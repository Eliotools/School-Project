/*
** EPITECH PROJECT, 2019
** convert
** File description:
** lib
*/
int power(int nb, int pow);

int converteur(int nb, int base)
{
    int mod = 1;
    int final = 0;
    int size = 0;

    while (nb != 0)
    {
        mod = nb % base;
        nb = nb / base;
        final += mod * power(10 , size);
        size++;
    }
    return (final);
}

int power(int nb, int pow)
{
    int nbr = 1;
    while (pow != 0) {
        nbr = (nbr * nb);
        pow--;
    }
    return (nbr);
}