# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 10:40:50 by pyammoun          #+#    #+#              #
#    Updated: 2022/10/30 20:41:45 by pyammoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	${addprefix src/parsing/, parsing.c linklist.c utils.c sortcommand.c \
std.c checkforerror.c promptparser.c spliter.c struct_init.c string_trimmer.c error.c environnement.c find_file.c}
SRCS += ${addprefix src/builtin/, cd.c is_builtin.c export.c unset.c env.c echo.c pwd.c utils_builtin.c exit.c utils_builtin_2.c \
echo_utils.c unset_utils.c export_utils.c}
SRCS += ${addprefix	src/main/, main.c}
SRCS += ${addprefix	src/pipex/, access_path.c ft_split.c pipex_main.c child_execution.c one_command_exec.c waitpid.c error_file.c parsing_command.c allocation.c utils_pipex.c}
HEADERFILES := include/include.h
BUILD_DIR 	?= ./build
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
NAME        =	minishell
AR    		=	ar rcs
GCC       	=	gcc 
RM       	=	rm -f
CFLAGS    	=	-Wall -Wextra -Werror -g
INC_FLAGS 	:= -Ilibft/incs 
LIBS 		:= -Llibft -lft -lreadline
INC_FLAGS 	+= -I$(HOME)/.brew/opt/readline/include
LIBS 		+= -L$(HOME)/.brew/opt/readline/lib
INC_DIR 	?= ./includes
INC_FLAGS 	+= $(addprefix -I,$(INC_DIRS))
LBFT_PATH	=	./libft/
FRAMLIBS  	=    -L ${LBFT_PATH} -lft
READLIB 	:=	-I $(HOME)/.brew/opt/readline/include
LIB    		:= libft/libft.a
LIB 		=  -lreadline -L $(HOME)/.brew/opt/readline/lib  

all:	$(NAME)

%.c.o: $(HEADERFILES)	
	$(GCC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.c.o: %.c
	@echo Compiling $@
	@mkdir -p $(dir $@)
	@$(CC) -c  $(CFLAGS) $(INC_FLAGS) $< -o $@

$(NAME): $(LIB) $(OBJS)
		@echo Linking $@
		@$(CC) $(CFLAGS) $(INC_FLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(LIB):
		@$(MAKE) -C libft
		@echo Libft done

clean:
	${RM} ${OBJS}
	@$(MAKE) -C $(LBFT_PATH) clean

fclean:        clean
	${RM} ${NAME}
	@$(MAKE) -C $(LBFT_PATH) fclean

re:			fclean all

.PHONY:		all clean fclean re
