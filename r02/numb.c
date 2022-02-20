#include "header.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int str_is_zero(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] != '0')
            return (0);
        i++;
    }
    return (1);
}

char *associate_base_ten(int distance)
{
    char *str = malloc(distance + 2);
    int i;

    i = 1;
    str[0] = '1';
    while (i < distance + 1)
    {
        str[i] = '0';
        i++;
    }
    str[i] = '\0';
    return (str);
}

char *associate_three(int distance, char c)
{
    char *str = malloc(distance + 2);
    int i;

    i = 1;
    str[0] = c;
    while (i < distance + 1)
    {
        str[i] = '0';
        i++;
    }
    str[i] = '\0';
    return (str);
}

char *unite_two(char c1, char c2)
{
    char *str;

    str = malloc(3);
    str[0] = c1;
    str[1] = c2;
    str[2] = '\0';
    return (str);
}

void    subdivide(char *str)
{
    int distance;
    int i;

    i = 0;
    distance = ft_strlen(str) - 1;
    while (str[i] != '\0')
    {
        if (i == 1 && str[i] == '1')
        {
            if (!str_is_zero(unite_two(str[i], str[i + 1])))
                printf("num : %s\n",  unite_two(str[i], str[i + 1]));
        }
        else
        {
            if (!str_is_zero((associate_three(distance, str[i]))))
                printf("num : %s\n", (associate_three(distance, str[i])));           
        }

        i++;
        distance--;
    }
}


void    divide_string(char *str)
{
    char *temp;
    int i;
    int j;
    int distance;

    i = 0;
    if (ft_strlen(str) % 3 == 0)
    {
        while (str[i] != '\0')
        {
            j = 0;
            temp = malloc(4);
            while (j < 3)
            {
                temp[j] = str[j + i];
                j++;
            }
            temp[j] = '\0';
            i += 3;
            distance = ft_strlen(str) - i;
            subdivide(temp);
            if (distance != 0 && ft_strcmp("000", temp))
                printf("distanza: %s\n", (associate_base_ten(distance))); 
        }
    }
    if (ft_strlen(str) % 3 == 1)
    {
        temp = malloc(2);
        temp[0] = str[0];
        temp[1] = '\0';
        str++;
        distance = ft_strlen(str);
        subdivide(temp);
        if (distance != 0)
            printf("distanza: %s\n", (associate_base_ten(distance))); 
        divide_string(str);
    }
    if (ft_strlen(str) % 3 == 2)
    {
        temp = malloc(3);
        if (i == 0 && str[i] == '1')
        {
            if (!str_is_zero(unite_two(str[i], str[i + 1])))
                printf("num : %s\n",  unite_two(str[i], str[i + 1]));
            distance = ft_strlen(str + 2);
            if (distance != 0)
                printf("distanza: %s\n", (associate_base_ten(distance))); 
        }
        else
        {
            temp[0] = str[0];
            temp[1] = str[1];
            temp[2] = '\0';
            distance = ft_strlen(str + 2);
            subdivide(temp);
            if (distance != 0)
                printf("distanza: %s\n", (associate_base_ten(distance))); 
        }
        str += 2;
        divide_string(str);
    }
}