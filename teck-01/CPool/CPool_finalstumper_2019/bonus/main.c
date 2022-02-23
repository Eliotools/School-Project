/*
** EPITECH PROJECT, 2024
** my_project
** File description:
** Created by Leo Fabre
*/

#include "my.h"
#include <unistd.h>
#include "rush3.h"

void bonus(char *str)
{
    int len = my_firstline_len(str);
    int nb_lines = my_count_lines(str);

    my_putstr("Aire Total Exterieur = ");
    my_put_nbr(len * nb_lines);
    my_putchar('\n');
    if (len > 2 && nb_lines > 2) {
        my_putstr("Aire Total Interieur = ");
        my_put_nbr((len - 2) * (nb_lines - 2));
        my_putchar('\n');
    } else
        my_putstr("Aire Total Interieur = 0\n");
}

int main(void)
{
    char buff[BUFF_SIZE + 1];
    int offset = 0;
    int len = 0;

    while ((len = read(0, buff + offset, BUFF_SIZE - offset))> 0){
        offset += len;
    }
    buff[offset] = '\0';
    if (len < 0 || my_strlen(buff) == 0)
        return (84);
    rush3(buff);
    bonus(buff);
    return (0);
}
