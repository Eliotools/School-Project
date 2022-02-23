#include <stdio.h>

int main(int ac, char **av)
{
    int j = 0;
    
    for (int i = 0; av[1][i] != '\0'; i++, j++)
    {
        if (av[1][i] != av[2][j])
            j = 0;
        if (av[2][j] == '\0') {
            printf("GG\n");
            return 1;
        }
    }
    printf("loupé\n");
    return 84;
}
