/*
** EPITECH PROJECT, 2021
** B-MAT-400-LIL-4-1-206neutrinos-eliot.martin [WSL: Ubuntu]
** File description:
** main
*/
#include "my.h"

void hache(void)
{
    printf("USAGE\n\
    ./206neutrinos n a h sd\n\
DESCRIPTION\n\
\tn\tnumber of values\n\
\ta\tarithmetic mean\n\
\th\tharmonic mean\n\
\tsd\tstandard deviation\n");
}

int getval(void)
{
    char *str = malloc(100);
    int i = -1;
    int my = 0;

    printf("Enter next value: ");
    fgets(str, sizeof(str), stdin);
    i = atoi(str);
    my = strcmp(str, "END\n");
    free(str);

    if (my == 0 || i == 0)
        return (-1);
    return (i);
}

int next(int n, double a, double h, double sd)
{
    int val = 0;
    double rms = get_first_rms(sd, a);
    double sum = (pow(a, 2) + pow(sd, 2)) * (n - 1);
    double product = 0;
    while (1) {
        val = getval();
        if (val == -1)
            return (0);
        if (val == -2)
            return (84);
        product = a * n;
        sum = (pow(sd, 2) + pow(a, 2)) * n;
        n++;
        a = get_artimetic(a, (double)val, (double)n);
        sd = sqrt((((sum) + pow(val, 2)) / n) - pow(((product + val) / n), 2));
        rms = get_new_rms(rms, n, val);
        h = get_harmonic(h, (double)val, (double)n);
        printer(n, a, sd, rms);
        printer_2(h);
    }
    return (0);
}

int check_arg(int n, int a, int h, int sd)
{
    if (n <= 0 || a == 0 || h == 0 || sd == 0 )
        return (84);
    return (next(n, (double) a, (double)h, (double)sd));
}

int main(int ac, char **av)
{
    if (ac == 2) {
        if (!strcmp(av[1], "-h"))
            hache();
    }
    else if (ac == 5)
        return (check_arg(atoi(av[1]), atoi(av[2]), atoi(av[3]), atoi(av[4])));
    else
        return (84);
}