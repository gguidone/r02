#include "header.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
   if (argc > 3 || argc == 1)
    {
        ft_putstr("Input error\n");
        return (0);
    }
    if (!(ft_str_is_numeric(argv[1])))
    {
        ft_putstr("Error\n");
        return (0);
    }
    if (str_is_zero(argv[1]))
    {
        printf("num : %s\n", "0");
        return (0);
    }
    divide_string(argv[1]);

    return (0);
}
//1000000000000000000000000000000000000 lunghezza: 37
//123567834533343534343434343434343343445656767811
