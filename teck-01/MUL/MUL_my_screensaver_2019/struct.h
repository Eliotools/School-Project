/*
** EPITECH PROJECT, 2019
** screensaver
** File description:
** Moi
*/

struct moving_square // La structure du carré
{
    int width;
    int height;
    int speed;
    sfColor c;
    sfVector2f my_pos;
    sfTexture * texture;
    sfImage * image;
    sfSprite *sprite;
    sfVector2f my_mov;
};