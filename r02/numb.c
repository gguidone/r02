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
    parse_to_search(temp);
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
        temp = (char *)malloc(ft_strlen(str) - i);
        if (str[i] != '0')
        {
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
            parse_to_search(temp);
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

void find_head(char *str)
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

    if (!(first[0] != '1' && first[1] != '0'))
    {
        parse_to_search(first);
    } 
    if(ft_strlen(first) > 0)
        split_head(first);
}

void split_head(char *str)
{
    if (str[0] != '1' && str[1] != '0')
    {
        int i;
        int j;
        char *temp;

        i = 0;
        while (i < 2)
        {
            temp = (char *)malloc(ft_strlen(str) - i);
            j = 0;
            temp[j] = str[j + i];
            j++;
            while (j < ft_strlen(str) - i)
            {
                temp[j] = '0';
                j++;
            }
            temp[j] = '\0';
            parse_to_search(temp);
            free(temp);
            i++;
        }
    }
}

void parse_to_search(char *str)
{
    if (ft_strlen(str) > 1)
    {
        int i;
        int j;

        j = 1;
        i = 0;
        while (str[i] != '0')
            i++;
        char *dec = (char *)malloc(i + 1);
        char *zeros = (char *)malloc(ft_strlen(str) - i + 2);
        zeros[0] = '1';
        while (str[i] != '\0')
        {
            zeros[j] = str[i];
            i++;
            j++;
        }
        zeros[j] = '\0';
        i = 0;
        while (str[i] != '0')
        {
            dec[i] = str[i];
            i++;
        }
        dec[i] = '\0';
        ft_putstr(dec);
        ft_putchar('-');
        ft_putstr(zeros);
        ft_putchar('\n');
        free(dec);
        free(zeros);
    }
    else 
        ft_putstr(str);
}