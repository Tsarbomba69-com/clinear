#include "clinear.h"

Vector2 new_vector2(double x, double y)
{
    Vector2 vector = {.x = x, .y = y};
    return vector;
}

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

Vec sub_vec(Vec *a, Vec *b)
{
    assert(a->len == b->len);
    Vec c = new_vec(DOUBLE);
    for (size_t i = 0; i < a->len; i++)
    {
        enqueue(&c, (T)(get(a, i).d - get(b, i).d));
    }
    return c;
}

Vector2 add_vector2(Vector2 *a, Vector2 *b)
{
    assert(a != NULL && b != NULL);
    Vector2 c = new_vector2(0, 0);
    c.x = a->x + b->x;
    c.y = a->y + b->y;
    return c;
}

Vector2 sub_vector2(Vector2 *a, Vector2 *b)
{
    assert(a != NULL && b != NULL);
    Vector2 c = new_vector2(0, 0);
    c.x = a->x - b->x;
    c.y = a->y - b->y;
    return c;
}

double dot_vector2(Vector2 *a, Vector2 *b)
{
    assert(a != NULL && b != NULL);
    return a->x * b->x + a->y * b->y;
}

double dot_vec(Vec *a, Vec *b)
{
    assert(a->len == b->len);
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

double *sub(double *a, double *b, size_t len)
{
    double *c = (double *)malloc(len);

    for (size_t i = 0; i < len; i++)
    {
        c[i] = a[i] - b[i];
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

double magnitude2(Vector2 *a)
{
    return sqrt(a->x * a->x + a->y * a->y);
}

double distance2(Vector2 *a, Vector2 *b)
{
    Vector2 c = sub_vector2(a, b);
    return magnitude2(&c);
}

double angle2(Vector2 *a, Vector2 *b)
{
    return (180 / PI) * acos(dot_vector2(a, b) / (magnitude2(a) * magnitude2(b)));
}

Vector2 normalize2(Vector2 *a)
{
    double m = magnitude2(a);
    return new_vector2(a->x / m, a->y / m);
}

void print_vector2(Vector2 *vector)
{
    assert(vector != NULL);
    printf("(x = %f, y = %f)\n", vector->x, vector->y);
}