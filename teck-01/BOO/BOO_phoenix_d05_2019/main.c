/*
** EPITECH PROJECT, 2019
** main
** File description:
** Moi
*/
#include "include/phoenix.h"
#include <stdlib.h>
#include <stdio.h>

char **split_string(char const *str);
int show_string_array (char *const *array);
char **split_string(char const *str);
int make_my_double(int star);
char **make_my_array(char **str, int star, int hite);
char **fill_my_array(char **str, int star, int size);
int find_error(char **argv, int argc);


int main(int argc, char **argv)
{
    if (find_error(argv, argc) == 1)
        return (0);
    int star = to_number(argv[1]);
    int size = ((star * 2) - 3) + 2 * (3 + (star - 1)* 2);
    int hite = make_my_double(star) + 1;
    char **str = malloc(sizeof(char *) * hite);
    str = make_my_array(str, star, hite);
    str = fill_my_array(str, star, size);
    show_string_array(str);
    return (0);
}

int make_my_double(int star)
{
    if (star <= 2)
        return ((star * 3) + 2);
    else
        return ((star * 4) + 1);
}

char **make_my_array(char **str, int star, int hite)
{
    int j = 0;
    int k = 0;
    int size = ((star * 2) - 3) + 2 * (3 + (star - 1)* 2);
    while (j != hite-1)
    {
        k = 0;
        str[j] = malloc(sizeof(char) * size);
        while (k != size)
        {
            str[j][k] = ' ';
            k++;
        }
        j++;
    }
    str[j] = NULL;
    return (str);
}

char **fill_my_array(char **str, int star, int size)
{
    int k = 0;
    int clone  = 0;
    int i = size/2;
    int j = size/2;
    while(str[k] != NULL) {
        while (k < star) {    
            str[k][i] = '*';
            str[k][j] = '*';
            i++;
            j--;
            k++;
        }
        i--;
        j++;
        clone = j;
        while (j > 0)
        {
            str[k][i] = '*';
            str[k][j] = '*';
            i++;
            j--;

        }
        while (j != star)
        {
            str[k][i] = '*';
            str[k][j] = '*';
            i--;
            j++;
            k++;
        }
        while (j > 0)
        {
            str[k][i] = '*';
            str[k][j] = '*';
            i++;
            j--;
            k++;
        }
        while (j != clone-1)
        {
            str[k][i] = '*';
            str[k][j] = '*';
            i--;
            j++;
        }
        clone = star + k;
        while (k <= clone) {    
            str[k][i] = '*';
            str[k][j] = '*';
            i--;
            j++;
            k++;
        }
        k++;
    }
    return (str);
}

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
}
