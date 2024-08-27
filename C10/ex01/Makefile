CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_cat
MY_SOURCES = ft_cat.c main.c
			
MY_OBJECTS = $(MY_SOURCES:.c=.o)
REMOVE = rm -rf

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	$(REMOVE) $(NAME)

clean:
	$(REMOVE) $(MY_OBJECTS)

re: fclean
	$(MAKE) all

.PHONY: clean fclean all re