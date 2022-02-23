/*
** EPITECH PROJECT, 2020
** strcmp
** File description:
** Moi
*/

int my_strcmp(char const *s1, char const *s2, char c)
{
    int i = 0;

    while (s1[i] && s2[i]) {
        if (s1[i] != s2[i])
            return (1);
        if (s1[i+1] == c || s2[i+1] == c)
            return (0);
        i++;
    }
    return (0);
}
