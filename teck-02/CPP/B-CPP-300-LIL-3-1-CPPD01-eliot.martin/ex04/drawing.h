/*
** EPITECH PROJECT, 2024
** CPool_Day07_2019
** File description:
** Created by moi
*/

#include <string.h>
#include <stdint.h>


#ifndef DRAWING_H
#define DRAWING_H


typedef struct point {
    uint32_t x;
    uint32_t y;
} point_t;


void draw_square(uint32_t **img, const point_t *origin,
size_t size, uint32_t color);
#endif