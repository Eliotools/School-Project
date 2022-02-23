/*
** EPITECH PROJECT, 2020
** duostumper
** file :
** Moi
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

char give_me_my_letter(char* word)
{
    static int i = 0;
    printf("strlen = %d\n", strlen(word));
    if (i > (strlen(word)))
        return('1');
    i++;
    return (word[i]);
}

int make_my_return(char **grid ,char *word, char to_find, int i, int x, int y)
{
    if (word[i] != to_find && i != strlen(word)-1)
        return (1);
    if (to_find == word[i]) {
        find(grid, word, x, y);
    } else
        return (0);
}

int find(char **grid, char *word, int x, int y)
{
    static int i = 0;
    int j = i;
    char to_find = give_me_my_letter(word);

    grid[y][x] -= 32;
    if (to_find == '1')
        return (0);
    if (grid[y][x+2] == (to_find) && i == j) {
        x += 2;
        i++;
    } else if (grid[y][x-2] == (to_find) && i == j) {
        x -= 2;
        i++;
    } if (grid[y+1][x] == (to_find) && i == j) {
        y += 1;
        i++;
    } else if (grid[y-1][x] == (to_find) && i == j) {
        y -= 1;
        i++;
    } return (make_my_return(grid, word, to_find, i, x , y));
}

int find_compte(char **grid, char c)
{
    int x = 0;
    int y = 0;
    int compte = 0;
    
    while (grid[y] = NULL)
    {
        if (grid[y][x] == '|' || grid[y][x] == '+') {
            y++;
            x = 0;
        } if (grid[y][x] == c )
              compte++;
        x++;
    }
    return (compte);
}


int first(char **grid, char *word)
{
    int x = 0;
    int y = 0;
    static int compte = 0;
        
    compte = find_compte(grid, word[0]); 
      while (compte != 0) {
        if (grid[y][x] == '|' || grid[y][x] == '+') {
            y++;
            x = 0;
        } if (grid[y][x] == word[0])
              compte--;
        x++;
    }
    return (find(grid, word, x, y));
}
