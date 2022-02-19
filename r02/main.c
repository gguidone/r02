#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

char *find_head(char *str)
{
    int i;
    int j;
    char *first;
    j = 0;
    i = ft_strlen(str) % 3;
    first = (char *)malloc(ft_strlen(str) + 1);
    while (j < i)
    {
        first[j] = str[j];
        j++;
    }
    while (j < ft_strlen(str))
    {
        first[j] = '0';
        j++;
    }
    first[j] = '\0';
    return (first);
}

void read_num(char *str)
{
    int i;
    int j;
    char *temp;

    i = ft_strlen(str) % 3;
    while (str[i] != '\0')
    {
        temp = (char *)malloc(ft_strlen(str) - i);
        j = 0;
        while (j < 3)
        {
            temp[j] = str[j + i];
            j++;
        }
        while (j < ft_strlen(str) - i)
        {
            temp[j] = '0';
            j++;
        }
        temp[j] = '\0';
        ft_putstr(temp);
        ft_putchar('\n');
        i = i + 3;
    }
    free(temp);
}

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
    read_num(argv[1]);
    return (0);
}