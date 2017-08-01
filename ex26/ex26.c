//
// Created by Mu$t4f△ J4m4L on 7/1/17.
// Final version.

#include "../dbg.h"
#include <stdlib.h>
#include <glob.h>
#include <assert.h>

const size_t MAX_LINE = 1024;


int list_files(glob_t *pglob)
{
	char *line = calloc(MAX_LINE, 1);
	FILE *file = fopen(".ex26", "r");
	int glob_flags = GLOB_TILDE;
	int i = 0;
	int rc = -1;

	check(pglob != NULL, "Invalid glob_t given.");
	check_mem(line);
	check(file, "Failed to open .ex26. make that first.");

	while (fgets(line, MAX_LINE - 1, file) != NULL) {
		size_t line_length = strnlen(line, MAX_LINE - 1);   // updated by lecture 27 // using strnlen instead of strlen
		assert(line_length < MAX_LINE && "Got a line_length too long.");    // updated by lec 27
		//line[strlen(line) - 1] = '\0';  // drop the \n ending
		line[line_length] = '\0';   // updated at lecture 27 by defensive programming
		debug("Globbing %s", line);

		rc = glob(line, glob_flags, NULL, pglob);
		check(rc == 0 || rc == GLOB_NOMATCH, "Failed to glob.");

		// dump work around to a stupid design in glob
		if (glob_flags == GLOB_TILDE) glob_flags |= GLOB_APPEND;
	}

	//rc = glob("*.c", glob_flags | GLOB_ABEND, NULL, pglob);
	//check(rc == 0, "Failed to glob.")

	for (i = 0; i < pglob->gl_pathc; i++) {
		debug("Matched file: %s", pglob->gl_pathv[i]);
	}

	rc = 0; // all good

error: // fallthrough
	if(line) free(line);
	return rc;
}

int found_it(int use_or, int found_count, int search_len)
{
	debug("use_or: %d, found_count: %d, search_len: %d", use_or, found_count, search_len);

	if (use_or && found_count > 0) {
		return 1;
	} else if (!use_or && found_count == search_len) {
		return 1;
	} else {
		return 0;
	}
}

int scan_file(const char *filename, int use_or, int search_len, char *search_for[])
{
	char *line = calloc(MAX_LINE, 1);
	FILE *file = fopen(filename, "r");
	int found_count = 0;
	int i = 0;

	check_mem(line);
	check(file, "Failed to open file: %s", filename);

	// read each line of the file and search that line for the contents
	while(fgets(line, MAX_LINE-1, file) != NULL) {
		for(i = 0; i < search_len; i++) {
			if(strcasestr(line, search_for[i]) != NULL) {
				debug("file: %s, line: %s, search: %s", filename, line, search_for[i]);
				found_count++;
			}
		}

		if(found_it(use_or, found_count, search_len)) {
			printf("%s\n", filename);
			break;
		} else {
			found_count = 0;
		}
	}


	free(line);
	fclose(file);
	return 0;

	error:
	if(line) free(line);
	if(file) fclose(file);

	return -1;
}

/* // From the 2ed version.

int scan_file(const char *filename, int search_len, char *search_for[])
{
	char *line = calloc(MAX_LINE, 1);
	FILE *file = fopen(filename, "r");
	char *found = NULL;
	int i = 0;

	check_mem(line);
	check(file, "Failed to open file: %s", filename);

	// read each line of the file and search that line for the contents
	while (fgets(line, MAX_LINE - 1, file) != NULL && found == NULL) {
		for (i = 0; i < search_len && found == NULL; i++) {
			found = strcasestr(line, search_for[i]);
			if (found) {
				printf("%s\n", filename);
			}
		}
	}

	free(line);
	fclose(file);
	return 0;

error:
	if(line) free(line);
	if(file) fclose(file);

	return -1;
}
*/

int parse_args(int *use_or, int *argc, char **argv[])
{
	(*argc)--;
	(*argv)++;

	if (strcmp((*argv)[0], "-o") == 0) {
		*use_or = 1;
		(*argc)--;  // skip the -o
		(*argv)++;
		check(*argc > 1, "You need words after -o.");
	} else {
		*use_or = 0;    // there was a bug here by using it w/out the pointer *, as i just set this value to 0 in main (so it'll useless w/ out the pointer)
	}

	check(*use_or == 1 || *use_or == 0, "Invalid default use_or."); // updated by lecture 27

	return 0;
error:
	return -1;
}

int main(int argc, char *argv[])
{
	int i = 0;
	int use_or = 0;
	glob_t files_found;

	check(argc > 1, "USAGE: ./ex26 [-o] words");

	check(parse_args(&use_or, &argc, &argv) == 0, "USAGE: ./ex26 [-o] words");

	check(list_files(&files_found) == 0, "Failed to list files.");

	for (i = 0; i < files_found.gl_pathc; i++) {
		scan_file(files_found.gl_pathv[i], use_or, argc, argv);
	}

	globfree(&files_found);
	return 0;

error:
	return 1;
}
