/*
** EPITECH PROJECT, 2019
** CPool_Day08_2019
** File description:
** lib.h
*/

#ifndef MY_H_
#define MY_H_
#include <stdarg.h>

void my_putchar(char);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char *str);
int my_printf(char *str, ...);
int my_put_nbr_octa(int nb);
int my_put_nbr_u(int nb);
int my_put_nbr_bin(int nb);
int my_put_nbr_hexa(int nb);
int first_flags(char *str, int counter, va_list list);
int second_flags(char *str, int counter, va_list list);
int third_flags(char *str, int counter, va_list list);

#endif /* MY_H_ */
