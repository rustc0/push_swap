NAME = push_swap

CC = cc -Wall -Werror -Wextra

SRC = push_swap.c get_args.c parsing_utils.c operations_utils.c stack_utils.c

LIBFT = libft/libft.a

INCLUDES = -I./libft

LIBS = -lft

all: $(NAME)

$(NAME): $(LIBFT) $(GNL) $(SRC) push_swap.h
	$(CC) $(SRC) $(INCLUDES) -L./libft $(LIBS) -o $(NAME)

$(LIBFT): FORCE
	make bonus -C libft && make clean -C libft

FORCE:

clean:
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re FORCE               