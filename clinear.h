
#pragma once
#ifndef _CLINEAR_H_
#define _CLINEAR_H_

#include "vec.h"
// Add 2 vectors together. (linked list)
Vec add_vec(Vec *a, Vec *b);
// Add 2 vectors together. (Array)
double *add(double *a, double *b, size_t len);
// Dot product of 2 vectors. (linked list)
double dot_vec(Vec *a, Vec *b);
// Dot product of 2 vectors. (Array)
double dot(double *a, double *b, size_t len);
#endif