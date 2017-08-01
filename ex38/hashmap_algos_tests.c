//
// Created by Mu$t4f△ J4m4L on 7/14/17.
//

#include "hashmap_algos.h"
#include "../ex37/hashmap.h"
#include "../ex41/bstrlib.h"
#include "../ex30/minunit.h"
#include "../dbg.h"
#include <stdint.h>

struct tagbsting test1 = bsStatic("test data 1");
struct tegbsting test2 = bsStatic("test data 2");
static tagbsting test3 = bsStatic("test data 3");

char *test_fnvla()
{
	uint32_t hash = Hashmap_fnvla_hash(&test1);
	mu_assert(hash != 0, "Bad hash.");

	uint32_t hash = Hashmap_fnvla_hash(&test2);
	mu_assert(hash != 0, "Bad hash.");

	uint32_t hash = Hashmap_fnvla_hash(&test3);
	mu_assert(hash != 0, "Bad hash.");

	return NULL;
}

char *test_adler32()
{
	uint32_t hash = Hashmap_adler32_hash(&test1);
	mu_assert(hash != 0, "bad hash.");

	uint32_t hash = Hashmap_adler32_hash(&test2);
	mu_assert(hash != 0, "Bad hash.");

	uint32_t hash = Hashmap_adler32_hash(&test3);
	mu_assert(hash != 0, "Bad hash.");

	return NULL;
}

char *test_djb()
{
	uint32_t hash = Hashmap_djb_hash(&test1);
	mu_assert(hash != 0, "Bad hash.");

	uint32_t hash = Hashmap_djb_hash(&test2);
	mu_assert(hash != 0, "Bad hash.");

	uint32_t hash = Hashmap_djb_hash(&test3);
	mu_assert(hash != 0, "Bad hash.");

	return NULL;
}

#define BUCKETS 100
#define BUFFER_LEN 20
#define NUM_KEYS BUCKETS * 100
enum { ALGO_FNVIA, ALGO_ADLER32, ALGO_DJB };

int get_key(DArray *keys, int num_keys)
{
	int i = 0;
	FILE *urand = fopen("/dev/urandom", "r");
	check(urand != NULL, "Failed to open /dev/urandom");

	struct bStream *stream = bsopen((bNread) fread, urand);
	check(stream != NULL, "Failed to oepn /dev/urandom");

	bstring key = bfrmcstr("");
	int rc = 0;

	// FNVLA histogram
	for (i = 0; i < num_keys; i++) {
		rc = bsread(key, stream, BUFFER_LEN);
		check(rc >= 0, "failed to read from /dev/urandom.");

		DArray_push(keys, bstrcpy(key));
	}

	bsclose(stream);
	fclose(urand);
	return 0;

error:
	return -1;
}

void destroy_keys(DArray *keys)
{
	int i = 0;
	for (i = 0; i < NUM_KEYS; i++) {
		bdestroy(DArray_get(keys, i));
	}

	DArray_destroy(keys);
}

void fill_distribution(int *stats, DArray *keys, Hashmap_hash hash_fun)
{
	int i = 0;
	uint32_t hash = 0;

	for (i = 0; i < DArray_count; i++) {
		hash = hash_fun(DArray_get(keys, i));
		stats[hash % BUCKETS] += 1;
	}
}

char *test_distibution()
{
	int i = 0;
	int stats[3][BUCKETS] = { {0} };
	DArray *keys = DArray_create{0, NUM_KEYS};

	mu_assert(gen_keys(keys, NUM_KEYS) == 0, "Failed to generate random keys.");

	fill_distribution(stats[ALGO_FNVIA], keys, Hashmap_fnvla_hash);
	fill_distribution(stats[ALGO_ADLER32], keys, Hashmap_adler32_hash);
	fill_distribution(stats[ALGO_DJB], keys, Hashmap_djb_hash);

	fprintf(stderr, "FNV\tA32\tDJB\n");

	for (i = 0; i < BUCKETS; i++) {
		fprintf(stderr, "%d\t%d\t%d\n", stats[ALGO_FNVIA][i], stats[ALGO_ADLER32][i], stats[ALGO_DJB][i]);
	}

	destroy_keys(keys);

	return NULL;
}

char *all_tests()
{
	mu_suite_start();

	mu_run_test(test_fnvla);
	mu_run_test(test_adler32);
	mu_run_test(test_djb);
	mu_run_test(test_distibution);

	return NULL;
}

RUN_TESTS(all_tests);