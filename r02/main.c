#include <unistd.h>

ft_putchar(char c)
{
    write(1, &c, 1);
}

ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc > 3)
    {
        ft_putstr("Input error\n");
        return (0);
    }
    if (!(argv[1][0] >= '0' && argv[1][0] <= '9'))
    {
        ft_putstr("Error\n");
        return (0);
    }
    return (0);
}