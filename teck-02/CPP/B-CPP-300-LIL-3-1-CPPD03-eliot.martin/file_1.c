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

void  assign_s(string_t *this , const  string_t *str)
{
    this->str = str->str;
}

void  assign_c(string_t *this , const  char *s)
{
    this->str = (char *)s;
}

void  string_init(string_t *this , const  char *s)
{
    this->str = (char *)s;
    this->assign_s = &assign_s;
    this->assign_c = &assign_c;
    this->append_s = &append_s;
    this->append_c = &append_c;
    this->at = &at;
    this->clear = &clear;
    this->size = &size;
    this->compare_s = &compare_s;
    this->compare_c = &compare_c;
    this->copy = &copy;
    this->c_str = &c_str;
    this->empty = &empty;
    this->find_s = &find_s;
    this->find_c = &find_c;
    this->insert_c = &insert_c;
    this->insert_s = &insert_s;
}

void  string_destroy(string_t *this)
{
    free(this->str);
}

void  append_s(string_t *this , const  string_t *ap)
{
    int size = strlen(this->str)+(strlen(ap->str))+1;
    char *new = malloc(sizeof(char) * (size));
    for (int i = 0; i < size; i++)
        new[i] = 0;
    new = strcat(new, this->str);
    new = strcat(new, ap->str);
    this->str = new;
}