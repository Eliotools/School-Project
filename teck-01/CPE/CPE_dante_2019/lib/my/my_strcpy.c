/*
** EPITECH PROJECT, 2024
** day06
** File description:
** Created by Leo Fabre
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i] != '\0' ; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}