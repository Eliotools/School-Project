*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** str
*/

int my_putstr (char const *str )
{
    int i = 0;

    while (str[i] != '\0')
    {
        i++;
    }
    my_putchar(i);
}

