/*
** EPITECH PROJECT, 2020
** main
** File description:
** Moi
*/

#include "my.h"

char *new(char c, char **src, char *E)
{
    char *new = delet(src[c-46], src[c-46][0]);
    for (int i = 0; E[i]; i++){
        new = delet(new, E[i]);
    }
    return (new);
}

char find_s(int *way, int size, char *T)
{
    int smaller = 999;
    char new;

    for (int i = 0; i != size; i++) {
        if (smaller > way[i] && is_in(T, i+48) != 1)
        {
            smaller = way[i];
            new = i+48;
        }
    }
    return (new);
}

char *dijktra(char **tab)
{
    all_t *all = malloc(sizeof(all_t));
    all->src = tab;
    all->s = all->src[0][0];
    all->top = all->src[1];
    all->size = len(all->top);
    all->untop = malloc(sizeof(char) * len(all->top));
    all->way = init_way(all->top, all->s);
    all->next = delet(all->src[all->s-46], all->src[all->s-46][0]);
    all->old = malloc(sizeof(char) * len(all->top));
    return (loop(all));
}

char *loop(all_t *all)
{
    for (int i = 0; i != len(all->top); i++)
    {
        all->top = delet(all->top, all->s);
        all->untop = add(all->untop, all->s);
        all->way[all->s-48] = i;
        all->n  
        if (all->next == NULL)
            return (NULL);
        for (int j = 0; all->next[j]; j++)
            if (all->way[all->next[j]-48] >= all->way[all->s-48] + 1)
                all->way[all->next[j]-48] = all->way[all->s-48] + 1;
        all->s = find_s(all->way, all->size, all->next);
        all->old[i] = all->s;
        if (all->s == all->src[0][1])
            return (all->old);

    }
    return (NULL);
}