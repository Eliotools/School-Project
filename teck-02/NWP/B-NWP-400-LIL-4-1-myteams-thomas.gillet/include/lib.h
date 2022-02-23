/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet [WSL: Ubuntu]
** File description:
** lib
*/

#ifndef LIB_H_
#define LIB_H_

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <uuid/uuid.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define GREEN "\x1b[32m"
#define RESET "\x1b[0m"
#define INFO "\x1b[34m\xE2\x84\xB9\x1b[0m"
#define INFOG "\x1b[34m\xE2\x84\xB9\x1b[0m\x1b[32m"


//get_word.c
char *get_second_word_noq(char *str);
char *get_second_word(char *str);
char *get_third_word_noq(char *str);
char *get_third_word(char *str);
char *get_fourth_word_noq(char *str);
//uuid_name.c
char *gen_user_uuid(void);
char *take_name(char *line);
int get_time_stamp(char *line);
char *get_fifth_word_noq(char *str);
int get_time(char **msgsent, int j);
//str_to_zord_array.c
char **string_to_tab(const char *str);
int get_nbr_lines(char const *str);
int my_linelen(char const *str);
char *file_to_str(char *file);
char *get_x_line(char *str, int line);
//file.c
char *open_file(char *filename);
char *get_nth(char *str, int i);
char *remove_chars(char *s, char c);
char *remove_quote(char *str);

#endif /* !LIB_H_ */
