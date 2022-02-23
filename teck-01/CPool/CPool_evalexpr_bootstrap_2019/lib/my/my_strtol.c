/*
** EPITECH PROJECT, 2019
** my_strtol
** File description:
** char into int
*/
void my_putchar (char c);
int my_strlen(char  const *str);
int my_put_nbr (int nb);

int my_strtol(char *past, int marque)
{
    int futur = 0;
    int counter = 1;
    int marqueur = 0;
    int stop = 0;
    int pointer = my_strlen(past) - 1;
    while (pointer >= stop)
    {
        futur += ((past[pointer]- '0' ) * counter);
        pointer--;
        counter = counter * 10;
    }
    if (marque != 0)    
        futur = futur * -1;
    return(futur);
}