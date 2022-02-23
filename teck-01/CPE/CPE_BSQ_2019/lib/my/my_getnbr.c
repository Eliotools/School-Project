/*
** EPITECH PROJECT, 2024
** day04
** File description:
** Created by Moi
*/

int my_getnbr(char const *str)
{
    int res = 0;
    int sign = 1;
    int i = 0;

    for (i = 0; str[i] == '+' || str[i] == '-'; i++)
        if (str[i] == '-')
            sign *= -1;
    for (; ((str[i] != '\0') && (str[i] >= '0' && str[i] <= '9')); i++) {
        res *= 10;
        res += str[i] - '0';
    }
    return (res * sign);
}
