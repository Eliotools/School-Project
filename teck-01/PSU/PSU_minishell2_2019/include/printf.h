/*
** EPITECH PROJECT, 2024
** CPool_Day07_2019
** File description:
** Created by Moi
*/

#include <stdarg.h>
#ifndef my_print
#define my_print

int len_buff(void);
int converteur(int nb, int base);
int power(int nb, int pow);
int my_new_putstr(char const *str, int base);
char *my_new_realloc(char *save, int size);
char *itob(unsigned int to_convert);
void percent_id(va_list list);
void percent_s(va_list list);
void percent_c(va_list list);
void percent_b(va_list list);
void percent_big_s(va_list list);
void percent_(void);
void percent_u(va_list list);
void percent_o(va_list list);
void percent_X(va_list list);
void percent_x(va_list list);
void my_put_nbr_in_str(char newe, int base);
int my_new_putstr(char const *str, int base);
void percent_p(va_list list);
void my_printf(char *str, ...);
int my_new_putstr(char const *str, int base);

#endif //printf