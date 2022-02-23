/*
** EPITECH PROJECT, 2021
** B-MAT-400-LIL-4-1-206neutrinos-eliot.martin [WSL: Ubuntu]
** File description:
** printer
*/

#include "my.h"

double get_root(double a, double i, double n)
{
    return (sqrt(pow(a, 2) + ( pow(i, 2) - pow(a, 2)) / n));
}

double get_artimetic(double a, double i, double n)
{
    return (ceill((a +( ( i - a ) / n)) * 100) / 100);
}

double get_harmonic(double h, double i, double n)
{
    return (n / ((1.0 / h * (n - 1.0)) + (1.0 / i)));
}

void printer(int n, double a, double sd, double rms)
{
    printf("\tNumber of values:\t%d\n", n);
    printf("\tStandard deviation:\t%.2lf\n", sd);
    printf("\tArithmetic mean:\t%.2lf\n", a);
    printf("\tRoot mean square:\t%.2lf\n", rms);
}

void printer_2(double h)
{
    printf("\tHarmonic mean:\t\t%.2lf\n\n", h);
}