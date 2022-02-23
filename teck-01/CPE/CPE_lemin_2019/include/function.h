/*
** EPITECH PROJECT, 2020
** include
** File description:
** function
*/

#ifndef FUNCTION_H_
#define FUNCTION_H_

int nbr_of_link(char *buffer);
int get_ant(char *buffer);
int get_nbr_room(char *buffer);
int *get_nbr_link(char *buffer, int nbr_room, char **name);
t_info main_info(char *av);
char **string_to_tab(const char *str);
int get_nbr_lines(char const *str);
int my_linelen(char const *str);
int my_strcmp(char *s1, char *s2);
int output(char *buffer);
int error_handling(char *buffer);
int is_it_number(char const *str);
int len(char const *str);
char *start_end(char *buffer);
char *dijktra(char **tab);
char check_index(char val, char **name);
char *check_index_2(char *val, char **name);
void print_move(char *scheme, int nb, char **name);
int number(char *str);



#endif /* !FUNCTION_H_ */
