/*
** EPITECH PROJECT, 2024
** day06
** File description:
** Created by Leo Fabre
*/

int my_str_isupper(char const *str)
{
    while (*str) {
        if (!(*str >= 'A' && *str <= 'Z'))
            return (0);
        str++;
    }
    return (1);
}