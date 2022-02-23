/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD09-eliot.martin
** File description:
** ex00
*/

#include "ex00.h"

cthulhu_t *new_cthulhu()
{
    cthulhu_t *new = malloc(sizeof(cthulhu_t));
    cthulhu_initializer(new);
    return (new);
}

void cthulhu_initializer(cthulhu_t *this)
{
    this->m_name = "Cthulhu\0";
    this->m_power = 42;
    printf("----\nBuilding %s\n", this->m_name);
}

void print_power(cthulhu_t *this)
{
    printf("Power => %d\n", this->m_power);
}

void attack(cthulhu_t *this)
{
    if (this->m_power >= 42) {
        this->m_power -= 42;
        printf("%s attacks and destroys the city\n", this->m_name);
    }
    else
        printf("%s can't attack, he doesn't have enough power\n", this->m_name);
}

void sleeping(cthulhu_t *this)
{
    this->m_power += 42000;
    printf("%s sleeps\n", this->m_name);

}

koala_t *new_koala(char *name, char is_a_legend)
{
    koala_t *new = malloc(sizeof(cthulhu_t));
    koala_initializer(new, name, is_a_legend);
    return (new);
}

void koala_initializer(koala_t *this, char *_name, char _is_A_Legend)
{
    cthulhu_t *_cthulhu = new_cthulhu();

    this->m_is_a_legend = _is_A_Legend;
    this->m_parent = *_cthulhu;
    if (this->m_is_a_legend)
        this->m_parent.m_power = 42;
    else 
        this->m_parent.m_power = 0;
    this->m_parent.m_name = _name;
    printf("Building %s\n", this->m_parent.m_name);
}

void eat(koala_t *this)
{
    this->m_parent.m_power += 42;
    printf("%s eats\n", this->m_parent.m_name);

}