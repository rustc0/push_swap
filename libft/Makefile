# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/25 20:48:48 by rahmoham          #+#    #+#              #
#    Updated: 2025/03/05 00:59:15 by rahmoham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -Wall -Wextra -Werror

AR = ar rcs

RM = rm -rf

SRCS =	ft_atoi.c		ft_isprint.c	ft_strnstr.c 	ft_strncmp.c	ft_striteri.c	\
		ft_bzero.c 		ft_strdup.c		ft_strrchr.c 	ft_tolower.c	ft_split.c		\
		ft_memchr.c		ft_strlcat.c 	ft_toupper.c	ft_putchar_fd.c	ft_calloc.c		\
		ft_isalnum.c	ft_memcmp.c		ft_strlcpy.c 	ft_substr.c		ft_putstr_fd.c	\
		ft_isalpha.c	ft_memcpy.c		ft_strlen.c		ft_strjoin.c	ft_putendl_fd.c	\
		ft_isascii.c	ft_memmove.c	ft_strchr.c		ft_itoa.c		ft_putnbr_fd.c	\
		ft_isdigit.c	ft_memset.c		ft_strtrim.c 	ft_strmapi.c \

BSRCS = ft_lstnew_bonus.c		ft_lstadd_front_bonus.c		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c		ft_lstadd_back_bonus.c		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c		ft_lstiter_bonus.c			ft_lstmap_bonus.c \

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

bonus: $(OBJS) $(BOBJS)
	@$(AR) $(NAME) $(OBJS) $(BOBJS)

%.o: %.c
	@$(CC) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(BOBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY : all bonus clean fclean re