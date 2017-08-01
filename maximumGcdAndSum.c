#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int maximumGcdAndSum(int* A, int* B) {
	// Complete this function
	return (int) A;
}

int main() {
	int n;
	scanf("%i", &n);
	int *A = malloc(sizeof(int) * n);
	for (int A_i = 0; A_i < n; A_i++) {
		scanf("%i",&A[A_i]);
	}

	// sort first array
	int sort_i = 0;
	int sort_j = 0;
	int temp = 0;
	for (sort_i = 0; sort_i < n; sort_i++) {
		for (sort_j = sort_i + 1; sort_j < n; sort_j++) {
			if (A[sort_i] < A[sort_j])
			temp = A[sort_i];
			A[sort_i] = A[sort_j];
			A[sort_j] = temp;
		}
	}

	printf("%i\t", A[sort_i]);

	int *B = malloc(sizeof(int) * n);
	for (int B_i = 0; B_i < n; B_i++) {
		scanf("%i",&B[B_i]);
	}
	int res = maximumGcdAndSum(A, B);
	printf("%d\n", res);
	return 0;
}
