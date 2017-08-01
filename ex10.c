#include <stdio.h>
/*
int main(int argc, char *argv[]) {
	int i = 0;

	// Go through each string in argv
	// why am I skipping argv[0]?
	for (i = 1; i < argc; i++) 
		printf("agc %d: %s\n", i, argv[i]);

	// let's make our own array of strings
	char *states[] = {
		"California", "Oegon",
		"Washington", "Texas"
	};

	int num_states = 4;

	for (i = 0; i < num_states; i++)
		printf("state %d: %s\n", i, states[i]);

	return 0;
}
*/

int main(int argc, char *argv[]) {
	if (argc != 2) {
		puts("Need an argumant");
		return 1;
	}

	int i = 0;
	for (i = 0; argv[1][i] != '\0'; i++) {
		char letter = argv[1][i];

		switch (letter) {
			case 'a':
			case 'A':
				printf("%d: 'A'\n", i);
				break;

			case 'e':
			case 'E':
				printf("%d: 'E'\n", i);
				break;

			case 'i':
			case 'I':
				printf("%d: 'I'\n", i);
				break;

			case 'o':
			case 'O':
				printf("%d: 'O'\n", i);
				break;

			case 'y':
			case 'Y':
				if (i > 2)
					// it's only statment
					printf("%d: 'Y'\n", i);

				break;
			
			default:
				printf("%d: %c is not a vowel\n", i, letter);
		}
	}

	return 0;
}