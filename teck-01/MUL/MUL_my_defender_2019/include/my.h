/*
** EPITECH PROJECT, 2019
** CPool_Day08_2019
** File description:
** lib.h
*/

#ifndef MY_H_
#define MY_H_
#include <stdarg.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include <stdlib.h>
#include <SFML/System/Vector2.h>
#include <SFML/Config.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>

typedef struct draw
{
    sfTexture *r_play_t;
    sfSprite *r_play_s;
    sfTexture *play_t;
    sfSprite *play_s;
    sfVector2f sprite_pos_play;
} drawing;

typedef struct window
{
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
} window;

typedef struct menu
{
    sfMusic *menu_song;
    sfSprite *menu_screen;
    sfTexture *menu_screen_t;
    sfSprite *exit;
    sfTexture *exit_t;
    sfVector2f pos;
    sfText *menu_name;
    sfVector2f pos_name;
    const char *name;
    sfFont *name_texture;
} menu;

void my_putchar(char);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char *str);
int my_printf(char *str, ...);
int my_put_nbr_octa(int nb);
int my_put_nbr_u(int nb);
int my_put_nbr_bin(int nb);
int my_put_nbr_hexa(int nb);
int first_flags(char *str, int counter, va_list list);
int second_flags(char *str, int counter, va_list list);
int third_flags(char *str, int counter, va_list list);

#endif /* MY_H_ */
