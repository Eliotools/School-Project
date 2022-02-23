/*
** EPITECH PROJECT, 2024
** day06
** File description:
** Created by Leo Fabre
*/

int my_str_isnum(char const *str)
{
    while (*str) {
        if (!(*str >= '0' && *str <= '9'))
            return (0);
        str++;
    }
    return (1);
}