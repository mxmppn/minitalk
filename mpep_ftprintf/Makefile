# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/29 16:27:08 by mpepin            #+#    #+#              #
#    Updated: 2022/06/02 19:23:43 by mpepin           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# All files
SRC =	ft_printf.c \
		ft_print_fmt.c \
		ft_print_fmt_c.c \
		ft_print_fmt_d.c \
		ft_print_fmt_i.c \
		ft_print_fmt_p.c \
		ft_print_fmt_percent.c \
		ft_print_fmt_s.c \
		ft_print_fmt_u.c \
		ft_print_fmt_x.c \
		ft_print_fmt_xx.c

# Name of the direcory containing the object files
OBJS_DIR = objs/
OBJS = ${SRC:.c=.o}
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

# Name of the executable file
EXE_NAME = libftprintf.a

# Flags used for compilation
FLAGS = -Wall -Wextra -Werror

# Delete
RM = rm -f

all: $(EXE_NAME)

$(OBJS_DIR)%.o:	%.c ft_printf.h
				@mkdir -p $(OBJS_DIR)
				@echo "Compiling: $<"
				@clang $(FLAGS) -c $< -o $@

$(EXE_NAME):	$(OBJECTS_PREFIXED)
			@ar rcs $(EXE_NAME) $(OBJECTS_PREFIXED)
			@echo "----> Librairy done for ft_printf <----"

clean:
			rm -rf $(OBJS_DIR)

fclean:		clean
			rm -f $(EXE_NAME)

re:			fclean all
