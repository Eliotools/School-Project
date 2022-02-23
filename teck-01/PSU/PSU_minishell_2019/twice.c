/*                                                                                                                   
** EPITECH PROJECT, 2019                                                                                             
** Phoenix                                                                                                           
** File description:                                                                                                 
** Moi                                                                                                               
*/

#include "include/phoenix.h"
#include <stdlib.h>

int finding_space(char const *str)
{
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ' ') {
            j++;
        }
    j++;
    return (j);
}

int lening_space(char const *str, int j)
{
    int i = 0;
    while ((str[j] != ' ' ) && j < len(str)) {
            i++;
            j++;
    }
    return (i);
}

char *filling(int k, char const *str, char **autre, int j)
{
    int i = 0;
    while ((str[j] != ' ') && j < len(str))
    {
        autre[k][i] = str[j];
        j++;
        i++;
    }
    return (autre[k]);
}

int againing(char const *str, int j)
{
    int i = 0;
    while ((str[j] == ' ') && j < len(str)) {
        j++;
        i++;
    }
    return (i);
}

char **spliting_string(char const *str)
{
    int k = 0;
    int clone = 0;
    char **autre = malloc(sizeof(char *) * finding_space(str)+1);

    for (int j = 0; j < len(str); j++)
    {
        j += lening_space(str, j);
        autre[k] = malloc(sizeof(char)* j);
        autre[k] = filling(k, str, autre, clone);
        j += againing(str, j);
        clone = j;
        k++;
    }
    autre[k] = NULL;
    return (autre);
}