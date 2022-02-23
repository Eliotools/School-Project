/*
** EPITECH PROJECT, 2019
** phoenix
** File description:
** Moi
*/

int recursive_power(int nb, int p)
{
    int calc = 1;

    for (; p != 0; p--)
    {
        calc = calc * nb;
    }
    return (calc);
}