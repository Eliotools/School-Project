/*
** EPITECH PROJECT, 2019
** screensaver
** File description:
** Moi
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/System/Vector2.h>
#include "include/my.h"
#include "stdlib.h"
#include "struct.h"
#include <math.h>
//malloc struct


void draw_my_square_rev(struct moving_square *my_square,
sfRenderWindow* window, int acc, int speed)
{
    sfRenderWindow_drawSprite(window, my_square->sprite, NULL);
    my_square->my_mov.x += speed + speed * acc;
    my_square->my_mov.y += speed + speed * acc;
    if (sfSprite_getPosition(my_square->sprite).y < 0){
        my_square->my_pos.y = 1080 - 121;
        my_square->my_mov.y = 0;
}
    if (sfSprite_getPosition(my_square->sprite).x  < 0){
        my_square->my_pos.x = 1920 - 121;
        my_square->my_mov.x = 0;
}
    sfSprite_setPosition(my_square->sprite, my_square->my_pos);
    sfSprite_move(my_square->sprite, my_square->my_mov);
}

int my_ftanim(void)
{
    sfVideoMode screen = {1920, 1080, 32};
    sfRenderWindow* window;
    int nb_square = 5;
    int speed = 1;
    int curr = 0;
    struct moving_square *my_square = malloc(sizeof(struct moving_square) *
    (nb_square));
    for (curr = 0; curr < nb_square; curr++)
        create_my_square_blue(&(my_square[curr]), 14000 + (curr * 10), 600 +
        (curr * 100), 80 + curr);
    curr = 0;
    window = sfRenderWindow_create(screen, "ScreenSaver", sfResize
        | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)){
        sfRenderWindow_clear(window, sfBlack);
        for (curr = 0; curr < nb_square; curr++)
            draw_my_square(&(my_square[curr]), window, curr, speed);
        sfRenderWindow_display(window);
    }
}

int my_thdanim(void)
{
    sfVideoMode screen = {1920, 1080, 32};
    sfRenderWindow* window;
    int nb_square = 5;
    int speed = -4;
    int curr = 0;
    struct moving_square *my_square = malloc(sizeof(struct moving_square) *
    nb_square);
    for (curr = 0; curr < nb_square; curr++)
        create_my_square_red(&(my_square[curr]), 1400 + curr * 10, 600 -
        curr * 10, 70 + curr * 5);
    curr = 0;
    window = sfRenderWindow_create(screen, "ScreenSaver", sfResize
    | sfClose, NULL);
    while (sfRenderWindow_isOpen(window)){
        sfRenderWindow_clear(window, sfBlack);
        for (curr = 0; curr < nb_square; curr++)
            draw_my_square_rev(&(my_square[curr]), window, curr, speed);
        sfRenderWindow_display(window);
    }
}

int my_sdanim(void) // Deuxième animation
{
    sfVideoMode screen = {1920, 1080, 32};
    sfRenderWindow* window;
    int nb_square = 10;
    int curr = 0;
    int speed = 1;
    struct moving_square *my_square = malloc(sizeof(struct moving_square)
    * nb_square);
    for (curr = 0; curr < nb_square; curr++)
        create_my_line(&(my_square[curr]), 30 + (curr * 100), 60 +
        (curr * 200), 5);
    window = sfRenderWindow_create(screen, "bite", sfResize | sfClose, NULL);
    while (sfRenderWindow_isOpen(window)){
        speed--;
        if (speed == 0)
            speed = 5;
        sfRenderWindow_clear(window, sfRed);
        for (curr = 0; curr < nb_square; curr++)
            draw_my_square(&(my_square[curr]), window, curr, speed);
        sfRenderWindow_display(window);
    }
}

int my_sortanim(int animation) //Regarde quelle animation c'est
{
    int (*function[]) (void) = {my_ftanim, my_sdanim, my_thdanim};
    int max_animation = 3;

    if (animation > max_animation)
        return (84);
    return (function[animation - 1]());
}