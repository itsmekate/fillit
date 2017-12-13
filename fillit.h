/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprasol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:54:05 by kprasol           #+#    #+#             */
/*   Updated: 2017/12/11 12:58:04 by kprasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include "libft.h"
# define BUF_SIZE 546
# define EXPR (map[c.y + i / 5 - j / 5][c.x + i %  5 - j % 5])

struct	s_coord
{
	int	x;
	int	y;
};

void	ft_cleanmap(char **map, int k);
int		function(char **map, char **t, int number);
void	map_size(char **t);
int		test(char **map, struct s_coord c, char *value, int counter);
char	**ft_split_array(char *s);
int		ft_check_relations(const char *s);
int		ft_check(const	char *s);
char	**ft_newmap(int size);
int		checkdots(char *s, int j);
void	fillit(char **map, char **s);
int		ft_reader(const char *file);
int		ft_check_relations_more(const char *s, int i, int counter);
#endif
