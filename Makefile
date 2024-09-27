SERVER := server

CLIENT := client

CC := cc

FLAGS := -Wall -Wextra -Werror

HEADER := minitalk.h

SERVER_CFILES := server.c ft_utils.c
CLIENT_CFILES := client.c ft_utils.c

SERVER_OFILES := $(SERVER_CFILES:.c=.o)
CLIENT_OFILES := $(CLIENT_CFILES:.c=.o)

all: $(SERVER) $(CLIENT)

# Compiling the server
$(SERVER): $(SERVER_OFILES)
	$(CC) $(FLAGS) $(SERVER_OFILES) -o $(SERVER)

# Compiling the client
$(CLIENT): $(CLIENT_OFILES)
	$(CC) $(FLAGS) $(CLIENT_OFILES) -o $(CLIENT)

%.o: %.c
	$(CC) $(FLAGS) -I$(HEADER) -c $< -o $@

clean:
	rm -f $(SERVER_OFILES) $(CLIENT_OFILES)

fclean: clean
	rm -f $(SERVER) $(CLIENT) 

re: fclean all

.PHONY: all clean fclean re
