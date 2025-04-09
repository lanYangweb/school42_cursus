# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: layang <layang@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 17:08:57 by layang            #+#    #+#              #
#    Updated: 2025/01/23 13:10:08 by layang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## ------Definitions------ ##
# Folders and objects

SRCS = ./ft_atoi.c ./ft_itoa.c ./ft_putnbr_fd.c ./ft_strlcpy.c ./ft_tolower.c \
       ./ft_bzero.c ./ft_memchr.c ./ft_putstr_fd.c ./ft_strlen.c ./ft_toupper.c \
       ./ft_calloc.c ./ft_memcmp.c ./ft_split.c ./ft_striteri.c\
       ./ft_isalnum.c ./ft_memcpy.c ./ft_strchr.c ./ft_strncmp.c \
       ./ft_isalpha.c ./ft_memmove.c ./ft_strdup.c ./ft_strnstr.c \
       ./ft_isascii.c ./ft_memset.c  ./ft_strrchr.c ./ft_strmapi.c\
       ./ft_isdigit.c ./ft_putchar_fd.c ./ft_strjoin.c ./ft_strtrim.c \
       ./ft_isprint.c ./ft_putendl_fd.c ./ft_strlcat.c ./ft_substr.c\
       ./get_next_line.c ./get_next_line_utils.c
       
SRCSBONUS = ./ft_lstnew_bonus.c ./ft_lstadd_front_bonus.c \
            ./ft_lstsize_bonus.c ./ft_lstlast_bonus.c \
            ./ft_lstadd_back_bonus.c ./ft_lstdelone_bonus.c \
            ./ft_lstclear_bonus.c ./ft_lstiter_bonus.c \
            ./ft_lstmap_bonus.c
OBJS = $(SRCS:.c=.o)
OBJSBONUS = $(SRCSBONUS:.c=.o)
INC = ./libft.h

# Compiler and options
CC = cc
CFLAGS = -Wall -Wextra -Werror -c

# Library name
NAME = libft.a
AR = ar -rc
RANLIB = ranlib

## ------Rules------ ##
# Default rule
all: $(NAME)

# Bonus rule
bonus: $(OBJS) $(OBJSBONUS)
	$(AR) $(NAME) $(OBJS) $(OBJSBONUS)
	$(RANLIB) $(NAME)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -I. -o $@ $<

# Create library file
$(NAME): $(OBJS)
	$(AR) $@ $^
	$(RANLIB) $@

# Clean temporary files
clean:
	rm -f $(OBJS) $(OBJSBONUS)

# Clean all binary files
fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean all

.PHONY: all bonus clean fclean re
