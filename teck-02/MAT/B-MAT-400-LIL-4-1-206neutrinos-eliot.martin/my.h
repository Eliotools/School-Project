/*
** EPITECH PROJECT, 2021
** B-MAT-400-LIL-4-1-206neutrinos-eliot.martin [WSL: Ubuntu]
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(int ac, char **av);
int check_arg(int n, int a, int h, int sd);
int next(int n, double a, double h, double sd);
int getval(void);
void hache(void);
void printer(int n, double a, double sd, double rms);
void printer_2(double h);
double get_artimetic(double a, double i, double n);
double get_harmonic(double a, double i, double n);
double get_root(double a, double i, double n);
double get_first_rms(double deviation, double arithmetic_mean);
double get_new_rms(double rms, int n, int i);

#endif /* !MY_H_ */
