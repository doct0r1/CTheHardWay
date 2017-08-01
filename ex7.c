#include <stdio.h>

int main(int argc, char *argv[]) {
	int distance = 100;
	float power = 2.435f;
	double super_power = 56789.4532;
	char initial = 'A';
	char first_name[] = "Mustafa";
	char last_name[] = "Jamal";

	printf("You are %d miles away.\n", distance);
	printf("You Have %f levels of power.\n", power);
	printf("You Have %f awesome super powers.\n", super_power);
	printf("I have an initial %c.\n", initial);
	printf("I Have a first name %s\n", first_name);
	printf("My whole name is %s %c. %s.\n",
			first_name, 
			initial,
			last_name);

	int bugs = 100;
	double bugs_rate = 1.2;

	printf("You have %d bugs at the imaginary rate of %f.\n",
			bugs, bugs_rate);

	long unicerse_of_defects = 1L * 1024L * 1024L * 1024L;
	printf("The entire Universe has %ld bugs.\n", unicerse_of_defects);

	double expected_bugs = bugs * bugs_rate;
	printf("You are expected to have %f bugs.\n", expected_bugs);

	double part_of_unverse = expected_bugs / unicerse_of_defects;
	printf("That is only a %e protion of the unverse.\n", part_of_unverse);

	// This make no sense, just a demo of something weird
	char nul_byte = '\0';
	int care_parcentage = bugs * nul_byte;
	printf("Which means you should care %d%%.\n", care_parcentage);

	return 0;
}	