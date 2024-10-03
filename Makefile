# Nome do executável
NAME = push_swap

# Caminho para a biblioteca libft
LIBFT = libft/libft.a

# Diretórios de fontes, includes e objetos
SRC_PATH = src
INCLUDE_PATH = include
OBJ_PATH = obj

# Lista de arquivos fontes
SRC = push_swap.c initialize_args.c process_stack.c fill_stack.c sorting_stack.c \
      sorting_big_stack.c push.c swap.c rotate.c reverse_rotate.c

# Prefixando o caminho para os arquivos fontes e objetos
SRC_FILES = $(addprefix $(SRC_PATH)/, $(SRC))
OBJ = $(patsubst $(SRC_PATH)/%.c, $(OBJ_PATH)/%.o, $(SRC_FILES))

# Comandos
RM = @rm -rf
CC = @cc
CFLAGS = -g -Wextra -Werror -Wall -I$(INCLUDE_PATH)

# Regras principais
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

# Regra para compilar os arquivos objetos e colocar na pasta obj
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

# Criar o diretório de objetos, se não existir
$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

# Compilar a libft
$(LIBFT):
	@make -C libft

# Limpar os objetos
clean:
	$(RM) $(OBJ_PATH)
	@make clean -C libft

# Limpar tudo
fclean: clean
	$(RM) $(NAME)
	@make fclean -C libft

# Recompilar tudo
re: fclean all

# Alvos phony
.PHONY: all clean fclean re
