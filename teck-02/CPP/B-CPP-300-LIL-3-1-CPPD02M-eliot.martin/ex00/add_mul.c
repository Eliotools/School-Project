/*
** EPITECH PROJECT, 2020
** main
** File description:
** Moi
*/

void  add_mul_4param(int first , int  second , int *sum , int *product)
{
    *sum = first + second;
    *product = first * second;
}

void  add_mul_2param(int *first , int *second)
{
    int sum = *first + *second;
    int product = *first * *second;
    *first = sum;
    *second = product;
}