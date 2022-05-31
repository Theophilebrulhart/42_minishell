SRCS	=	ft_striteri.c\
			ft_strmapi.c\
  			ft_putnbr_fd.c\
  			ft_putendl_fd.c\
   			ft_putstr_fd.c\
	 		ft_putchar_fd.c\
	  		ft_split.c ft_itoa.c\
	   		ft_strtrim.c\
	   		ft_substr.c\
		 	ft_strjoin.c\
		  	ft_memcmp.c\
		   	ft_strchr.c\
		    ft_strdup.c\
			ft_strlcat.c\
			ft_strrchr.c\
			ft_strncmp.c\
			ft_strnstr.c\
			ft_isalpha.c\
			ft_isdigit.c\
			ft_isalnum.c\
			ft_isascii.c\
			ft_isprint.c\
			ft_strlen.c\
			ft_memset.c\
			ft_bzero.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_atoi.c\
			ft_toupper.c\
			ft_tolower.c\
			ft_strlcpy.c\
			ft_memchr.c\
			ft_calloc.c\
			ft_lstnew.c\
			ft_lstadd_front.c\
			ft_lstsize.c\
			ft_lstlast.c\
			ft_lstadd_back.c\
			ft_lstdelone.c\
			ft_lstclear.c\
			ft_lstiter.c\
			ft_lstmap.c

OBJS= ${SRCS:.c=.o}


CFLAGS= -Wall -Werror -Wextra -g
NAME := libft.a

all: $(NAME)

.c.o:
	@echo Compiling $<
	gcc -c $(CFLAGS) $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	@echo make $(NAME)
	ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)

re:	fclean $(NAME)

clean:
	@echo Cleaning out those old .o
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@echo Cleaning out that old $(NAME)
	@rm -f $(NAME)

out:
	gcc $(CFLAGS) $(SRCS)

cleanout:
	rm a.out

bonus : $(OBJS) $(BONUS_OBJS)
	@echo make $(NAME)
	ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:        all clean fclean re


