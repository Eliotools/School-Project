/*
** EPITECH PROJECT, 2020
** main
** File description:
** Moi
*/

#include "drawing.h"
#include "bitmap.h"

void draw_square(uint32_t **img, const point_t *origin,
size_t size, uint32_t color)
{
    uint32_t y;
    uint32_t x;
    int lengthy = origin->y + size;
    int lengthx = origin->x + size;

    for (y = origin->y; y < lengthy; ++y) {
        for (x = origin->x; x < lengthx; ++x) {
            img[y][x] = color;
        }
    }
}