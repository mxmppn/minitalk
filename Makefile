# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 13:18:51 by mpepin            #+#    #+#              #
#    Updated: 2022/06/02 16:58:29 by mpepin           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SERVER =	server
CLIENT =	client
NAME =	$(CLIENT) $(SERVER)
HEADER_FILES =	header/minitalk.h
# OBJECT_FILES =	object/
SERVER_SRCS =	source/server.c\
				source/server_utils.c
CLIENT_SRCS =	source/client.c\
				source/client_utils.c
SERVER_OBJS =	$(SERVER_SRCS:.c=.o)
CLIENT_OBJS =	$(CLIENT_SRCS:.c=.o)
CC =	gcc
C_FLAGS =	-Wall -Wextra -Werror -I.

all: $(SERVER) $(CLIENT)

%.o: %.c $(HEADER_FILES)
	$(CC) $(C_FLAGS) -c $< -o $@

$(SERVER): $(SERVER_OBJS)
	$(CC) $(SERVER_OBJS) -o $(SERVER)

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(CLIENT_OBJS) -o $(CLIENT)

norme:
	@norminette $(SERVER_SRCS)
	@norminette $(CLIENT_SRCS)
	@norminette $(HEADER_FILES)

clean:
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all norme clean fclean re