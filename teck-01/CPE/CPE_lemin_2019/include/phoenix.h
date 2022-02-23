/*
** EPITECH PROJECT, 2024
** CPool_Day07_2019
** File description:
** Created by Moi
*/
#ifndef Phoenix
#define Phoenix

void my_putchar(char c);
int len(char const *str);
char *my_strcpy(char *dest, char const *src);
int show_string_array(char *const *array);
char *reverse_string(char *str);
int show_number(int a);
int show_string(char const *str);
int to_number(char const *str);
char **str_to_word_array(char *str, char c);
char *readable(char *path);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *dest, char const *src);
char *chartochar(char **array);
int randomizer(int nb);
int error (char *buffer, int i);
int space_x (int k, char *buffer, int j);
char *get_next_line(int fd, int stop);
int asking_int(void);
char *asking_char(void);

#endif //Phoenix