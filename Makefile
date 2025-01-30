CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = checker_functions.c algorithm.c rev_rotate.c rotate.c stack_functions0.c stack_functions1.c choosing_targets.c stack_functions2.c stack_functions3.c stack_functions4.c parsing0.c parsing1.c stack_functions5.c push.c stack_functions6.c push_bonus.c swap.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = ./ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
GNL_DIR = ./get_next_line
GNL = $(GNL_DIR)/gnl.a

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF) $(GNL) push_swap.c
	$(CC) $(CFLAGS) push_swap.c $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME) $(GNL)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(GNL):
	$(MAKE) -C $(GNL_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

checker: $(OBJS) $(LIBFT) $(FT_PRINTF) $(GNL) checker.c
	$(CC) $(CFLAGS)  checker.c -o checker $(OBJS) $(LIBFT) $(FT_PRINTF) $(GNL)

bonus: checker

clean:
	rm -rf $(OBJS) checker_functions.o
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean

fclean: clean
	rm -rf push_swap checker
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean

re: fclean all

.PHONY: all clean fclean re