/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** task06 Day06 
*/

int my_strlen(char const *str);


int my_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
    {
        i++;
    }
    return (i);
}
