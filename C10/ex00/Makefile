NAME = ft_display_file
CC = cc
CFLAGS = -Wall -Wextra -Werror
MY_SOURCES = ft_display_file.c
MY_OBJECTS = $(MY_SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(MY_OBJECTS)

$(MY_OBJECTS): $(MY_SOURCES) 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)
