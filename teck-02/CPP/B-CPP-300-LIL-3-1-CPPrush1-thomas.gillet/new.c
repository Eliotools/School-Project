/*
** EPITECH PROJECT, 2021
** new.c
** File description:
** new
*/

#include "object.h"
#include "new.h"
#include "player.h"

Object *new(const Class *class, ...)
{
    Object *ob;
    va_list ap;

    va_start(ap, class);
    ob = va_new(class, &ap);
    va_end(ap);
    return (ob);
}

Object *va_new(const Class *class, va_list *ap)
{
    Class *new_ob;

    new_ob = malloc(class->__size__);
    memcpy(new_ob, class, class->__size__);
    if (new_ob == NULL)
        raise("Out of memory");
    if (class->__ctor__)
        class->__ctor__((Object *)new_ob, ap);
    return ((Object *)new_ob);
}

void delete(Object *ptr)
{
    Class *del = ptr;
    //del->__dtor__;
    //if (del->__dtor__)
    del->__dtor__((Class *)ptr);
    free(ptr);
}