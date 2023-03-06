#include <stdio.h>
#include "clinear.h"
#include <GL/glut.h>
#include <math.h>
#define TIME_INTERVAL 0.1
double posX = 0.0;
double posY = 0.0;
double velX = 0.0;
double velY = 0.0;
double accX = 0.0;
double accY = -9.8;

double radius = 0.1;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslated(posX, posY, 0.0);
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        double theta = i * 3.141592653589793 / 180.0;
        double x = radius * cos(theta);
        double y = radius * sin(theta);
        glVertex2d(x, y);
    }
    glEnd();

    glutSwapBuffers();
}

void update()
{
    velX += accX * TIME_INTERVAL;
    velY += accY * TIME_INTERVAL;
    posX += velX * TIME_INTERVAL;
    posY += velY * TIME_INTERVAL;

    if (posY - radius < -1.0)
    {
        posY = -1.0 + radius;
        velY = -velY * 0.9;
    }

    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Falling Particle");
    glutDisplayFunc(display);
    glutIdleFunc(update);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glutMainLoop();
    return 0;
}
typedef struct Particle
{
    Vector2 position;
    Vector2 velocity;
} Particle;

int main2(int argc, char **argv)
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
