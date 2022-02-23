/*
** EPITECH PROJECT, 2019
**mu_swap.c
**File description
**swap
*/

void my_swap (int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
    return (0);
}
