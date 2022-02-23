/*
** EPITECH PROJECT, 2021
** B-MAT-400-LIL-4-1-206neutrinos-eliot.martin [WSL: Ubuntu]
** File description:
** rms
*/
#include "my.h"

double get_first_rms(double deviation, double arithmetic_mean)
{
    return (sqrt((pow(deviation, 2)) + (pow(arithmetic_mean, 2))));
}

double get_new_rms(double rms, int n, int i)
{
    double sum = pow(rms,2) * n;
    sum += pow(i,2);
    return(roundl(pow(sum / (n+1),0.5) * 100) / 100);
}