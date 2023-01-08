NAME =			push_swap.a
LIB =			push_swap.h
LIBFT_DIR =		../libft
LIBFT =			../libft/libft.a
FT_PRINTF_DIR =	../ft_printf
FT_PRINTF =		../ft_printf/libftprintf.a
BONUS_LIB =		checker.h
SRC =			push_swap.c utils.c operations.c
SRC_OBJS =		$(SRC:.c=.o)
BONUS_OBJS =	checker.c
BONUS_OBJS =	$(BONUS_OBJS:.c=.o)
CC = 			@cc
CFLAGS = 		-Wall -Wextra -Werror -g

all:		$(NAME)

$(NAME):	$(SRC_OBJS)
			@$(MAKE) --no-print-directory -C $(LIBFT_DIR)
			@$(MAKE) --no-print-directory -C $(LIBFT_DIR) bonus
			@$(MAKE) --no-print-directory -C $(FT_PRINTF_DIR)
			@ar -rcs $(NAME) $(SRC_OBJS) $(LIB)

bonus:		$(SRC_BONUS)
			@ar -rcs $(NAME) $(SRC_BONUS) $(LIB_BONUS)

clean:
			@rm -f $(SRC_OBJS)
			@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
			@$(MAKE) --no-print-directory -C $(FT_PRINTF_DIR) clean

fclean:		clean
			@rm -f $(NAME)
			@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
			@$(MAKE) --no-print-directory -C $(FT_PRINTF_DIR) fclean

re:			fclean all
			@$(MAKE) --no-print-directory -C $(LIBFT_DIR) re
			@$(MAKE) --no-print-directory -C $(FT_PRINTF_DIR) re

run:
			$(CC) $(FLAGS) main.c $(NAME) $(LIBFT) $(FT_PRINTF) -fsanitize=address

.PHONY: all bonus clean fclean run re