/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 12:16:44 by kprasol           #+#    #+#             */
/*   Updated: 2017/12/11 13:49:19 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_relations(const char *s)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	return (ft_check_relations_more(s, i, counter));
}

int		ft_check_more(const char *s, int i, int counter, int c)
{
	while (s[i])
	{
		if (s[i] == 46 || s[i] == 35 || s[i] == 10)
		{
			if ((i % 21 != 4 && i % 21 != 9 && i % 21 != 14 && i % 21 != 19 &&
						i % 21 != 20) && s[i] == '\n')
				return (0);
			if (s[i] == '#')
			{
				counter++;
				c++;
			}
		}
		else
			return (0);
		if ((i % 21 == 19) && (counter != 4))
			return (0);
		else if ((i % 21 == 19) && (counter == 4))
			counter = 0;
		i++;
	}
	if (c % 4 != 0 || c == 0)
		return (0);
	return (c / 4);
}

int		ft_check(const	char *s)
{
	int	i;
	int counter;
	int c;

	i = 0;
	counter = 0;
	c = 0;
	return (ft_check_more(s, i, counter, c));
}

int		ft_reader(const char *file)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE];
	int		size;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	ret = read(fd, buf, BUF_SIZE);
	if ((ret + 1) % 21 != 0)
		return (0);
	buf[ret] = '\0';
	size = ft_check(buf);
	if (size == 0 || !ft_check_relations(buf))
		return (0);
	if (close(fd) == -1)
		return (-1);
	map_size(ft_split_array(buf));
	return (1);
}

int		main(int argc, char **argv)
{
	int read;

	if (argc != 2)
	{
		ft_putstr("./fillit source_file\n");
		return (0);
	}
	read = ft_reader(argv[1]);
	if (!read)
		ft_putstr("error");
	return (1);
}
