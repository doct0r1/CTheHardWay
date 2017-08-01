//
// Created by Mu$t4f△ J4m4L on 7/5/17.
//

#include <stdio.h>

void fun(int **);

int main()
{
	int *j;
	fun(&j);
	printf("%d", *j);
	//putchar('\n');
}

void fun(int **k)
{
	int a = 10;
	*k = &a;
}

