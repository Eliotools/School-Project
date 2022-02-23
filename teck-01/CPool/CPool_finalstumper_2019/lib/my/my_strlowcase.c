/*
** EPITECH PROJECT, 2024
** day06
** File description:
** Created by Leo Fabre
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += ('a' - 'A');
    return str;
}