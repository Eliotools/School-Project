/*
** EPITECH PROJECT, 2020
** main
** File description:
** Moi
*/

#include  <stdio.h>
#include "string.h"
#include <stdlib.h>
#include <stdio.h>

int  find_c(const  string_t *this , const  char *str , size_t  pos)
{
    int i = pos;
    int j = 0;

    while (i <= strlen(this->str)) {
        j = 0;
        while (this->str[i] == str[j] && str[j] != '\0') {
            i++;
            j++;
        }
        if (j == strlen(str)) {
            return (i - j);
        }
        i++;
    }
    return (-1);
}

void  insert_c(string_t *this , size_t pos , const  char *str)
{
    int size = strlen(this->str) + strlen(str)+1;
    int i = 0;
    int j = 0;
    char *new = malloc(sizeof(char) * (size));
    while (i != pos && i < strlen(this->str)) {
        new[i] = this->str[i];
        i++;
    }
    new[i] = '\0';
    new = strcat(new, str);
    j = i;
    i += strlen(str);
    while (this->str[j] != '\0') {
        new[i] = this->str[j];
        i++;
        j++;
    }
    new[i] = '\0';
    this->str = new;
}

void  insert_s(string_t *this, size_t pos , string_t *str)
{
    int size = strlen(this->str) + strlen(str->str)+1;
    int i = 0;
    int j = 0;
    char *new = malloc(sizeof(char) * (size));
    while (i != pos && i < strlen(this->str)) {
        new[i] = this->str[i];
        i++;
    }
    new[i] = '\0';
    new = strcat(new, str->str);
    j = i;
    i += strlen(str->str);
    while (this->str[j] != '\0') {
        new[i] = this->str[j];
        i++;
        j++;
    }
    new[i] = '\0';
    this->str = new;
    free(new);
}
