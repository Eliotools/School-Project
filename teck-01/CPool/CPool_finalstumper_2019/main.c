/*
** EPITECH PROJECT, 2024
** my_project
** File description:
** Created by Leo Fabre
*/

#include "my.h"
#include <unistd.h>
#include "rush3.h"

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
    return (rush3(buff));
}
