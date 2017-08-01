#include <math.h>
#include "stats.h"
#include <stdlib.h>
#include "dbg.h"

// load the number from some kind of data bases.
Stats *Stats_recreate(double sum, double sumsq, unsigned long n, double min, double max)
{
    Stats *st = malloc(sizeof(Stats));
    check_mem(st);

    st->sum = sum;
    st->sumsq = sumsq;
    st->n = n;
    st->min = min;
    st->max = max;

    return st;

error:
    return NULL;
}

// same of Stats_recreate but with all Zero
Stats *Stats_create()
{
    return Stats_recreate(0.0, 0.0, 0L, 0.0, 0.0);
}

// using the sum and n, it gives the mean.
double Stats_mean(Stats *st)
{
    return st->sum / st->n;
}

// This implements the formala
double Stats_stddev(Stats *st)
{
    return sqrt((st->sumsq - (st->sum * st->sum / st->n)) / (st->n - 1));
}

// this does the work of maintaining the number in the Stats struct.
// it gives the first value, it seems that n is 0 and set min and max accordingly.
// Every call after that keeps increasing sum, sumsq, and n.
// it then figure out if this new sample is a new min or max.
void Stats_sample(Stats *st, double s)
{
    st->sum += s;
    st->sumsq += s * s;

    if (st->n == 0) {
        st->min = s;
        st->max = s;
    } else {
        if (st->min > s)
            st->min = s;
        if (st->max < s)
            st->max = s;
    }

    st->n += 1;
}

// this is a sample debug function that dumps the statistics so you can view them.
void Stats_dump(Stats *st)
{
    fprintf(stderr,
            "sum: %f, sumsq: %f, n: %ld, "
            "min: %f, max: %f, mean: %f, stddev: %f",
            st->sum, st->sumsq, st->n, st->min, st->max, Stats_mean(st), Stats_stddev(st));
}
