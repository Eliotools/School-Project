/*
** EPITECH PROJECT, 2019
** Phoenix
** File description:
** Moi
*/

int len(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}