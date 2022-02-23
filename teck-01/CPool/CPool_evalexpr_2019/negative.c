/*
** EPITECH PROJECT, 2019
** negative
** File description:
** supprime les moins
*/

char negative(char *str, int i)
{
    char strplus = str[i + 1];
    char signe = '0';
    if (str[i] >= '0' && str[i] <= '9') {
        if (strplus < '0' || strplus > '9') {
            signe = (strplus);
            return (signe);
        }
        else
            return ('0');
    }
    else
        return ('0');
}