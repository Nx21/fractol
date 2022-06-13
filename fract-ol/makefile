# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 16:59:22 by nhanafi           #+#    #+#              #
#    Updated: 2022/05/16 19:07:23 by nhanafi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = control.c draw.c main.c utils.c equation.c opration.c libft.c
OBJ = ${SRC:.c=.o}
GCC = gcc -Wall -Wextra -Werror
NAME = fractol

all: $(NAME)

$(NAME): $(OBJ) 
	$(GCC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c fractol.h
	$(GCC) -c $< -o $@

bonus: all

clean:
	rm -rf $(OBJ)
	
fclean: clean
	rm -rf $(NAME)
	
re: fclean all