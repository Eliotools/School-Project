/*
** EPITECH PROJECT, 2024
** day06
** File description:
** Created by Leo Fabre
*/

void my_swap(int *a, int *b)
{
    int swap = *b;

    *b = *a;
    *a = swap;
}