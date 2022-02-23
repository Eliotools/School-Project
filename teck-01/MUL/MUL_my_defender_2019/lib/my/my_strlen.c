/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** my_strlen.c
*/

int my_strlen(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z') {
            count++;
            i++;
        }
        else
            i++;
    }
    return (count);
}