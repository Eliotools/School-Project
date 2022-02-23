/*
** EPITECH PROJECT, 2024
** day06
** File description:
** Created by Leo Fabre
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (; src[i] != '\0' && n > 0; ++i, --n)
        dest[i] = src[i];
    if (n > 0)
        dest[i] = '\0';
    return dest;
}