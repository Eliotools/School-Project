/*
** EPITECH PROJECT, 2020
** main
** File description:
** Moi
*/

#ifndef EX_5_H_
# define EX_5_H_

# include <stdint.h>

typedef union foo_t
{
    struct
    {
        short foo;
        union
        {
            short bar;
            short foo;
        } bar;
    } foo;
    int bar;
} foo_t;

#endif