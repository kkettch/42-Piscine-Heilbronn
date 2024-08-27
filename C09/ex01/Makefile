NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
MY_SOURCES = srcs/ft_putchar.c \
	srcs/ft_swap.c \
	srcs/ft_putstr.c \
	srcs/ft_strlen.c \
	srcs/ft_strcmp.c
MY_HEADERS = includes/ft.h
MY_OBJECTS = $(MY_SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	ar rc $(NAME) $(MY_OBJECTS)
	ranlib $(NAME)

$(MY_OBJECTS): $(MY_SOURCES) $(MY_HEADERS)
	$(CC) $(CFLAGS) -Iincludes -c $< -o $@

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
