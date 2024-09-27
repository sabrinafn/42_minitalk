NAME := minitalk

CC := cc

CFLAGS := -Wall -Wextra -Werror

HEADER := minitalk.h

CFILES := server.c

OFILES := $(CFILES:.c=.o)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $^ -o $@

all: $(NAME)

clean:
	rm -f $(OFILES)

fclean:
	rm -f $(NAME) $(OFILES)

re: fclean all

.PHONY: all clean fclean re
