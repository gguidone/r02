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
    char *first = find_head(argv[1]);
    ft_putstr(first);
    ft_putchar('\n');
    split_str(argv[1]);
    return (0);
}