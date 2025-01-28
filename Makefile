CC = gcc
CFLAGS = -Wall -Wextra -Werror
CLIENT = client
SERVER = server
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
CLIENT_SOURCES = client.c
SERVER_SOURCES = server.c
CLIENT_OBJECTS = $(CLIENT_SOURCES:.c=.o)
SERVER_OBJECTS = $(SERVER_SOURCES:.c=.o)

all:$(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJECTS) $(LIBFT)  
	$(CC) $(CFLAGS) $(CLIENT_OBJECTS) -L$(LIBFT_DIR) -lft -o $(CLIENT)

$(SERVER): $(SERVER_OBJECTS) $(LIBFT)  
	$(CC) $(CFLAGS) $(SERVER_OBJECTS) -L$(LIBFT_DIR) -lft -o $(SERVER)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(CLIENT_OBJECTS) $(SERVER_OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(CLIENT) $(SERVER)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re