#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/25 18:32:51 by etugoluk          #+#    #+#              #
#    Updated: 2017/10/25 18:33:27 by etugoluk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRCS = ft_checker.c \
		ft_fillit.c \
		ft_additional.c \

LIB = -L libft/ -lft
OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

libft: 
	make -C ./libft

$(NAME): libft $(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(NAME) $(LIB) -I ./

clean:
	/bin/rm -f *.o
	make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ./libft fclean

re: fclean all

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $< -I libft/

.PHONY: all clean fclean re libft

.NOTPARALLEL: all clean fclean re libft