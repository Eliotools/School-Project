/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** my_getnbr Piscine
*/

int global_counter(int n, char const *str);

int my_getnbr(char const *str)
{
    int n = 0;
    int i = 0;
    int minus = 0;
    int n_before_alter;
    while (str[i] == 45 || str[i] == 43) {
        if (str[i] == 45)
            minus++;
        i++;
    }
    while (str[i] >= 48 && str[i] <= 57) {
        n_before_alter = n;
        n = n * 10 + str[i] - '0';
        if (n / 10 != n_before_alter && n != -2147483648)
            return (0);
        if (n == 214748364 && str[i + 1] == '8' && minus % 2 == 0)
            return (0);
        i++;
    }
    return (minus % 2 != 0 ? -n : n);
}