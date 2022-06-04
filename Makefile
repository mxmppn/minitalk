# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 13:18:51 by mpepin            #+#    #+#              #
#    Updated: 2022/06/04 14:55:38 by mpepin           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# * * * * * * * * * * * * * * * * Header * * * * * * * * * * * * * * * * *	#
HEADER_FILES =	header/minitalk.h


# * * * * * * * * * * * * * * * Executables * * * * * * * * * * * * * * * *	#		
SERVER =	server
SERVER_SRCS =	source_server/server.c\
				source_server/server_utils.c
SERVER_OBJS =	$(SERVER_SRCS:.c=.o)

CLIENT =	client
CLIENT_SRCS =	source_client/client.c\
				source_client/client_utils.c
CLIENT_OBJS =	$(CLIENT_SRCS:.c=.o)


# * * * * * * * * * * * * * * * Other Stuff * * * * * * * * * * * * * * * *	#
FT_PRINTF =	mpep_ftprintf/libftprintf.a

# * * * * * * * * * * * * * * * Compilation * * * * * * * * * * * * * * * *	#
CC =	gcc
C_FLAGS =	-Wall -Wextra -Werror -I.


# * * * * * * * * * * * * * * * * Rules * * * * * * * * * * * * * * * * * * #
all: $(SERVER) $(CLIENT)

%.o: %.c $(HEADER_FILES)
	$(CC) $(C_FLAGS) -c $< -o $@
	
$(FT_PRINTF):
	make -C mpep_ftprintf
	
$(SERVER): $(SERVER_OBJS) $(FT_PRINTF)
	$(CC) $(SERVER_OBJS) $(FT_PRINTF) -o $(SERVER)

$(CLIENT): $(CLIENT_OBJS) $(FT_PRINTF)
	$(CC) $(CLIENT_OBJS) $(FT_PRINTF) -o $(CLIENT)

norme:
	@norminette $(SERVER_SRCS)
	@norminette $(CLIENT_SRCS)
	@norminette $(HEADER_FILES)

clean:
	make -C mpep_ftprintf clean
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS)

fclean: clean
	make -C mpep_ftprintf fclean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all norme clean fclean re