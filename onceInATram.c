//
// once In A Tram
// Created by Must4fA J4m4L on 7/17/17.
//

#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdlib.h>

int onceInATram(int n) {
	int y = 0;
	int x = 0;
	int t1 = n;
	int t2 = y;
	int reminder1 = 0;
	int reminder2 = 0;
	int sum1 = 0;
	int sum2 = 0;


	do {
		n = n + 1;     // to add 1 to the number
		y = n % 1000;  // This is the first 3 numbers
		x = n / 1000;  // This is the last 3 numbers

		//printf("%d is now split into %d and %d\n", n, x, y);

		t1 = x;
		t2 = y;
		sum1 = 0;
		sum2 = 0;

		for(int l=0; l<3; ++l) {
			reminder1 = t1 % 10;
			sum1 = sum1 + reminder1;
			t1 = t1 / 10;

			reminder2 = t2 % 10;
			sum2 = sum2 + reminder2;
			t2 = t2 / 10;
		}
	} while (sum1 != sum2);


	return 1000*x+y;
}

int main() {
	int x;
	scanf("%d", &x);
	int result = onceInATram(x);
	//printf("The Final Answer is %d\n", result);
	printf("%d\n",result);
	return 0;
}
