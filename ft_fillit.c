/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 14:27:33 by etugoluk          #+#    #+#             */
/*   Updated: 2017/12/11 13:00:19 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		test(char **map, struct s_coord c, char *value, int counter)
{
	int i;
	int count;
	int j;

	i = 0;
	count = 0;
	while (i < 19)
	{
		if ((value[i] == '#') && count++ == 0)
			j = i;
		if ((value[i] == '#') &&
			(((int)ft_strlen(map[0]) - 1 < c.y + i / 5 - j / 5)
			|| ((int)ft_strlen(map[0]) - 1 < c.x + i % 5 - j % 5)))
			return (0);
		if ((value[i] == '#') && (EXPR == '.'))
		{
			EXPR = counter + 65;
			i++;
		}
		else if ((value[i] == '#') && (EXPR != '.'))
			return (0);
		else if (value[i] != '#')
			i++;
	}
	return (1);
}

void	ft_cleanmap(char **map, int k)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == k + 65)
				map[i][j] = '.';
			j++;
		}
		i++;
		j = 0;
	}
}

int		function(char **map, char **t, int number)
{
	struct s_coord c;

	c.x = 0;
	c.y = 0;
	if (!t[number])
		return (1);
	while (map[c.y])
	{
		if (test(map, c, t[number], number) && function(map, t, number + 1))
			return (1);
		else
		{
			ft_cleanmap(map, number);
			if (map[c.y][c.x + 1] == '\0')
			{
				c.y++;
				c.x = 0;
			}
			else
				c.x++;
		}
	}
	return (0);
}

void	map_size(char **t)
{
	int		i;
	char	**map;

	map = ft_newmap(2);
	i = 2;
	while (!function(map, t, 0))
	{
		free(map);
		map = ft_newmap(++i);
	}
	ft_print_array(map);
}
