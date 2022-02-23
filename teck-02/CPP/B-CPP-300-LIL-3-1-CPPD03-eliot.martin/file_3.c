/*
** EPITECH PROJECT, 2020
** main
** File description:
** Moi
*/

#include  <stdio.h>
#include "string.h"
#include <stdlib.h>
#include <stdio.h>

int  compare_c(const  string_t *this, const char *str)
{
    return (strcmp(this->str, str));
}

size_t copy(const  string_t *this , char *s, size_t n, size_t  pos)
{
    int i = pos;
    char * new = malloc(sizeof(char) * n);

    if (pos >= strlen(this->str))
        return (0);
    for (int j = 0; j != n && this->str[i] != '\0'; i++, j++)
        new[j] = this->str[i];
    s = new;
    free(new);
    return (i-pos);
}

const char *c_str(const  string_t *this)
{
    return (this->str);
}

int empty(const string_t *this)
{
    if (this->str == NULL)
        return (1);
    if (strlen(this->str) == 0)
        return (1);
    return (0);
}

int find_s(const  string_t *this , const  string_t *str , size_t  pos)
{
    int i = pos;
    int j = 0;

    while (i <= strlen(this->str)) {
        j = 0;
        while (this->str[i] == str->str[j] && str->str[j] != '\0') {
            i++;
            j++;
        }
        if (j == strlen(str->str)) {
            return (i - j);
        }
        i++;
    }
    return (-1);
}