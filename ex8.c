#include <stdio.h>

int main(int argc, char *argv[]) {
	int i = 0;

	if (argc == 1)
		printf("You only have 1 argumant.\n");
	else if (argc > 1 && argc < 4) {
		printf("Here's Your argumant: \n");

		for (i = 1; i < argc; i++)
			printf("%s ", argv[i]);
		putchar('\n');
	} else 
		printf("You have too many argumants. You Suck :P .\n");


	return 0;
}