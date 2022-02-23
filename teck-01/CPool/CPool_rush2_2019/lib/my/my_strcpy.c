/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** task01 Day06
*/

int my_strlen(char const *src);

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    int src_len = my_strlen(src);
    int dest_len = my_strlen(dest);

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    if (src_len < dest_len)
        dest[src_len + 1] = '\0';
    else
        return (dest);
    return (dest);
}
