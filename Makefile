NAME =			push_swap.a
LIB =			push_swap.h
LIBFT_DIR =		../libft
LIBFT =			../libft/libft.a
SRC =			push_swap.c operations.c mini_sort.c big_sort.c \
				utils.c list_utils.c utils_extra.c big_sort_utils.c big_sort_utils_2.c
SRC_OBJS =		$(SRC:.c=.o)
CC = 			@cc
CFLAGS = 		-Wall -Wextra -Werror -g

all:		$(NAME)

$(NAME):	$(SRC_OBJS)
			@$(MAKE) --no-print-directory -C $(LIBFT_DIR)
			@ar -rcs $(NAME) $(SRC_OBJS) $(LIB)

clean:
			@rm -f $(SRC_OBJS)
			@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean

fclean:		clean
			@rm -f $(NAME)
			@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean

re:			fclean all

run:
			$(CC) $(FLAGS) push_swap.c -o push_swap $(NAME) $(LIBFT) -fsanitize=address

.PHONY: all clean fclean run re