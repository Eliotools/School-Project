/*
** EPITECH PROJECT, 2019
** my_list_size
** File description:
** size
*/
#include "include/mylist.h"
#include "my.h"

int my_list_size(linked_list_t const *begin)
{
    int i = 0;
    linked_list_t *t;

    t = begin;
    while (t != NULL)
    {
        i++;
        t = t->next;
    }
    return (i);
}
