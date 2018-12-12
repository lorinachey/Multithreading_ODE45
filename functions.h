// functions.h
#ifndef FUNCTIONS_H // include guard
#define FUNCTIONS_H

double ode45(double *x, double *y, double *y_1, double step_size);
double func(double x, double y);
int testFunc(int i);


#endif /* FUNCTIONS_H */
