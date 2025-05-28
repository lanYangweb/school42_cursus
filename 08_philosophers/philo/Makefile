# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: layang <layang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 13:37:24 by layang            #+#    #+#              #
#    Updated: 2025/05/20 20:15:17 by layang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
#NAME_B = philo_bonus
CC = cc
CFLAGS = -Werror -Wall -Wextra -g -pthread

# MODE=debug
ifeq ($(MODE), debug)
	CFLAGS	+= -D DEBUG_FORMATTING=1 -fsanitize=thread -g
endif
#CFLAGS_D = -Werror -Wall -Wextra -fsanitize=address -fPIC -fsanitize=thread -g
#valgrind --tool=helgrind
SRC_PATH = src/
OBJ_PATH = obj/

SRC	=	main.c \
		utils.c \
		init.c \
		free_philo.c \
		time_utils.c \
		start_philo.c \
		end_check.c

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))

INC		= -I ./includes/

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
