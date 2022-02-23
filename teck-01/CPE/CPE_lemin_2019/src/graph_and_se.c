/*
** EPITECH PROJECT, 2020
** graph_and_se.c
** File description:
** graph
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "graph.h"
#include "lemin.h"
#include "function.h"

node_t *newadjlistnode(int dest)
{
    node_t *newnode = malloc(sizeof(node_t));
    newnode->dest = dest;
    newnode->next = NULL;
    return newnode;
}

graph_t *creategraph(int vertice)
{
    int i = 0;
    graph_t *graph = malloc(sizeof(graph_t));

    graph->vertice = vertice;
    graph->array = malloc(vertice * sizeof(list_t));
    for (i = 0; i < vertice; i++)
        graph->array[i].head = NULL;
    return graph;
}

void addedge(graph_t *graph, int src, int dest)
{
    node_t *newnode = newadjlistnode(dest);

    newnode->next = graph->array[src].head;
    graph->array[src].head = newnode;
    newnode = newadjlistnode(src);
    newnode->next = graph->array[dest].head;
    graph->array[dest].head = newnode;
}

void printgraph(graph_t *graph)
{
    int ver;
    node_t *node;
    for (ver = 0; ver < graph->vertice; ver++) {
        node = graph->array[ver].head;
        my_putstr("linked to this room :");
        my_put_nbr(ver);
        while (node != NULL) {
            my_put_nbr(node->dest);
            node = node->next;
        }
        my_putstr("\n");
    }
}

char *start_end(char *buffer)
{
    int k = 0;
    char *s_e = malloc(4);
    char start[7] = "#start";
    char end[5] = "#end";
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '#'){
            for (int j = 0; j < 4; j++){
                if (buffer[i + j] != end[j])
                    break;
                if (j == 3)
                    s_e[k++] = buffer[i + j + 2];
            }
            for (int j = 0; j < 6; j++){
                if (buffer[i + j] != start[j])
                    break;
                if (j == 5)
                    s_e[k++] = buffer[i + j + 2];
            }
        }
    } return (s_e);
}
