#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>

int str_is_zero(char *str);
void    divide_string(char *str);
void    subdivide(char *str);
char *associate_three(int distance, char c);
char *associate_base_ten(int distance);
char *unite_two(char c1, char c2);
int ft_strlen(char *str);
void ft_putstr(char *str);
int	ft_strcmp(char *s1, char *s2);

#endif