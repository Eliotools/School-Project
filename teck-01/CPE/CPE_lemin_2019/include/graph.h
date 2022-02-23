/*
** EPITECH PROJECT, 2020
** graph.h
** File description:
** graph structs
*/

#ifndef LEMIN_H_
#define LEMIN_H_


typedef struct adjlistnode
{
    int dest;
    struct adjlistnode *next;
} node_t;

typedef struct adjlist
{
    struct adjlistnode *head;
} list_t;

typedef struct graph
{
    int vertice;
    struct adjlist *array;
} graph_t;

void printgraph(graph_t *graph);
void addedge(graph_t *graph, int src, int dest);
graph_t *creategraph(int vertice);
node_t *newadjlistnode(int dest);

#endif