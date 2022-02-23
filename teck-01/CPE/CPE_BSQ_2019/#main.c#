/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** BSQ
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void compte_collum(char *buffer)
{
    int nbr_collum = 3;
    int j = 0;
    int clone = 0;
    int compte = 0;
    int memor = 0;

    for (; buffer[nbr_collum] != '\n'; nbr_collum++);
    while (buffer[j] != '\0') {
        for (; buffer[j] == '.'; j++, compte++);
        if (compte > memor) {
            clone = j - compte;
            memor = compte;
            buffer[clone] = 'e';
            buffer[clone+nbr_collum+1] = 'i';
        }
        j++;
        compte = 0; 
    }
    my_putstr(buffer);
}

int find_first_int(char *buffer)
{
    int i = 0;
    char j[10000];

    while (buffer[i] >= '0' && buffer[i] <= '9')
    {
        j[i] = buffer[i];
        i++;
    }
return (my_getnbr(j));
}

int fs_open_file(char const *filepath)
{
    int i;
    int nb_line;
    int compte;
    char buffer[20000];

    i = open(filepath, O_RDONLY);
    if (i == -1){
        return (84);
    } else {
        compte = read(i, buffer, 20000);
    }
    nb_line = find_first_int(buffer);
    compte_collum(buffer);
    close(i);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        return (84);
    }
    fs_open_file(argv[1]);
}