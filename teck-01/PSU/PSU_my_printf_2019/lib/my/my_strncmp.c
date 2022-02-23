/*
** EPITECH PROJECT, 2024
** day06
** File description:
** Created by Leo Fabre
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n - 1; ++i);
    return (s1[i] - s2[i]);
}