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
#include "struct.h"
#include "stdlib.h"
#include <math.h>

int create_my_square_blue(struct moving_square *my_square,
                                                int x_pos, int y_pos, int size)
{
    my_square->c = sfColor_fromRGBA(20, 255, 150, 100);
    my_square->width = size;
    my_square->height = size;
    my_square->speed = 10;
    my_square->my_pos.x = x_pos;
    my_square->my_pos.y = y_pos;
    my_square->my_mov.x = 0;
    my_square->my_mov.y = 0;
    my_square->image = sfImage_createFromColor(size, size, my_square->c);
    my_square->texture = sfTexture_createFromImage(my_square->image, NULL);
    my_square->sprite = sfSprite_create();
    sfSprite_setTexture(my_square->sprite, my_square->texture, sfTrue);
    return (0);
}

int create_my_square_red(struct moving_square *my_square,
int x_pos, int y_pos, int size)
{
    my_square->c = sfColor_fromRGBA(255, 25, 150, 255);
    my_square->width = size;
    my_square->height = size;
    my_square->speed = 10;
    my_square->my_pos.x = x_pos;
    my_square->my_pos.y = y_pos;
    my_square->my_mov.x = 0;
    my_square->my_mov.y = 0;
    my_square->image = sfImage_createFromColor(size, size, my_square->c);
    my_square->texture = sfTexture_createFromImage(my_square->image, NULL);
    my_square->sprite = sfSprite_create();
    sfSprite_setTexture(my_square->sprite, my_square->texture, sfTrue);
    return (0);
}

int create_my_line(struct moving_square *my_square, int x_pos,
int y_pos, int size)
{
    my_square->c = sfColor_fromRGBA(0, 0, 255, 250);
    my_square->width = size;
    my_square->height = 200;
    my_square->speed = 1;
    my_square->my_pos.x = x_pos;
    my_square->my_pos.y = y_pos;
    my_square->my_mov.x = 0;
    my_square->my_mov.y = 0;
    my_square->image = sfImage_createFromColor(size, 200, my_square->c);
    my_square->texture = sfTexture_createFromImage(my_square->image, NULL);
    my_square->sprite = sfSprite_create();
    sfSprite_setTexture(my_square->sprite, my_square->texture, sfTrue);
    return (0);
}

void draw_my_square(struct moving_square *my_square,
sfRenderWindow* window, int acc, int speed)
{
    sfRenderWindow_drawSprite(window, my_square->sprite, NULL);
    my_square->my_mov.x += speed + speed * acc;
    my_square->my_mov.y += speed + speed * acc;
    if (sfSprite_getPosition(my_square->sprite).y >= 1080 - 120 ||
        sfSprite_getPosition(my_square->sprite).y < 0){
        my_square->my_pos.y = 0;
        my_square->my_mov.y = 0;
     }
    if (sfSprite_getPosition(my_square->sprite).x >= 1920 - 120 ||
        sfSprite_getPosition(my_square->sprite).x  < 0){
        my_square->my_pos.x = 0;
        my_square->my_mov.x = 0;
     }
    sfSprite_setPosition(my_square->sprite, my_square->my_pos);
    sfSprite_move(my_square->sprite, my_square->my_mov);
}
