/*
** EPITECH PROJECT, 2020
** main
** File description:
** Moi
*/

#include "func_ptr.h"
#include "func_ptr_enum.h"
#include <stdio.h>
#include <string.h>

void  print_normal(const  char *str)
{
    printf("%s\n", str);
}

void  print_reverse(const  char *str)
{
    int i = strlen(str);
    while (i != -1) {
        printf("%c", str[i]);
        i--;
    }
    printf("\n");

}

void  print_upper(const  char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] <= 122 && str[i] >= 97 )
            printf("%c", str[i]-32);
        else
            printf("%c", str[i]);
    }
    printf("\n");

}

void  print_42(const  char *str)
{
    printf("42\n");
}

void do_action(action_t  action , const  char *str)
{
    void (*point_func[4])(const char *) = {&print_normal, &print_reverse,
    &print_upper, &print_42};
    action_t a[4] = {PRINT_NORMAL, PRINT_REVERSE, PRINT_UPPER, PRINT_42};

    for (int i = 0; i <= 3; i++)
        if (action == a[i])
            (*point_func[i])(str);
}