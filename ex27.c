//
// Created by Mu$t4f△ J4m4L on 7/3/17.
//

#include "dbg.h"
#include <assert.h>

/**
 * Naive copy that assumes all inputs are always valid
 * taken from K&R C and cleaned up a bit.
 */
void copy(char to[], char from[])
{
	int i = 0;

	// while loop will not end if from isn't '\0' terminated
	while ((to[i] = from[i]) != '\0') {
		++i;
	}
}

/**
 * A safer version that checks fro many common errors using the
 * length of each string to control the loops and termination.
 */
int saferCopy(int from_len, char *from, int to_len, char *to)
{
	assert(from != NULL && to != NULL && "from and to can't be NULL");
	int i = 0;
	int max = from_len > to_len - 1 ? to_len - 1 :from_len; // this line <3

	// to_len must have at least 1 byte
	if (from_len < 0 || to_len <= 0)
		return -1;

	for (i = 0; i < max; i++) {
		to[i] = from[i];
	}

	to[to_len - 1] = '\0';

	return i;
}

int main(int argc, char *argv[])
{
	// careful to understand why we can't get these sizes
	char from[] = "0123456789";
	int from_len = sizeof(from);
	
	// notice that it's 7 chars + \0
	char to[] = "0123456";
	int to_len = sizeof(to);
	
	debug("Copying '%s': %d to '%s': %d", from, from_len, to, to_len);
	
	int rc = saferCopy(from_len, from, to_len, to);
	check(rc > 0, "Failed to safercopy.");
	check(to[to_len - 1] == '\0', "String not terminated.");
	
	debug("Result is: '%s': %d", to, to_len);
	
	// now try to break it
	rc = saferCopy(from_len * -1, from, to_len, to);
	check(rc == -1, "saferCopy should fail #1");
	check(to[to_len - 1] == '\0', "String not terminated.")
	
	rc = saferCopy(from_len, from, 0, to);
	check(rc == -1, "saferCopy should fail #2");
	check(to[to_len - 1] == '\0', "Sting not terminated.")
	
	return 0;
	
error:
	return 1;
}