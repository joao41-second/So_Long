# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 06:17:31 by jperpect          #+#    #+#              #
#    Updated: 2024/08/08 13:54:53 by jperpect         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLGS = -Wall -Wextra -Werror

FILES = main.c 

SRCS = $(FILES:.c=.o)

LIB = ./libft/libft.a ./libft/libftprintf.a

MINX_FLAG = -Lminilibx-linux -lmlx_Linux -lX11 -lXext

AR = ar rcs

CC = cc 

RM = rm -f

CAT = cat number.txt 

NAME = so_long


#.SILENT:

all: $(NAME)
%.o:%.c 
	cc -c $(FLGS) -o $@ $<

$(NAME) : $(SRCS)
	cd libft && make compile && make 
	cc $(FLGS) $(SRCS) $(LIB) $(MINX_FLAG) -o $(NAME) 
	
bonus: $(OBJECT_B) $(NAME)
	ar rcs $(NAME) $^


clean:
	$(fclean)
	$(RM)  $(SRCS)
	$(RM)  $(OBJS_CLI)
	cd ./libft && make clean

fclean: clean
	$(RM) $(NAME) 


re: fclean all

exec:
	cc	-g $(FLGS)  $(SRCS) $(BONUS) -lbsd

norm: 
	python3 -m c_formatter_42 -c $(BONUS)
	
	


