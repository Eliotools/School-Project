/*
** EPITECH PROJECT, 2024
** day06
** File description:
** Created by Leo Fabre
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; ++i);
    return s1[i] - s2[i];
}