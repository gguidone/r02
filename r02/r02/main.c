#include "header.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
   if (argc > 3 || argc == 1)
    {
        ft_putstr("Input error\n");
        return (0);
    }
    if (!(argv[1][0] >= '0' && argv[1][0] <= '9'))
    {
        ft_putstr("Error\n");
        return (0);
    }
    find_head(argv[1]);
    split_str(argv[1]);
    return (0);
}
//1000000000000000000000000000000000000
//123567834533343534343434343434343343445656767811
