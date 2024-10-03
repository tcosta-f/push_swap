NAME = push_swap

LIBFT = libft/libft.a

SRC = push_swap.c initialize_args.c process_stack.c fill_stack.c sorting_stack.c sorting_big_stack.c push.c swap.c rotate.c reverse_rotate.c

OBJ = $(SRC:.c=.o)

RM = @rm -rf

CC = @cc -g -Wextra -Werror -Wall

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ): %.o: %.c
	$(CC) -c $< -o $@

$(LIBFT):
	@make -C libft

clean:
	$(RM) $(OBJ)
	@make clean -C libft

fclean: clean
	$(RM) $(NAME)
	@make fclean -C libft

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
