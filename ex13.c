#include <stdio.h>

int main(int argc, char *argv[]) {
	int i = 0;

	// go through each string in argv
	// Skipping over argv[0]
	for (i = 1; i < argc; i++) 
		printf("Arg %d:%s\n", i, argv[i]);

	// Let's make our own array of strings 
	char *string[] = {
		"California", "Orange",
		"Washaton", "Texas"
	};

	int num_states = 4;

	for (i = 0; i < num_states; i++)
		printf("States %d: %s\n", i, string[i]);

	return 0;
}