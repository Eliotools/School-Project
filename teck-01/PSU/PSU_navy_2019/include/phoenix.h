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
int find_space(char const *str);
int len_space(char const *str, int j);
char *fill(int k, char const *str, char **autre, int j);
int again(char const *str, int j);
char **split_string(char const *str);
char **str_to_word_array(char *str, char c);
char *readable(char *path);
char *my_itoa(int past);
char *convert(int past, int size);
#endif //Phoenix