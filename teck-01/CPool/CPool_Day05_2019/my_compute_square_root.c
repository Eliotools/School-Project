/*
** EPITECH PROJECT, 2019
** my_compute_square_root
** File description:
** square
*/

int my_compute_square_root (int nb)
{
    int x = 2;
    int y;
    while (x != 99999)
    {
        y = x*x;
        if (y == nb)
        {
            break;
        }
        x++;
    }
    if (y == nb)
        return (x);
    else
        return (0);
}
