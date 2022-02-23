/*
** EPITECH PROJECT, 2020
** lemin.h
** File description:
** lemin header
*/

/*typedef struct info_s
{
    int ants;
    int startname;
    int startx;
    int starty;
    int endname;
    int endx;
    int endy;
} info_t;

typedef struct child_s
{
    int data;
    struct child_s *next;
} child_t;

typedef struct node_s
{
    int data;
    child_t *down;
    struct node_s *next;
} node_t;*/

typedef struct
{
    int nbr_rooms;
    int nbr_ant;
    int *nbr_of_link;
    char **name_of_rooms;
    char **link;
    int check;
} t_info;

typedef struct move_s
{
    char *scheme;
    char **name;
    int nbr;
    int lock;
    int *state;
    int k;
} move_t;

void my_putchar(char c);
void my_putstr(char *str);
int my_put_nbr(int nb);
