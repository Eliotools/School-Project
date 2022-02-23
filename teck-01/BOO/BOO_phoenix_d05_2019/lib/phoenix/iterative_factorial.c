/*
** EPITECH PROJECT, 2019
** phoenix
** File description:
** Moi
*/

int iterative_factorial(int nb )
{
    int calc = 1;
    if (nb >= 13 || nb < 0)
        return (0);
    for (; nb > 1; nb--)
        calc = calc*(nb);
    return (calc);
}