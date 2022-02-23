/*
** EPITECH PROJECT, 2024
** CPool_Day07_2019
** File description:
** Created by Moi
*/

#include <stdlib.h>

int len(char *);

int count_w(char *str, char c)
{
    int i = 0;
    int j = 0;

    for (; str[i] == c || str[i] == '\0'; i++);
    if (str[i] != c && str[i])
        j = 1;
    while (i < (len(str) -1)) {
        if (str[i] == c && str[i + 1] != c)
            j++;
        i++;
    }
    return (j);
}

int word_len(char *str, char c, int *pos)
{
    int len = 0;
    int i = *pos;

    for (; str[i] && str[i] == c; i++);
    if (str[i] == '\0')
        return (0);
    for (; str[i] && str[i] != c; i++, len++);
    *pos = i;
    return (len);
}

char **str_to_word_array(char *str, char c)
{
    int pos = 0;
    char **tab;
    int word = count_w(str, c);
    int len = 0;
    int j = 0;

    if (word == 0)
        return (NULL);
    tab = malloc(sizeof(char *) * (word + 1));
    for (int i = 0; i < word; i++) {
        len = word_len(str, c, &pos);
        j = pos - len;
        tab[i] = malloc(sizeof(char) * (len + 1));
        for (int d = 0; d < len; d++, j++)
            if (str[j] != '\n')
                tab[i][d] = str[j];
        tab[i][len] = '\0';
    }
    tab[word] = NULL;
    return (tab);
}
