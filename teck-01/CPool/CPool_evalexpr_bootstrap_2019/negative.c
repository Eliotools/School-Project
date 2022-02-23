/*
** EPITECH PROJECT, 2019
** negative
** File description:
** supprime les moins
*/

char negative (char *str, int i)
{
    char strplus = str[i + 1];
    char signe = '0';
    if (str[i] >= '0' && str[i] <= '9') {
        if (strplus < '0' || strplus > '9') {
            printf("str = %s\n", str);
            printf("char = %c\n", str[i]);
            printf("char +1 = %c\n", strplus);
            printf("empacement n°%i\n", i);
            signe = (strplus);
            my_put_nbr(i);
            printf("return = %c\n", signe);
            return (signe);
        }
        else 
            return('0');
    }
    else 
        return('0');
}
    
