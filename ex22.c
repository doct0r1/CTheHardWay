//
// Created by Mu$t4f△ J4m4L on 6/29/17.
// This is the object file .o

#include "ex22.h"
#include "dbg.h"
// didn't include stdio.h or others as they linked to dbg.h



int get_age()
{
	return state->the_age;
}

void set_age(struct State *state,int age)
{
	state->the_age = age;
}

double update_ratio(double new_ratio)
{
	static double ratio = 1.0;

	double old_ratio = ratio;
	ratio = new_ratio;

	return old_ratio;
}

void print_size()
{
	log_info("I think size is: %d", THE_SIZE);
}