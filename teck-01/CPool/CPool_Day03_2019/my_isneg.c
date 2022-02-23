/*  
** EPITECH PROJECT, 2019
** my_isneg.c
** File description:
** displays either N or P
*/

#include <unistd.h>

int my_isneg(int n)
{
    if (n < 0){
        write(1, "N", 1);
    }
    else{
        write(1, "P", 1);
    }
}

