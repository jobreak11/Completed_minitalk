NAME = minitalk
SERVER_NAME = server
CILENT_NAME = client
# make -C [directory]
FT_PRINTF_PATH = ft_printf
FT_PRINTF_A = ft_printf/libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I ./includes 

SERVER = server.c
server_objs = $(SERVER:.c=.o)
CLIENT = client.c
client_objs = $(CLIENT:.c=.o)
utils_src = utils/ft_atoi.c \
			utils/ft_strlen.c
utils_objs = $(utils_src:.c=.o)


all: $(FT_PRINTF_A) $(NAME)

$(NAME): server client

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

server: $(server_objs) $(utils_objs)
	@$(CC) $(CFLAGS) $(INCLUDE)  $(server_objs) $(FT_PRINTF_A) $(utils_objs) -o $(SERVER_NAME)
client: $(client_objs) $(utils_objs)
	@$(CC) $(CFLAGS) $(INCLUDE)  $(client_objs) $(utils_objs) -o $(CILENT_NAME)
$(FT_PRINTF_A): 
	make -C $(FT_PRINTF_PATH)

clean:
	@rm -rf $(client_objs) $(server_objs) $(utils_objs)
	@cd ft_printf && make clean

fclean: clean
		@rm -rf $(SERVER_NAME) $(CILENT_NAME)
		@cd ft_printf && make fclean

re: fclean all

.PHONY: all clean fclean re