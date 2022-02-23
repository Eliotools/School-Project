/* 
** EPITECH PROJECT, 2019
** calculatron
** File description:
** les calculs
*/

int plus (int I, int II)
{
    int resulty = I+II;
    return(resulty);
}

int moinss(int I, int II)
{
    int resulty = I-II;
    return(resulty);
}

int modulo(int I, int II)
{
    int resulty = I%II;
    return(resulty);
}

int divi(int I, int II)
{
    int resulty = I/II;
    return(resulty);
}

int foie(int I, int II)
{
    int resulty = I*II;
    return(resulty);
}

int calculatron (int I, int II, char signe)
{
    int resulty = 0;

    if (signe == '+')
        resulty = (plus(I,II));
    if (signe == '-')
        resulty = (moinss(I,II));
    if (signe == '%')
        resulty = (modulo(I,II));
    if (signe == '/')
        resulty = (divi(I,II));
    if (signe == '*')
        resulty = (foie(I,II));
    return(resulty);
}