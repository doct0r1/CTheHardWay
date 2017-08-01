//
// Created by Mu$t4f△ J4m4L on 7/1/17.
// This program should be more robust against buffer overflows, but it doesn't handle the formatted input as well as scanf.
// use command: man va_start
// I've updated some lines of the code.
//

#include "dbg.h"
#include <stdarg.h>
#include <stdlib.h>

#define MAX_DATA 100

int read_string(char **out_string, int max_buffer)  // ** means this out_string gonna modify to content giving to it.
{
	// the value of *out_string is a character sting target, So, i set the max buffer and check it.
	*out_string = calloc(1, (size_t) (max_buffer + 1));
	check_mem(*out_string);

	// then do fgets on it and fill the string.
	char *result = fgets(*out_string, max_buffer, stdin);
	check(result != NULL, "Input error.");

	return 0;

error:
	if (*out_string) free(*out_string);
	*out_string = NULL;
	return -1;
}

int read_int(int *out_int)
{
	char *input = NULL;
	int rc = read_string(&input, MAX_DATA);
	check(rc == 0, "Failed to read number.");

	*out_int = atoi(input);

	free(input);
	return 0;

error:
	if (input) free(input);
	return -1;
}

/**
 * vararg function is called read_scan, and it does the same thing that scanf function to handle stings the way i Want.
 */
 int read_scan(const char *fmt, ...)    // Set the last parameter the keyword ... to indicate to C that this function will take any number of args after the fmt arg.
{
	// variable declaration
	int i = 0;
	int rc = 0;
	int *out_int = NULL;
	char *out_char = NULL;
	char **out_string = NULL;
	int max_buffer = 0;

	// set the va_list variable to initialize it with va_start. This configures the gear in stdarg.h that handles variable arguments.
	va_list argp;
	va_start(argp, fmt);

	// for loop to loop through the format string fmt and process the same kind of formats that scanf has.
	for (i = 0; fmt[i] != '\0'; i++) {
		if (fmt[i] == '%') {
			i++;
			switch (fmt[i]) {
				case '\0':
					sentinel("Invalid format, you ended with %%.");
					break;

				case 'd':
					out_int = va_arg(argp, int *);
					rc = read_int(out_int);
					check(rc == 0, "Failed to read int.");
					break;

				case 'c':
					out_char = va_arg(argp, char *);
					*out_char = (char) fgetc(stdin);
					break;

				case 's':
					max_buffer = va_arg(argp, int);
					out_string = va_arg(argp, char **);
					rc = read_string(out_string, max_buffer);
					check(rc == 0, "Failed to read string.");
					break;

				default:
					sentinel("Invalid format.");
			}
		} else {
			fgetc(stdin);
		}

		check(!feof(stdin) && !ferror(stdin), "Input error.");
	}

	va_end(argp);
	return 0;

error:
	va_end(argp);
	return -1;
}

int main(int argc, char *argv[])
{
	char *first_name = NULL;
	char initial = ' ';
	char *last_name = NULL;
	int age = 0;

	printf("What's your first name? ");
	int rc = read_scan("%s", MAX_DATA, &first_name);
	check(rc == 0, "Failed first name.");

	printf("What's your initial? ");
	rc = read_scan("%c\n", &initial);
	check(rc == 0, "Failed initial.");

	printf("What's your last name? ");
	rc = read_scan("%s", MAX_DATA, &last_name);
	check(rc == 0, "Failed last name.");

	printf("How old are you? ");
	//rc = read_scan("%d", &age);
	read_scan("%d", &age);  // as the value never used. (my update).
	puts("----- RESULTS -----");
	printf("First name: %s", first_name);
	printf("Initial: '%c'\n", initial);
	printf("Last name: %s", last_name);
	printf("Age: %d\n", age);

	free(first_name);
	free(last_name);
	return 0;
error:
	return -1;
}