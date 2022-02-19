#include "header.h"
#include <stdlib.h>
#include <unistd.h>

void final_split(char *str, int z)
{
    int i;
    int j;
    char *temp;

    i = 0;
    temp = (char *)malloc(ft_strlen(str) - i);
    j = 0;
    while (j < z)
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
    free(temp);
}

int teenager(char a)
{
    if (a == '1')
    {
        return (1);
    }
    
    return (0);   
}

void read_num_threesome(char *str)
{
    int i;
    int j;
    char *temp;

    i = 0;
    while (i < 3)
    {
        if (str[i] != '0')
        {
            temp = (char *)malloc(ft_strlen(str) - i);
            j = 0;
            if(i == 1 && teenager(str[i])) //da scrivere per la questione 10 to 19
            {
                final_split(str + 1, 2);
                i++;
            }
            else
            {
                temp[j] = str[j + i];
                j++;
                while (j < ft_strlen(str) - i)
                {
                    temp[j] = '0';
                    j++;
                }
            }
            temp[j] = '\0';
            ft_putstr(temp);
            ft_putchar('\n');
        }
        i++;
        free(temp);
    }
}

void split_str(char *str)
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
        read_num_threesome(temp);
        i = i + 3;
        free(temp);
    }
}

char *find_head(char *str)
{
    int i;
    int j;
    char *first;
    j = 0;
    i = ft_strlen(str) % 3;
    first = (char *)malloc(ft_strlen(str) + 1);
    if (i > 0)
    {
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
    }
    first[j] = '\0';
    return (first);    
}