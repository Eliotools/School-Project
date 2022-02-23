/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_str_is_alphanum
*/

int my_str_is_alphanum(char x)
{
    if (x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z' || x >= '0' && x <= '9')
        return (0);
    else
        return (1);
}