/*
** EPITECH PROJECT, 2019
** Phoenix
** File description:
** Moi
*/

#include "include/phoenix.h"
#include <stdlib.h>
#include <stdio.h>

int find_error(char **argv, int argc)
{
    if (argc != 2 || to_number(argv[1]) == 0)
        return(1);
    if (to_number(argv[1]) == 1) {
        show_string("   *\n*** ***\n *   *\n*** ***\n   *\n");
        return(1);
    }
    if (to_number(argv[1]) == 2) {
        show_string("     *\n    * *\n***** *****\n *       *\n *       *\n");
        show_string("***** *****\n    * *\n     *\n");
        return(1);
    }
    return(0);
}

int make_my_double(int star)
{
    if (star <= 2)
        return ((star * 3) + 2);
    else
        return ((star * 4) + 1);
}

void fifth (int star, int const size, char *str)
{
    for (int k = 0; k != size; str[k] = ' ', k++);
    static int compte = 0;
    static int i = -1;
    static int j = -1;
    if (i == -1) {
        i = 3 + (star - 1) * 2 - 1;
        j = i+(star*2)-3 + 1;
    }
    str[i] = '*';
    str[j] = '*';
    i++, j--, compte++;
    show_string(str);
    my_putchar('\n');
    if (compte >= star)
        return (0);
    else
        fifth(star, size, str);
}
void fourth(int star, int const size, char *str)
{
    int j = 0;
    int i = ((size)-((star * 2) - 3))/2;
    for (; j < i; str[j] = '*',j++);
    for (; j < i+(star*2)-3; str[j] = ' ',j++);
    for (; j < size; str[j] = '*',j++);
    show_string(str);
    my_putchar('\n');
    fifth(star,size,str);
}

void third(int star, int const size, char *str)
{
    for (int k = 0; k != size; str[k] = ' ', k++);
    static int compte = -2;
    static int k = 1;
    static int i = -1;
    if (i == -1) {
        i = size-2;
    }
    str[i] = '*';
    str[k] = '*';
    if (compte < star) {
        k++,i--, compte++;
    }
    else 
        i++, k--; compte++; 
    show_string(str);
    my_putchar('\n');
    if (compte > 2*star-1)
        fourth(star, size, str);
    else
        third(star, size, str);
}
void second(int star, int const size, char *str)
{
    int j = 0;
    int i = ((size)-((star * 2) - 3))/2;
    for (; j < i; str[j] = '*',j++);
    for (; j < i+(star*2)-3; str[j] = ' ',j++);
    for (; j < size; str[j] = '*',j++);
    show_string(str);
    my_putchar('\n');
    third(star,size,str);
}

void first(int star, int const size, char *str)
{
    for (int k = 0; k != size; str[k] = ' ', k++);
    static int compte = 0;
    static int i = -1;
    static int j = -1;
    if (i == -1) {
        i = size/2;
        j = size/2;
    }
    str[i] = '*';
    str[j] = '*';
    i++, j--, compte++;
    show_string(str);
    my_putchar('\n');
    if (compte >= star)
        second(star, size, str);
    else
        first(star, size, str);
}

void next(int star, int const size)
{
    char str[size-1];
    first(star, size, str);
}

int main(int argc, char **argv)
{
    if (find_error(argv, argc) == 1)
        return (0);
    int star = to_number(argv[1]);
    int const size = ((star * 2) - 3) + 2 * (3 + (star - 1)* 2);
    //int high = make_my_double(star) + 1;
    next(star, size);
    return (0);
}