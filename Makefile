CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = operations.c parsing.c push_swap.c stack_functions.c algorithm.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap
LIBFT_DIR = ./libft
FT_PRINTF_DIR = ./ft_printf
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(FT_PRINTF)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re