NAME = push_swap

CC = cc -Wall -Werror -Wextra

SRC = main.c get_args.c utils.c operations_utils.c operations.c operations_r.c ft_sort.c sorting_utils.c sorting_utils_2.c

LIBFT = libft/libft.a

LIBFT_SRCS =./libft/ft_atoi.c		./libft/ft_isprint.c	./libft/ft_strnstr.c 	./libft/ft_strncmp.c	./libft/ft_striteri.c	\
			./libft/ft_bzero.c		./libft/ft_strdup.c		./libft/ft_strrchr.c 	./libft/ft_tolower.c	./libft/ft_split.c		\
			./libft/ft_memchr.c		./libft/ft_strlcat.c 	./libft/ft_toupper.c	./libft/ft_putchar_fd.c	./libft/ft_calloc.c		\
			./libft/ft_isalnum.c	./libft/ft_memcmp.c		./libft/ft_strlcpy.c 	./libft/ft_substr.c		./libft/ft_putstr_fd.c	\
			./libft/ft_isalpha.c	./libft/ft_memcpy.c		./libft/ft_strlen.c		./libft/ft_strjoin.c	./libft/ft_putendl_fd.c	\
			./libft/ft_isascii.c	./libft/ft_memmove.c	./libft/ft_strchr.c		./libft/ft_itoa.c		./libft/ft_putnbr_fd.c	\
			./libft/ft_isdigit.c	./libft/ft_memset.c		./libft/ft_strtrim.c 	./libft/ft_strmapi.c

INCLUDES = -I./libft

LIBS = -lft

MAKEFLAGS += --no-print-directory

all: $(NAME)

$(NAME): $(LIBFT) $(SRC) push_swap.h
	@echo "COMPILING PUSH_SWAP..."
	@$(CC) $(SRC) $(INCLUDES) -L./libft $(LIBS) -o $(NAME)

$(LIBFT): $(LIBFT_SRCS)
	@echo "MAKING LIBFT ARCHIVE..."
	@make -C libft

clean:
	@$(MAKE) -C libft clean
	@echo "Cleaning object files..."

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C libft fclean
	@echo "Getting initial state..."

re: fclean all

.PHONY: all clean fclean re               