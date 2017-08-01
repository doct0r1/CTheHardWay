//
// Created by Mu$t4f△ J4m4L on 7/15/17.
//

#define MIN 1
#define MAX 1000
#define DIST 128

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int len = 0;
	int i = 0;
	int j = 0;

	scanf("%d", &len);
	if (len < MIN || len > MAX) return 1;
	//char *s = (char *)malloc(sizeof(char) * 512000);
	char *s = (char *) malloc(sizeof(char) * (len + 1));
	scanf("%s", s);

	// get distinct char in string by creating an array to save them
	int distChar[DIST] = {0};

	for (i = 0; i < len; i++) {
		if (distChar[s[i]] <= 0) {
			distChar[s[i]]++;   // if the char = 0 move to next char
		}
	}

	// do comparison
	int position = 1;
	int maxChar = 0;
	int charCount = 0;

	for (i = 0; i < DIST; i++) {
		if (distChar[i] == 0) {
			continue;
		}

		for (j = 0; j < DIST; j++) {
			if (i == j) {
				continue;
			} else if (distChar[j] == 0) {
				continue;
			}

			int k = 0;
			for (k = 0; k < len; k++) {
				if (position == 1) {
					if (s[k] == i) {
						position--;
						charCount++;
					} else if (s[k] == j) {
						charCount = 0;
						break;
					} else {
						continue;
					}
				} else if (position == 0) {
					if (s[k] == i) {
						position++;
						charCount++;
					} else if (s[k] == j) {
						charCount = 0;
					} else {
						continue;
					}
				}
			}

			if (charCount > 0 && charCount > maxChar) {
				maxChar = charCount;
			}

			charCount = 0;
			position = 1;
		}
	}

	printf("%d\n", maxChar);

	return 0;
}