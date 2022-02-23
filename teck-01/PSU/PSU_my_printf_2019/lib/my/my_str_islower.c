/*
** EPITECH PROJECT, 2024
** day06
** File description:
** Created by Leo Fabre
*/

int my_str_islower(char const *str)
{
    while (*str) {
        if (!(*str >= 'a' && *str <= 'z'))
            return (0);
        str++;
    }
    return (1);
}