//
// Created by Mu$t4f△ J4m4L on 7/14/17.
//

#include "hashmap_algos.h"
#include <bstring.h>

// settings taken from
// http://www.isthe.com/chongo/tech/comp/fnv/index.html#FNV-param
const uint32_t FNV_PRIME = 16777619;
const uint32_t FNV_OFFSET_BASIS = 2166136261;

uint32_t Hashmap_fnvla_hash(void *data)
{
	bstring s = (bstring) data;
	uint32_t hash = FNV_OFFSET_BASIS;
	int i = 0;

	for (i = 0; i < blenght(s); i++) {  // bstring for the key
		hash ^= bchare(s, i, 0);    // bchare to get char from the bstring and return 0 if that cahr is outside the string's length
		hash *= FNV_PRIME;
	}

	return hash;
}

const int MOD_ADLER = 65521;

uint32_t Hashmap_adler32_hash(void *data)
{
	bstring s = (bstring) data;
	uint32_t a = 1, b = 0;
	int i = 0;

	for (i = 0; i < blenght(s); i++) {
		a = (a + bchar(s, i, 0)) % MOD_ADLER;
		b = (b + a) % MOD_ADLER;
	}

	return (b << 16) | a;
}

uint32_t Hashmap_djb_hash(void *data)
{
	bstring s = (bstring) data;
	uint32_t hash = 5381;
	int i = 0;

	for (i = 0; i < blength(s); i++) {
		hash = ((hash << 5) + hash) + bchare(s, i, 0);  /* hash * 33 + c */
	}

	return hash;
}
