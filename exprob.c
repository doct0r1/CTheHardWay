//
// Created by Mu$t4f△ J4m4L on 7/4/17.
//

#include <stdio.h>


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int numberOfChapters = 0, problemsPerPage = 0, pagesPerChap = 0, pages = 1, special = 0, i = 0, j = 0;
    scanf("%d %d", &numberOfChapters, &problemsPerPage);

    for (i = 0; i < numberOfChapters; i++) {
        scanf("%d", &pagesPerChap);
        for (j = 1; j <= pagesPerChap; j++) {
            if (j == pages)
                special++;
            if (j == pagesPerChap || !(j % problemsPerPage))
                pages++;
        }
    }
    printf("%d", special);

    return 0;
}