SERVER := server

CLIENT := client

CC := cc

CFLAGS := -Wall -Wextra -Werror

HEADER := minitalk.h

SERVER_CFILES := server.c

CLIENT_CFILES := client.c

SERVER_OFILES := $(SERVER_CFILES:.c=.o)

CLIENT_OFILES := $(CLIENT_CFILES:.c=.o)

$(SERVER_OFILES): $(SERVER_CFILES) $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(CLIENT_OFILES): $(CLIENT_CFILES) $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(SERVER): $(SERVER_OFILES)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT): $(CLIENT_OFILES)
	$(CC) $(CFLAGS) $^ -o $@

all: $(CLIENT) $(SERVER)

clean:
	rm -f $(SERVER_OFILES) $(CLIENT_OFILES)

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re
