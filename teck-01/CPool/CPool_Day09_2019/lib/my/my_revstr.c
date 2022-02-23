/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** task03 Day06
*/

char *my_revstr(char *str)
{
    int i = 0;
    int c = 0;
    char s;

    while (str[i] != '\0') {
        i++;
    }
    for (c; c < i; c++)
    {
        s = str[c];
        str[c] = str[i - 1];
        str[i - 1] = s;
        c++;
        i--;
    }
    return (str);
}
