# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 16:35:37 by tbrulhar          #+#    #+#              #
#    Updated: 2022/06/10 14:06:56 by tbrulhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS         =	src/main/main.c\
				src/builtin/cd.c\
				src/builtin/is_builtin.c\
				src/pipex/access_path.c\
				src/pipex/child_execution.c\
				src/pipex/error_file.c\
				src/pipex/ft_split.c\
				src/pipex/parsing_command.c\
				src/pipex/pipex_main.c\
				src/pipex/waitpid.c\
				src/pipex/one_command_exec.c\
				src/pipex/files_redirection.c\
				
OBJS         = ${SRCS:.c=.o}

NAME         = minishell

AR             = ar rcs

GCC            = gcc

RM             = rm -f

CFLAGS         = -Wall -Wextra -Werror

LBFT_PATH    =     ./libft/

FRAMLIBS    =     -L ${LBFT_PATH} -lft
all:         $(NAME)

.c.o:
			$(GCC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME):     $(OBJS)
			@$(MAKE) -C $(LBFT_PATH)
			$(GCC) $(OBJS) $(CFLAGS) -I ${LBFT_PATH} -o $(NAME) $(FRAMLIBS)

clean:
			${RM} ${OBJS}
			@$(MAKE) -C $(LBFT_PATH) clean

fclean:     clean
			${RM} ${NAME}
			@$(MAKE) -C $(LBFT_PATH) fclean

re: fclean all