CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = rush-02
MY_SOURCES = additional.c \
			error.c \
			ft_split.c \
			get_file.c \
			input.c \
			main.c \
			output.c \
			valid_dictionary.c \
			split_and_call.c
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