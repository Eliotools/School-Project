/*
** EPITECH PROJECT, 2019
** Phoenix
** File description:
** Moi
*/

int len(char const *str);

char *my_strcapitalize(char *str)
{
    if (str[0]  >= 'a' && str[0] <= 'z')
        str[0] -= 32;
    for (int i = 0; i < len(str)-1; i++) {
        if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z') &&
(str[i+1] >= 'a' && str[i+1] <= 'z'))
            str[i+1] -= 32;
        if (((str[i] >= 'A' && str[i] <= 'Z') || (str[i]  >= 'a' &&
str[i] <= 'z')) && (str[i+1] >= 'A' && str[i+1] <= 'Z'))
            str[i+1] += 32;
    }
    return (str);
}

