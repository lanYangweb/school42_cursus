# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: layang <layang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/23 11:25:10 by layang            #+#    #+#              #
#    Updated: 2025/03/10 10:19:18 by layang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
NAME_B = fdf_bonus
CC = cc
CFLAGS = -Werror -Wall -Wextra -g

#CFLAGS_B = -Werror -Wall -Wextra -fsanitize=address -fPIC

RM = rm -rf

SRC_F = ./src/
SRC_C = draw_map_img.c\
		fdf.c\
		utils_color.c\
		draw_map_lines.c\
		hook_events.c\
		utils_math.c\
		draw_map_points.c\
		transforms.c\
		utils_transform.c
		
SRC_B = draw_map_img.c\
		fdf_bonus.c\
		utils_color.c\
		draw_map_lines.c\
		hook_events.c\
		hook_events_bonus.c\
		utils_math.c\
		draw_map_points.c\
		transforms.c\
		utils_transform.c

SRCS = $(addprefix $(SRC_F), $(SRC_C))
SRCS_B = $(addprefix $(SRC_F), $(SRC_B))

LIBC =  -Llibft -Lminilibx-linux
LINKS = -lmlx -lft -lm -lpthread -lX11 -lXext

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

CYAN = \033[0;36m
RESET = \033[0m

$(NAME) : $(OBJS)
	@echo ""
	@echo "${CYAN}Compiling libft and minilibx-linux...${RESET}"
	$(MAKE) bonus -C libft
	@echo ""
	$(MAKE) -C minilibx-linux
	@echo ""
	@echo "${CYAN}libft and minilibx-linux Created${RESET}"
	@echo ""
	@echo "${CYAN}Compiling $(NAME)...${RESET}"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBC) $(LINKS)
	@echo ""
	@echo "${CYAN}$(NAME) Created${RESET}"

all : $(NAME)

fclean : clean
	$(MAKE) fclean -C libft

clean :
	$(RM) $(NAME) $(OBJS) $(NAME_B) $(OBJS_B)
	$(MAKE) clean -C libft

re : fclean all

bonus : $(NAME_B)

$(NAME_B) : $(OBJS_B)
	@echo ""
	@echo "${CYAN}Compiling libft and minilibx-linux...${RESET}"
	$(MAKE) bonus -C libft
	@echo ""
	$(MAKE) -C minilibx-linux
	@echo ""
	@echo "${CYAN}libft and minilibx-linux Created${RESET}"
	@echo ""
	@echo "${CYAN}Compiling $(NAME_B)...${RESET}"
	$(CC) $(CFLAGS) $(OBJS_B) -o $(NAME_B) $(LIBC) $(LINKS)
	@echo ""
	@echo "${CYAN}$(NAME_B) Created${RESET}"

.PHONY: all bonus clean fclean re