/*
** EPITECH PROJECT, 2024
** CPool_Day07_2019
** File description:
** Created by Leo Fabre
*/
#include "my.h"

        char *my_strcat(char *dest, char const *src)
        {
            int len = my_strlen(dest);
            int i = 0;

            while (src[i]) {
                dest[len + i] = src[i];
                i++;
            }
            dest[len + i] = '\0';
            return (dest);
        }