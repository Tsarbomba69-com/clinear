#include <stdio.h>
#include "clinear.h"

int main(void)
{
    double data1[] = {1.0, 2.0};
    double data2[] = {4.0, 5.0};
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
    printf("Linked List: a.b = %f\n", dot_vec(&a, &b));
    Vector2 p1 = new_vector2(1, 2.0);
    Vector2 p2 = new_vector2(4.0, 5.0);
    printf("a = ");
    print_vector2(&p1);
    printf("b = ");
    print_vector2(&p2);
    Vector2 p3 = add_vector2(&p1, &p2);
    printf("a + b = ");
    print_vector2(&p3);
    p3 = sub_vector2(&p1, &p2);
    printf("a - b = ");
    print_vector2(&p3);
    printf("2D: a.b = %f\n", dot_vector2(&p1, &p2));
    printf("|a| = %f\n", magnitude2(&p1));
    printf("Φ = %f\n", angle2(&p1, &p2));
    printf("√|A - B| = %f\n", distance2(&p1, &p2));
    Vector2 p4 = new_vector2(195.567, 1.0);
    print_vector2(&p4);
    printf("|p4| = %f\n", magnitude2(&p4));
    p4 = normalize2(&p4);
    print_vector2(&p4);
    printf("p4/|p4| = %f\n", magnitude2(&p4));
    return EXIT_SUCCESS;
}