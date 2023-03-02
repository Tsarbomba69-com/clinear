#include "clinear.h"

Vec add_vec(Vec *a, Vec *b)
{
    assert(a->len == b->len);
    Vec c = new_vec(DOUBLE);
    for (size_t i = 0; i < a->len; i++)
    {
        enqueue(&c, (T)(get(a, i).d + get(b, i).d));
    }
    return c;
}

double dot_vec(Vec *a, Vec *b)
{
    assert(a->len == b->len);
    Vec c = new_vec(DOUBLE);
    double r = 0;
    for (size_t i = 0; i < a->len; i++)
    {
        r += get(a, i).d * get(b, i).d;
    }
    return r;
}

double *add(double *a, double *b, size_t len)
{
    double *c = (double *)malloc(len);

    for (size_t i = 0; i < len; i++)
    {
        c[i] = a[i] + b[i];
    }
    return c;
}

double dot(double *a, double *b, size_t len)
{
    double r = 0;
    for (size_t i = 0; i < len; i++)
    {
        r += a[i] * b[i];
    }
    return r;
}