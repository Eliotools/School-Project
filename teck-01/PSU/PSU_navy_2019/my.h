/*
** EPITECH PROJECT, 2024
** CPool_Day07_2019
** File description:
** Created by Moi
*/
#ifndef my
#define my

int main(int ac, char **av);
int finding_twice(char *pos);
void maper(char *geo, char **map, char k);
char *filler(char *pos, char *str, int i, int j);
void space_x(char *first, char *second, char **map, char k);
void filling(char *pos, char **map);
char **decoding_pos(char *pos, char **map);
int next(char **pos, int pid);
void call(void);
void process(void);
void kill_it(int pid);
void space_y(char *first, char *second, char **map, char k);
int connecting (int pid);

int	g_user2pid;

#endif //my