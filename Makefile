# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpotier <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/01 16:36:41 by tpotier           #+#    #+#              #
#    Updated: 2019/10/09 12:23:02 by valecart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FILES1 = checker args_checker stack_utils display bench_utils graphics \
		 ops_utils checker_utils checker_utils2 checker_utils3 get_next_line
FILES2 = push_swap args_checker stack_utils bench_utils ops_utils
IFILES = push_swap.h checker.h get_next_line.h
NAME1 = checker
NAME2 = push_swap
IDIR = incs/
SDIR = srcs/
LIBFTDIR = libft/
LIBFT = $(LIBFTDIR)libft.a
LIBFTINC = $(LIBFTDIR)incs/
CFLAGS = -Wall -Wextra -Werror -I$(IDIR) -I$(LIBFTINC) -MMD -MP
CFLAGSF = $(CFLAGS) -L$(LIBFTDIR) -lft
CFLAGSG = $(CFLAGSF) $(shell sdl2-config --libs)

INCS = $(addprefix $(IDIR), $(IFILES))
SRCS1 = $(addprefix $(SDIR), $(addsuffix .c, $(FILES1)))
OBJS1 = $(SRCS1:.c=.o)
DEPS1 = $(SRCS1:.c=.d)
SRCS2 = $(addprefix $(SDIR), $(addsuffix .c, $(FILES2)))
OBJS2 = $(SRCS2:.c=.o)
DEPS2 = $(SRCS2:.c=.d)

all: $(NAME1) $(NAME2)

$(LIBFT):
	make -C $(LIBFTDIR)

$(NAME1): $(OBJS1) $(LIBFT)
ifdef GRAPH
	$(CC) $(CFLAGSG) -o $@ $(OBJS1)
else
	$(CC) -o $@ $(OBJS1) $(CFLAGSF)
endif

$(NAME2): $(OBJS2) $(LIBFT)
	$(CC) $(CFLAGSF) -o $@ $(OBJS2)

%.o: %.c
ifdef GRAPH
	$(CC) -DGRAPHIC_MODE $(shell sdl2-config --cflags) -o $@ -c $< $(CFLAGS)
else
	$(CC) -o $@ -c $< $(CFLAGS)
endif
	
clean:
	make -C $(LIBFTDIR) $@
	rm -f $(OBJS1) $(OBJS2) $(DEPS)

fclean: clean
	make -C $(LIBFTDIR) $@
	rm -f $(NAME1) $(NAME2)

re: fclean all

.PHONY: all clean fclean re
-include $(DEPS1) $(DEPS2)
