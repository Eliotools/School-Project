/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD09-eliot.martin
** File description:
** ex00
*/

#include <stdio.h>
#include <stdlib.h>

#ifndef EX00_H_
#define EX00_H_

typedef struct cthulhu_s {
    int m_power;
    char *m_name;
}cthulhu_t;

typedef struct koala_s
{
    cthulhu_t m_parent;
    char m_is_a_legend;

}koala_t;

cthulhu_t *new_cthulhu();
void print_power(cthulhu_t *this);
void attack(cthulhu_t *this);
void sleeping(cthulhu_t *this);
koala_t *new_koala(char *name, char is_a_legend);
void eat(koala_t *this);
void koala_initializer(koala_t *this, char *_name, char _is_A_Legend);
void cthulhu_initializer(cthulhu_t *this);

#endif /* !EX00_H_ */
