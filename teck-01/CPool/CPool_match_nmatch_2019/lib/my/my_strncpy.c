/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** task02 Day06
*/

int my_strlen(char const *src);

char *my_strncpy (char *dest, char const *src, int n)
{
    int i = 0;
    int src_len = my_strlen(src);

    while (src[i] != '\0' && i < n)
    {
        dest[i] = src[i];
        i++;
        if (src_len < n )
            dest[src_len + 1] = '\0';
        else
            return (dest);
    }
    return (dest);
}
