/*
** EPITECH PROJECT, 2024
** day06
** File description:
** Created by Leo Fabre
*/

int my_str_isalpha(char const *str)
{
    while (*str) {
        if (!((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')))
            return (0);
        str++;
    }
    return (1);
}