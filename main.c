#include <stdio.h>
#include "clinear.h"

int main(void)
{
    double data1[] = {1.0, 2.0, 3.0};
    double data2[] = {4.0, 5.0, 6.0};
    Vec a = new_vec(DOUBLE);
    Vec b = new_vec(DOUBLE);
    VEC(a, data1, sizeof(data1) / sizeof(double));
    VEC(b, data2, sizeof(data1) / sizeof(double));
    Vec c = add_vec(&a, &b);
    // TESTS ----------------------------------------------------
    for (size_t i = 0; i < a.len; i++) // Linked List: C = A + B
    {
        assert(data1[i] + data2[i] == get(&c, i).d);
    }
    printf("C = ");
    print_vec(&c);

    size_t len = sizeof(data1) / sizeof(double);
    double *data3 = add(data1, data2, len);
    for (size_t i = 0; i < len; i++) // array: C = A + B
    {
        assert(data1[i] + data2[i] == data3[i]);
    }

    assert(dot(data1, data2, len) == dot_vec(&a, &b));
    printf("dot: array = %f, vec = %f\n", dot(data1, data2, len), dot_vec(&a, &b));
    return EXIT_SUCCESS;
}