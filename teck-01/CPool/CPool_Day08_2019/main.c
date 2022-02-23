#include <stdio.h>
char **my_str_to_word_array(char *str);


int main(void)
{
    char **str = my_str_to_word_array("ls -l | cat -e > list ; bite >> eliot");
    for (int i = 0; str[i]; i++)
        printf("%s\n",str[i]);
}
