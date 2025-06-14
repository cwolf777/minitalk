CC = gcc
CFLAGS = -Wall -Wextra -Werror

CLIENT = client
SERVER = server

LIBFT_REPO = git@github.com:cwolf777/LIBFT.git
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CLIENT_SOURCES = client.c
SERVER_SOURCES = server.c
CLIENT_OBJECTS = $(CLIENT_SOURCES:.c=.o)
SERVER_OBJECTS = $(SERVER_SOURCES:.c=.o)

all: clone_libft $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJECTS) $(LIBFT)  
	$(CC) $(CFLAGS) $(CLIENT_OBJECTS) -L$(LIBFT_DIR) -lft -o $(CLIENT)

$(SERVER): $(SERVER_OBJECTS) $(LIBFT)  
	$(CC) $(CFLAGS) $(SERVER_OBJECTS) -L$(LIBFT_DIR) -lft -o $(SERVER)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clone_libft:
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		echo "📦 Cloning libft from GitHub..."; \
		git clone $(LIBFT_REPO) $(LIBFT_DIR); \
	fi

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(CLIENT_OBJECTS) $(SERVER_OBJECTS)
		@if [ -d "$(LIBFT_DIR)" ]; then \
			$(MAKE) -C $(LIBFT_DIR) clean; \
		fi

fclean: clean
	rm -f $(CLIENT) $(SERVER)
	@if [ -d "$(LIBFT_DIR)" ]; then \
		$(MAKE) -C $(LIBFT_DIR) fclean; \
	fi

re: fclean all

.PHONY: all clean fclean re clone_libft