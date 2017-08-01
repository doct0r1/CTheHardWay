#include <stdio.h>

int main(int argc, char *argv[]) {
	int numbers[4] = { 0 };
	char name[4] = { 'a' };

	// First, print them out raw
	printf("numbers: %d %d %d %d\n",
			numbers[0], numbers[1], numbers[2], numbers[3]);

	printf("name each: %c %c %c %c\n",
			name[0], name[1], name[2], name[3]);

	printf("name: %s\n", name);

	// Set up the numbers
	numbers[0] = 1;
	numbers[1] = 2;
	numbers[2] = 3;
	numbers[3] = 4;

	// Set up the name
	name[0] = 'z';
	name[1] = 'e';
	name[2] = 'd';
	name[3] = '\0';

	// then print them out initialized
	printf("numbers: %d %d %d %d\n",
			numbers[0], numbers[1], numbers[2], numbers[3]);

	printf("name each: %c %c %c %c\n", 
			name[0], name[1], name[2], name[3]);

	// Print the name like a sting
	printf("name: %s\n", name);

	// Anther way to use name
	char *anther = "Zed";

	printf("anther: %s\n", anther);

	printf("anther each: %c %c %c %c\n",
			anther[0], anther[1], anther[2], anther[3]);

	return 0;
}