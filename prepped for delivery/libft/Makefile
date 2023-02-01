# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 15:28:37 by gacorrei          #+#    #+#              #
#    Updated: 2022/11/14 13:56:26 by gacorrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FINALLIB = @ar -rc
REMOVE = @rm -f
CC = @cc
CFLAGS = -Wextra -Werror -Wall
FUNCTIONS =		ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
				ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c \
				ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
				ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
				ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
				ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
				ft_substr.c ft_tolower.c ft_toupper.c ft_atoi.c
OUTFILES = $(FUNCTIONS:.c=.o)
FOUTFILES = *.o
BFUNCTIONS =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
				ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BOUTFILES = $(BFUNCTIONS:.c=.o)

all: 		$(NAME)

$(NAME): 	$(OUTFILES)
			$(FINALLIB) $(NAME) $(OUTFILES)

bonus: 		$(BOUTFILES)
			$(FINALLIB) $(NAME) $(BOUTFILES)

clean: 
			$(REMOVE) $(FOUTFILES)

fclean: 	clean
			$(REMOVE) $(NAME)

re: 		fclean all

run:
			$(CC) $(CFLAGS) main.c $(NAME)
			@./a.out

.PHONY: all bonus clean fclean re