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
char **str_to_word_array(char *str, char t);
char *readable(char *path);
int my_strcmp(char const *s1, char const *s2, char c);
int check_buff(char *buffer);
char *my_strcat(char *dest, char const *src);
char *chartochar(char **array);
int randomizer(int nb);
int error (char *buffer, int i);
int space_x (int k, char *buffer, int j);
int asking_int(void);
char *asking_char(void);
int word_len(char *str, char c, int *pos);
int count_w(char *str, char c);
int my_new_strlen(char *str);

#endif //Phoenix