# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 13:18:51 by mpepin            #+#    #+#              #
#    Updated: 2022/06/02 20:39:15 by mpepin           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

HEADER_FILES =	header/minitalk.h

SERVER =	server
SERVER_SRCS =	source_server/server.c\
				source_server/server_utils.c
SERVER_OBJS =	$(SERVER_SRCS:.c=.o)

CLIENT =	client
CLIENT_SRCS =	source_client/client.c\
				source_client/client_utils.c
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
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all norme clean fclean re