// the unit test for the code

#include "../ex30/minunit.h"
#include "ringbuffer.h"

static RingBuffer *buffer = NULL;
char data[100] = { '\0' };

char *test_create()
{
    buffer = RingBuffer_create(100);
    mu_assert(buffer != NULL, "Failed to make bufferRing!");

    return NULL;
}

char *test_destroy()
{
    RingBuffer_destroy(buffer);

    return NULL;
}

char *test_read_write()
{
    mu_assert(RingBuffer_empty(buffer), "Sould be empty!");
    mu_assert(!RingBuffer_full(buffer), "Sould NOT be full.");
    debug("data is: %d, space is: %d", RingBuffer_available_data(buffer), RingBuffer_available_space(buffer));
    mu_assert(RingBuffer_available_data(buffer) == 0, "Should have 0 data.");
    mu_assert(RingBuffer_available_space(buffer) == 100, "Should have 100 space.");

    int rc = RingBuffer_write(buffer, "hello", sizeof("hello"));
    mu_assert(rc == sizeof("hello"), "Failed to write hello.");
    mu_assert(RingBuffer_available_data(buffer) == 6, "Sould have 6 data.");
    mu_assert(RingBuffer_available_space(buffer) == 100 - 6, "Should have 100 space.");

    rc = RingBuffer_write(buffer, "Mustafa", sizeof("Mustafa"));
    mu_assert(rc == sizeof("Mustafa"), "What the fuck happen on the earth damn it's maybe the whole universe!\nHOW it can't print this beautiful Mustafa!!!\nFuckin sorry Sir!");

    mu_assert(!RingBuffer_empty(buffer), "Should NOT be empty!");
    mu_assert(!RingBuffer_full(buffer), "Should NOT be full!");

    rc = RingBuffer_read(buffer, data, sizeof("hello"));
    mu_assert(rc == sizeof("hello"), "Failed to read the hello out.");

    mu_assert(!RingBuffer_empty(buffer), "Should NOT be empty!");
    mu_assert(!RingBuffer_full(buffer), "Should NOT be full!");

    rc = RingBuffer_read(buffer, data, sizeof("Mustafa"));
    mu_assert(rc == sizeof("Mustafa"), "Failedt to read Mustafa out!");
    mu_assert(RingBuffer_empty(buffer), "Sould be empty.");

    bstring data = bfromcstr("Hello Again");
    rc = RingBuffer_puts(buffer, data);
    bdestroy(data);
    mu_assert(rc != -1, "Failed to write a bstring.");
    mu_assert(!RingBuffer_empty(buffer), "Sould NOT be empty.");

    data = RingBuffer_gets(buffer, 2);
    mu_assert(data, "Didn't get any bstring for gets.");
    mu_assert(bisstemeqblk(data, "He", 2), "Wrong gets result!");
    bdestroy(data);

    data = RingBuffer_get_all(buffer);
    mu_assert(data, "Didn't get any bstring from gets.");
    mu_assert(bisstemeqblk(data, "llo Again", 9), "Wrong get_All result.");

    return NULL;
}

char *all_tests()
{
    mu_suite_start();

    mu_run_test(test_create);
    mu_run_test(test_read_write);
    mu_run_test(test_destroy);

    return NULL;
}

RUN_TESTS(all_tests());
