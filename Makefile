# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 13:18:51 by mpepin            #+#    #+#              #
#    Updated: 2022/04/27 13:59:24 by mpepin           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# All files
SRC =	server.c \
		client.c

OBJS_DIR = objs/
OBJS = ${SRC:.c=.o}
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

# Bonus files
SRCB =	file_1 \
		file_n

OBJSB = ${SRCB:.c=.o}
OBJECTS_BONUS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJSB))

# Name of the exec file
EXE1 = server
EXE2 = client

# Flags compile
FLAGS = -Wall -Wextra -Werror

# Delete
RM = rm -f

all: $(EXE1) $(EXE2)

$(OBJS_DIR)%.o:	%.c libft.h
				@mkdir -p $(OBJS_DIR)
				@echo "Compiling: $<"
				@clang $(FLAGS) -c $< -o $@

$(NAME):	$(OBJECTS_PREFIXED)
			@ar rcs $(NAME) $(OBJECTS_PREFIXED)
			@echo "Libft Done !"

bonus:		$(NAME) $(OBJECTS_BONUS_PREFIXED)
			@ar rcs $(NAME) $(OBJECTS_BONUS_PREFIXED)
			@echo "Libft Bonus Done !"

clean:
			rm -rf $(OBJS_DIR)

fclean:		clean
			rm -f all

re:			fclean all

all: program1 program2

program1: program1.c
    gcc -o program1 program1.c

program2: program2.c
    gcc -o program2 program2.c