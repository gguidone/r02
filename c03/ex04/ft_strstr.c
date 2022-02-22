/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguidone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:31:02 by gguidone          #+#    #+#             */
/*   Updated: 2022/02/15 18:51:05 by gguidone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	len(char *str)
{
	int	cont;

	cont = 0;
	while (str[cont] != '\0')
		cont++;
	return (cont);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		cont;
	int		i;
	int		target;

	i = 0;
	cont = 0;
	target = len(to_find);
	if (target == 0)
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[cont])
			cont++;
		else
			cont = 0;
		if (cont == target)
			return (&str[i - cont + 1]);
		i++;
	}
	return (0);
}
