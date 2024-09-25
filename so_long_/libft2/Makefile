# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fatigarc <fatigarc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 19:47:28 by fatigarc          #+#    #+#              #
#    Updated: 2024/08/22 16:24:33 by fatigarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

AR = ar -rcs
CFLAGS = -Wall -Werror -Wextra

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	get_next_line.c get_next_line_utils.c \
	ft_printf.c ft_putchar.c ft_putstr.c nbr_b.c nbr_p.c

OBJ = $(SRC:.c=.o)

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
	get_next_line_bonus.c get_next_line_utils_ bonus.c

BONUS_OBJS = $(BONUS:.c=.o)

NBONUS = .bonus

$(BNAME): $(BONUS_OBJS) $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(NBONUS): $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)
	touch .bonus

%.o:%.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJS) $(BNAME)
	rm -f $(OBJ) $(BONUS_OBJS) $(NBONUS)

fclean: clean
	rm -f $(NAME)

all: $(NAME)

bonus: $(NBONUS)

re: fclean all
	
.PHONY: all clean fclean re bonus