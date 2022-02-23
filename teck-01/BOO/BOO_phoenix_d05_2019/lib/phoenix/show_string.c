/*
** EPITECH PROJECT, 2019
** Phenix
** File description:
** Moi
*/

void my_putchar(char c);

int show_string(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}