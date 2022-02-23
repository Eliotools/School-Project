/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_strcmp
*/

int my_strlen(char const *str);

int my_strcmp(const char *str1, char const *str2)
{
    if (my_strlen(str1) != my_strlen(str2))
        return (1);
    for (int i = 0; str1[i]; i++) {
        if (str1[i] != str2[i])
            return (1);
    }
    return (0);
}