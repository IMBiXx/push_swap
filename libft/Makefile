# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpotier <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/01 16:36:41 by tpotier           #+#    #+#              #
#    Updated: 2019/08/06 15:43:17 by tpotier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FILES = ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr \
		ft_memcmp ft_strlen ft_strdup ft_strcpy ft_strncpy ft_strcat \
		ft_swap ft_max ft_min ft_atoi_len ft_putnstr ft_map \
		ft_strncat ft_strlcat ft_strchr ft_strrchr ft_strstr ft_strnstr \
		ft_strcmp ft_strncmp ft_atoi ft_isalpha ft_isdigit ft_isalnum \
		ft_isascii ft_isprint ft_toupper ft_tolower ft_nlen_base \
		ft_memalloc ft_memdel ft_strnew ft_strdel ft_strclr ft_striter \
		ft_striteri ft_strmap ft_strmapi ft_strequ ft_strnequ ft_strsub \
		ft_strjoin ft_strtrim ft_strsplit ft_strlen_bfrchr ft_strncat_mal \
		ft_putchar_fd ft_putchar ft_putstr_fd ft_putstr ft_putendl_fd \
		ft_putendl ft_putnbr_fd ft_putnbr ft_itoa \
		ft_dlstnew ft_dlstdel ft_dlstadd_end ft_dlstdelall ft_dlstdisp \
		ft_stkswap ft_stkpush ft_stkpop \
		ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter ft_lstmap \
		ft_lstdelif \
		ft_sstkswap ft_sstkpush ft_sstkpop ft_sstkrot ft_sstkrrot \
		ft_sstkchkord ft_sstkdisp ft_sstkinit ft_sstkdel ft_sstkcpy \
		ft_getnextline ft_putnchar \
		ft_printf io parsing parsing_utils io_csr io_doxb io_utils cast io_f \
		io_k io_other io_p f_utils

IFILES = libft.h
NAME = libft.a
SDIR = srcs/
IDIR = incs/

CFLAGS = -Wall -Wextra -Werror -I$(IDIR) -MMD -MP

SRCS = $(addprefix $(SDIR), $(addsuffix .c, $(FILES)))
INCS = $(addprefix $(IDIR), $(IFILES))
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $(OBJS)
	ranlib $@

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

list: all
	@nm libft.a -Ug | grep "T _" | sed "s/.*T _//" | sort
	@cat $(INCS) | grep -G "\t\\*\{0,\}ft" | sort

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all $(name) clean fclean re list
-include $(DEPS)
