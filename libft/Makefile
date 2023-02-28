SOURCES	=	ft_atoi.c 		\
			ft_isdigit.c	\
			ft_putchar_fd.c	\
			ft_putendl_fd.c \
			ft_split.c		\
			ft_strdup.c		\
			ft_strlen.c 	\
			ft_substr.c		



NAME 		= libft.a

OBJECTS 	= $(SOURCES:.c=.o)

CC 			= gcc

RM 			= rm -f

CFLAGS 		= -Wall -Werror -Wextra

all: 	$(NAME)


$(NAME): $(OBJECTS)
		$(AR) rc $(NAME) $(OBJECTS)

clean:
		$(RM) $(OBJECTS) 

fclean: clean
		$(RM) $(NAME)

re: 	fclean all

.PHONY: all clean fclean re