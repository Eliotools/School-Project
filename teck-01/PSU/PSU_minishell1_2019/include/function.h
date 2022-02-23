/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** function
*/

#ifndef FUNCTION_H_
#define FUNCTION_H_

int recup_nbr_of_word(char *av);
char *recup_word(char *av);
char *recup_separate_arg(char *av);
int verif_get(char *str);
char **recup_arg(void);
int my_exec(char **arg, char **envp);
int check_fct(char **str, char **envp);
char *recup_separate_path(char *av);
char **recup_path(char **envp);
int try_and_exec(char **arg, char **envp);
void my_env(char **env);
int my_setenv(char **arg, char **env);
void change_env(char **env, char **arg, int line);
void my_unsetenv(char **arg, char **env);
int my_exit(char **arg);
int my_strlen(char *str);
int my_strlen_w_spaces(char *str);
void my_strcat(char *dest, char *str);
int my_strcmp(char *name, char *str);
int my_atoi(char *str);
int my_cd_normal(char *path);
char *recup_home(char **env);
int my_cd(char **av, char **env);
void cat_some_things(char **arg, char **env, char *str, int i);

#endif /* !FUNCTION_H_ */
