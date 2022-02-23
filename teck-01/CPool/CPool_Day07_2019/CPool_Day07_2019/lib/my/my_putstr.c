/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** putstr
*/
void my_putchar (char c);

int my_putstr (char const *str)
{
    while (*str != '\0')
    {
        my_putchar(*str);
        str++;
    }
    return (1);
}
