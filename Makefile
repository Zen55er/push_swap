NAME =			push_swap.a
LIB =			push_swap.h
LIBFT_DIR =		../libft
LIBFT =			../libft/libft.a
BONUS_LIB =		checker.h
SRC =			push_swap.c operations.c mini_sort.c big_sort.c \
				utils.c list_utils.c utils_extra.c big_sort_utils.c big_sort_utils_2.c
SRC_OBJS =		$(SRC:.c=.o)
BONUS_OBJS =	checker.c
BONUS_OBJS =	$(BONUS_OBJS:.c=.o)
CC = 			@cc
CFLAGS = 		-Wall -Wextra -Werror -g

all:		$(NAME)

$(NAME):	$(SRC_OBJS)
			@$(MAKE) --no-print-directory -C $(LIBFT_DIR)
			@$(MAKE) --no-print-directory -C $(LIBFT_DIR) bonus
			@ar -rcs $(NAME) $(SRC_OBJS) $(LIB)

bonus:		$(SRC_BONUS)
			@ar -rcs $(NAME) $(SRC_BONUS) $(LIB_BONUS)

clean:
			@rm -f $(SRC_OBJS)
			@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean

fclean:		clean
			@rm -f $(NAME)
			@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean

re:			fclean all

run:
			$(CC) $(FLAGS) push_swap.c -o push_swap $(NAME) $(LIBFT) -fsanitize=address

.PHONY: all bonus clean fclean run re