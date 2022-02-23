/*
** EPITECH PROJECT, 2019
** main
** File description:
** Moi
*/
#include <unistd.h>

char *reverse_string(char *str);
int show_alphabet(void);
int show_combinations(void);
void show_number (int a);
int show_string(char const *str);
int to_number(char const *str);

void main (void)
{
    show_string(" !");
}

void my_putchar(char c)
{
    write(1, &c, 1);
}
