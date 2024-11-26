# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/17 12:39:12 by layang            #+#    #+#              #
#    Updated: 2024/11/18 10:00:03 by layang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## ------Definitions------ ##
# Folders and objects

SRCS = ./ft_printf.c ./ft_put_num.c ./ft_put_str.c ./ft_put_ptr.c
# SRCSBONUS = ./ft_.c
OBJS = $(SRCS:.c=.o)
# OBJSBONUS = $(SRCSBONUS:.c=.o)
INC = ./ft_printf.h

# Compiler and options
CC = cc
CFLAGS = -Wall -Wextra -Werror -c
AR = ar -rc
RANLIB = ranlib

# Library name
NAME = libftprintf.a

## ------Rules------ ##
# Compile source files to object files
$(OBJS): ./%.o: ./%.c $(INC)
		$(CC) $(CFLAGS) -I. -o $@ $<

# Create library file
$(NAME): $(OBJS)
		$(AR) $@ $^
		$(RANLIB) $@

# Default rule
all: $(NAME)

# Bonus rule
# bonus: $(OBJS) $(OBJSBONUS)
# 	$(AR) $(NAME) $(OBJSBONUS)

## ---------------------------------TEST----------------------------------- ##
#cc -Wall -Wextra -Werror -I. -o test_printf test_printf.c -L. -lftprintf
#./test_printf
## ------------------------------------------------------------------------ ##

# Clean temporary files
clean:
	rm -f $(OBJS)
# 	rm -f $(OBJS) $(OBJSBONUS)

# Clean all binary files
fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean all

# .PHONY: all bonus clean fclean re
.PHONY: all clean fclean re