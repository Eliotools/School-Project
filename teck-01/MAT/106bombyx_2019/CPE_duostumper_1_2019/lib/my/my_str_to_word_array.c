/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int my_str_is_alphanum(char c);

int my_wordlen(char const *str, int i);

int my_spaceslen(const char *str, int i)
{
    int x = 0;

    for (i; str[i] == ' '; i++)
        x++;
    return (x);
}

int my_cols(char const *str)
{
    int longest = 0;
    int current = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            if (current > longest)
                longest = current;
            current = 0;
        } else if (str[i+1] == '\0') {
            current++;
            if (current > longest)
                longest = current;
        } else {
            current++;
        }
    }
    return longest;
}

int my_words(char const *str)
{
    int x = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > 47 && str[i] < 58 || str[i] > 64 && str[i] < 91
        || str[i] > 96 && str[i] < 123) {
            x++;
            i += my_wordlen(str, i);
        }
    }
    return (x);
}

char **my_fill(char const *str, char **tab, int lines)
{
    int j = 0;
    int w = 0;
    int i = 0;

    for (int x = 0; str[x]; x++) {
        if (my_str_is_alphanum(str[x]) == 1) {
            x += my_spaceslen(str, x + 1);
        } else {
            while (my_str_is_alphanum(str[x]) == 0) {
                tab[w][j] = str[x];
                x++;
                j++;
            }
            w++;
            j = 0;
        }
        if (w == lines)
            break;
    }
    return (tab);
}

char **my_str_to_word_array(char const *str)
{
    int cols = my_cols(str);
    int lines = my_words(str);
    char **tab = malloc(sizeof(char *) * (cols + 1));

    if (tab == NULL)
        return (NULL);
    for (int i = 0; i < lines; i++) {
        tab[i] = malloc(sizeof(char) * (cols + 1));
        if (tab[i] == NULL)
            return (NULL);
    }
    tab = my_fill(str, tab, lines);
    return (tab);
}