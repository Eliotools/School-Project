/*
** EPITECH PROJECT, 2024
** CPool_Day07_2019
** File description:
** Created by Moi
*/

#include <stdarg.h>
#ifndef printf
#define printf

int len_buff(void);
int converteur(int nb, int base);
int power(int nb, int pow);
int my_new_putstr(char const *str, int base);
char *my_new_realloc(char *save, int size);
char *itob(unsigned int to_convert);
void pourcent_id(va_list list);
void pourcent_s(va_list list);
void pourcent_c(va_list list);
void pourcent_b(va_list list);
void pourcent_big_s(va_list list);
void pourcent_(void);
void pourcent_u(va_list list);
void pourcent_o(va_list list);
void pourcent_X(va_list list);
void pourcent_x(va_list list);
void my_put_nbr_in_str(char new, int base);
int my_new_putstr(char const *str, int base);
void pourcent_p(va_list list);
void my_printf(char *str, ...);
int my_new_putstr(char const *str, int base);
void my_put_nbr_in_str(char new, int base);

#endif //printf