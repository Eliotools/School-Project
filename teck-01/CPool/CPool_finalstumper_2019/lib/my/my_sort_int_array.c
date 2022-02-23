/*
** EPITECH PROJECT, 2024
** day04
** File description:
** Created by Leo Fabre
*/

void my_swap(int *a, int *b);

void my_bubblesort(int *array, int size, int i, int j)
{
    for (j = 0; j < (size - i - 1); ++j) {
        if (array[j] > array[j + 1])
            my_swap(&array[j], &array[j + 1]);
    }
}

void my_sort_int_array(int *array, int size)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < (size - 1); i++) {
        my_bubblesort(array, size, i, j);
    }
}
