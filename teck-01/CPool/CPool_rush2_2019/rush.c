/*
** EPITECH PROJECT, 2019
** rush2
** File description:
** cara
*/
#include <stdio.h>
#include <unistd.h>
#include "my.h"

int my_put_nbr (int nb);

int  my_putstr( char const *str);

int my_strlen(char const *str)
{
    int nb = 0;
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] >= 'a' && str[i] >= 'z') \
            || (str[i] >= 'A' && str[i] >= 'Z' )) {
            nb++;
        }
        i++;
    }
    return (nb);
}

int freq (char *str, int a)
{
    int i = my_strlen(str);
    int freq = ((a*100)/i);
    int freq2 = ( (((a*100)%i)*100)/7);
    
    write(1, " ", 1);
    write(1, "(", 1);
    my_put_nbr(freq);
    write(1, ".", 1);
    my_put_nbr(freq2);
    write(1, "%", 1);
    write(1, ")", 1);
    write (1, "\n", 1);
    return (freq);
}

void make_str (char str, int a)
{
    char strfinal[5];

    strfinal [0] = str;
    strfinal [1] = ' ';
    strfinal [2] = '=';
    strfinal [3] = ' ';
    strfinal [4] = '\0';
    my_putstr(strfinal);
    my_put_nbr(a);
}

int counter(char *str, char str2)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0')
    {
        if (str[i] == str2 || \
            str[i]  == str2  + 32 || \
            str[i]  == str2  - 32)
            j++;
        i++;
    }
    return (j);
}

int main(int argc, char **argv)
{
    if (argc > 2) {
        char *str = argv[1];
        int i = 2;
        char str2;
        int a;
        
        while (i != argc) {
            str2 = argv[i][0];
            a = (counter(str, str2));
            make_str (str2, a);
            freq (str, a);
            i++;
        }
        return(0);
    }
    else {
        write (2, "Invalid Parameter\n", 19);
        return(84);
        
    }
}
