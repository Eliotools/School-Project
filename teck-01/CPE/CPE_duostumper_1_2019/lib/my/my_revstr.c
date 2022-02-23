/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_revstr
*/

char *my_revstr(char *str)
{
    char *new_str = str;
    char temp_char;
    int half_string;
    int n = 0;
    int i = 0;
    while (str[n] != '\0')
        n++;
    n--;
    half_string = n / 2;
    while (n > half_string) {
        temp_char = str[i];
        new_str[i] = str[n];
        new_str[n] = temp_char;
        n--;
        i++;
    }
    return new_str;
}