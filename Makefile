#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/14 10:36:49 by vrybchyc          #+#    #+#              #
#    Updated: 2017/10/14 10:38:35 by vrybchyc         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls

SRC = 	add_route.c\		

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[32;1mmake libft...\033[0m"
	@make -C libft/
	@echo "\033[32;1mmake \033[0m"
	@gcc $(FLAGS) -o $(NAME) -L libft/ -lft $(OBJ)

.c.o:
	@gcc $(FLAGS) -c $< -o $@

clean:
	@echo "\033[31mRemoving objects...\033[0m"
	@rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@echo "\033[31mRemoving...\033[0m"
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

norm:
	norminette $(SRC)
