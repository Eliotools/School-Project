/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** task06 Day06 
*/

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    int size_1 = my_strlen(s1);
    int size_2 = my_strlen(s2);

    if (size_1 < size_2)
        return (size_1 - size_2);
    if (size_1 == size_2)
        return (size_1 - size_2);
    if (size_1 > size_2)
        return (size_1 - size_2);
}
