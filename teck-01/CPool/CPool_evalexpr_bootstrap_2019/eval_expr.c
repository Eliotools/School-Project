/*
** EPITECH PROJECT, 2019
** eval expr
** File description:
** calcul
*/

int  main(int ac , char **av)
{
    if (ac == 2) {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
        return  (0);
    }
    return  (84);
}
