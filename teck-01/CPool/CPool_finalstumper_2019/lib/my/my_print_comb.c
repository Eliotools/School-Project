/*
** EPITECH PROJECT, 2024
** day03
** File description:
** Created by Leo Fabre
*/

void my_putchar(char);

void print_digits(int first, int sec, int third)
{
    my_putchar(first+'0');
    my_putchar(sec+'0');
    my_putchar(third+'0');
    if (!((first == 7) && (sec == 8) && (third == 9))){
        my_putchar(',');
        my_putchar(' ');
    }
}

void new_hundred(int *first, int *sec, int *third)
{
    (*first)++;
    (*sec) = 1;
    if ((*sec) <= (*first))
        (*sec) = (*first) + 1;
    (*third) = 2;
    if ((*third) < (*sec))
        (*third) = (*sec);
}

int my_print_comb(void)
{
    int first = 0;
    int sec = 1;
    int third = 1;

    while (first <= 7) {
        while (sec <= 8) {
            while (++third <= 9) {
                print_digits(first, sec, third);
            }
            sec++;
            third = sec;
        }
        new_hundred(&first, &sec, &third);
    }
    return 0;
}
