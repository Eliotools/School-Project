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

void  append_c(string_t *this, const  char *ap)
{
    int size = strlen(this->str)+(strlen(ap))+1;
    char *new = malloc(sizeof(char) * (size));
    for (int i = 0; i < size; i++)
        new[i] = 0;
    new = strcat(new, this->str);
    new = strcat(new, ap);
    this->str = new;
}

char at(const  string_t *this, size_t pos)
{
    int size = strlen(this->str);

    if (pos < 0 || pos >= size-2)
        return (-1);
    return (this->str[pos]);
}

void  clear(string_t *this)
{
    this->str = NULL;
    this->str = malloc(sizeof(char)* 1);
    this->str[0] = '\0';
}

int  size(const  string_t *this)
{
    if (this->str == NULL)
        return (-1);
    return (strlen(this->str));
}

int  compare_s(const  string_t *this, const  string_t *str)
{
    return (strcmp(this->str, str->str));
}

