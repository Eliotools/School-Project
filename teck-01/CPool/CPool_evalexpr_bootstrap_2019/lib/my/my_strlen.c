/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** task03 Day04
*/

int my_strlen(char const *str)
{
    int nb = 0;
    int i = 0;

    while (str[i] !=    '\0') {
        i++;
        nb++;
        }
    return (nb);
}