# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/17 12:39:12 by layang            #+#    #+#              #
#    Updated: 2025/01/25 15:01:10 by layang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Werror -Wall -Wextra

#CFLAGS_B = -Werror -Wall -Wextra -fsanitize=address -fPIC
#CFLAGS = -Werror -Wall -Wextra
#-fsanitize=address

RM = rm -rf

SRCS = 	./main.c\
		srcs/operations/pa_pb.c\
		srcs/operations/ra_rb_rr.c\
		srcs/operations/rra_rrb_rrr.c\
		srcs/operations/sa_sb_ss.c\
		srcs/utils/put_a_index.c\
		srcs/utils/sort_long.c\
		srcs/utils/sort_short.c


SRCS_BONUS = srcs_bonus/checker.c\
			srcs_bonus/checker_utils.c\
			srcs_bonus/pa_pb.c\
			srcs_bonus/ra_rb_rr.c\
			srcs_bonus/rra_rrb_rrr.c\
			srcs_bonus/sa_sb_ss.c
#OBJS = $(SRCS:.c=.o)

$(NAME) : $(SRCS)
	make bonus -C libft
	cc $(CFLAGS) $(SRCS) -Llibft -lft -o $(NAME) 

all : $(NAME)

fclean : clean
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C libft

re : fclean all

bonus : fclean
	make bonus -C libft CFLAGS="-Wall -Wextra -Werror -fPIC -c"
	gcc $(CFLAGS) $(SRCS_BONUS) -Llibft -lft -o checker

test2:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 2))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test3:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 3))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test5:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 5))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test100:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test500:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test1000:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

.PHONY: all bonus clean fclean re test2 test3 test5 test100 test500 test1000
