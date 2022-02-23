/*
** EPITECH PROJECT, 2024
** day06
** File description:
** Created by Leo Fabre
*/

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        if ((i == 0 || str[i - 1] == ' ') && (str[i] >= 'a' && str[i] <= 'z'))
            str[i] -= ('a' - 'A');
    }
    return str;
}