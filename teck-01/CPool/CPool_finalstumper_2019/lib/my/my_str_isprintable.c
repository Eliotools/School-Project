/*
** EPITECH PROJECT, 2024
** day06
** File description:
** Created by Leo Fabre
*/

int my_str_isprintable(char const *str)
{
    for (; *str; ++str) {
        if (!(*str >= ' ' && *str <= 127))
            return (0);
    }
    return (1);
}