/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_wordlen
*/

int my_wordlen(const char *str, int i)
{
    int x = 0;

    for (i; str[i] != ' '; i++) {
        if (str[i + 1] == '\0')
            return (x);
        x++;
    }
    return (x);
}