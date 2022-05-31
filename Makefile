# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 00:46:25 by bgoncalv          #+#    #+#              #
#    Updated: 2022/05/31 18:47:14 by tbrulhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S		= src/
O		= objs/
I		= includes/

NAME	= minishell

SRCS	=	main/main.c\
			pipex/waitpid.c\
			pipex/error_file.c\
			pipex/access_path.c\
			pipex/child_execution.c\
			pipex/ft_split.c\
			pipex/parsing_command.c\
			pipex/pipex_main.c\
			builtin/cd.c\

CC		= gcc

CFLAGS	+= -Wall -Wextra -Werror -g

CFLAGS	+= -I$I
SRCS	:= $(foreach file,$(SRCS),$S$(file))
OBJS	= $(SRCS:$S%=$O%.o)
DEPS	= $(SRCS:$S%=$D%.d)
LBFT_PATH    =     ./libft/
LFLAGS		= -L./libft
RM		= /bin/rm -rf

.PHONY: all clean fclean re test

create_dir_objs:
	@mkdir objs
	@mkdir objs/main
	@mkdir objs/pipex
	@mkdir objs/builtin

all: $(NAME)
$O: create_dir_objs

$(OBJS): | $O

$(OBJS): $O%.o: $S%
		@echo "Compiling $^: "
		@$(CC) $(CFLAGS) -c $< -o $@
		@$(MAKE) -C ./libft
		@echo "✓"

$D:
		@mkdir $@
		@mkdir objs/main

$(NAME): $(OBJS)
		@echo "Assembling $(NAME)"
		@$(CC) $^ -o $@

clean:
		@echo "Cleaning up..."
		@$(RM) $D $O

fclean: clean
		@echo "Everything!"
		@$(RM) $(NAME)

re: fclean all

test: $(NAME)
	./$(NAME)