#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

// The structure will be used in the program
struct Person {
	char *name;
	int age;
	int height;
	int weight;
};

// creates chunk from memory for the structure and get the input from other function and store it in it.
struct Person *Person_create(char *name, int age, int height, int weight)
{
	// creates struct person who to return it.
	struct Person *who = malloc(sizeof(struct Person));
	assert(who != NULL);	// make sure it gets the memory it need from the system.

	who->name = strdup(name);	/* use strdup function to duplicate the string for the name, just to make sure that this structure actually owns it.
								   The strdup actually us like malloc, and it also copies the original string into the memory it creates. */
	who->age = age;
	who->height = height;
	who->weight = weight;

	return who;
}

// free memory
void Person_destroy(struct Person *who)
{
	assert(who != NULL);	// make sure he have a valid peace of memory.

	free(who->name);
	free(who);
}

void Person_print(struct Person *who)
{
	printf("Name: %s\n", who->name);	// using the same x->y syntax to get the field from the structure to print it.
	printf("\tAge: %d\n", who->age);
	printf("\tHeight: %d\n", who->height);
	printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
	// make 2 people structure
	struct Person *Mustafa = Person_create("Mustafa Jamal", 21, 64, 140);

	struct Person *Hasan = Person_create("Hasan Jamal", 15, 72, 18);

	// print them out from the memory
	printf("Mustafa is at memory location %p: \n", Mustafa);
	Person_print(Mustafa);

	printf("Hasan is at memory location %p: \n", Hasan);
	Person_print(Hasan);

	// increment the age and ...
	Mustafa->age += 20;
	Mustafa->height += 2;
	Mustafa->weight -= 2;
	Person_print(Mustafa);

	Hasan->age += 20;
	Hasan->weight += 2;
	Person_print(Hasan);

	// destroy 'em.
	Person_destroy(Mustafa);
	Person_destroy(Hasan);

	return 0;
}