/*
** EPITECH PROJECT, 2024
** day06
** File description:
** Created by Leo Fabre
*/

char *my_revstr(char *str)
{
    int len = 0;
    int j = 0;
    char swap;

    for (; str[len] != '\0'; ++len);
    len--;
    for (; len >= j; j++, len--) {
        swap = str[len];
        str[len] = str[j];
        str[j] = swap;
    }
    return str;
}