/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassani <ohassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:56:40 by ohassani          #+#    #+#             */
/*   Updated: 2024/04/21 12:56:59 by ohassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	d;

	i = 0;
	d = 0;
	while ((s2[i] != '\0' && s1[i] != '\0'))
	{
		if (s1[i] != s2[i])
			d = s1[i] - s2[i];
		i++;
	}
	return (d);
}

int	ft_strlen1(char *s)
{
	int	c;

	c = 0;
	while (s[c] != '\0')
		c++;
	return (c);
}

void	print_error(char *str)
{
	write(2, str, ft_strlen1(str));
	exit(1);
}

int	main(int ac, char **av)
{
	parsingall(ac, av);
}
