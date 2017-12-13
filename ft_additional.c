/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additional.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:51:53 by kprasol           #+#    #+#             */
/*   Updated: 2017/12/08 17:01:16 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		checkdots(char *s, int j)
{
	int i;

	i = ((j - 1) / 5) * 5;
	while (i < j)
	{
		if (s[i] == '#')
			return (1);
		i++;
	}
	return (0);
}

char	**ft_split_array(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (i % 21 == 20)
			s[i] = '*';
		i++;
	}
	return (ft_strsplit(s, '*'));
}

char	**ft_newmap(int size)
{
	int		i;
	char	**map;

	i = 0;
	map = (char**)malloc(sizeof(char*) * (size + 1));
	while (i < size)
	{
		map[i] = ft_strnew(size);
		ft_memset(map[i], '.', sizeof(char) * size);
		i++;
	}
	map[i] = NULL;
	return (map);
}

int		ft_check_relations_more(const char *s, int i, int counter)
{
	while (s[i])
	{
		if ((s[i] == '#') && (!counter))
			if ((s[i + 1] != '#') && (s[i + 5] != '#'))
				return (0);
		if ((s[i] == '#'))
			counter++;
		if ((s[i] == '#') && (counter > 1) &&
			(s[i - 1] != '#') && (s[i - 5] != '#'))
		{
			if (s[i + 1] == '#')
			{
				if ((s[i + 1 - 5] != '#') && (s[i + 1 + 1] != '#'))
					return (0);
			}
			else
				return (0);
		}
		if (counter == 4)
			counter = 0;
		i++;
	}
	return (1);
}
