//
// Created by Mu$t4f△ J4m4L on 7/14/17.
//

#ifndef string_algos_h
#define string_algos_h

#include <lcthw/bstring.h>
#include <lcthw/darray.h>

typedef struct StringScanner {
	bstring in;
	const unsigned char *haystack;
	ssize_t hlen;
	const unsigned char *needle;
	ssize_t skip_chars[UCHAR_MAX + 1];
} StringScanner;

int String_find(bsting in, bsting what);

stringScanner *StringScanner_create(bstring in);

int StringScanner_scan(StringScanner *scan, bstring tofind);

void StringScanner_destroy(StringScanner *scan);

#endif //STRING_ALGOS_H
