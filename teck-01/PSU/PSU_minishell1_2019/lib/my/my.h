/*
** EPITECH PROJECT, 2019
** my
** File description:
** Headers of functions
*/
#include <stdarg.h>

void my_putchar_error(char c);
int my_putstr_error(char const *str);
void my_putchar(char c);
int my_isneg(int nb);
void my_putnbr(int nb);
void my_unsigned_putnbr(unsigned int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
void display_var(char type, va_list *list);
int my_printf(char *s, ...);
int recup_nb_of_var(char *s);
char *int_binaire(int value);
char *int_hexa_maj(int value);
void display_type(char type, va_list *list);
char *int_hexa_min(int value);
int int_octal(int value);
int *string_octal(char *sr);
int int_simple_octal(int value);