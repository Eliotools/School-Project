/*
** EPITECH PROJECT, 2019
** Phoenix
** File description:
** Moi
*/
int show_string(char const *str);
void my_putchar(char c);

int show_string_array(char *const *array)
{
    int i = 0;
    while (array[i] != "0")
    {
        show_string(array[i]);
        my_putchar('\n');
        i++;
    }
    return (0);
}
