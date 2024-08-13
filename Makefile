# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 06:17:31 by jperpect          #+#    #+#              #
#    Updated: 2024/08/13 16:13:21 by jperpect         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLGS = -Wall -Wextra -Werror

MAKEFLAGS += -s

FILES = main.c ./src/maps_chek/main_map_chek.c ./src/maps_chek/vaid_unes.c

SRCS = $(FILES:.c=.o)

LIB = ./libft/libft.a ./libft/libftprintf.a ./libft/get_next_line.a

MINX_FLAG = -Lminilibx-linux -lmlx_Linux -lX11 -lXext

AR = ar rcs

CC = cc 

RM = rm -f

CAT = cat number.txt 

NAME = so_long



COUNT_FILE = count.txt

# Verifica se o arquivo existe; se não, cria com valor inicial 0
ifeq ($(wildcard $(COUNT_FILE)),)
    $(shell echo 0 > $(COUNT_FILE))
endif

COUNT = $(shell cat $(COUNT_FILE))


#.SILENT:

all: $(NAME)
%.o:%.c 
	@cc -c $(FLGS) -o $@ $< && clear && echo $(COUNT) && sleep 0.2
	$(eval COUNT=$(shell echo $$(( $(COUNT) + 1 ))))

	# Salva o novo valor de COUNT no arquivo
	@echo $(COUNT) > $(COUNT_FILE)

	



$(NAME) : $(SRCS)
	cd libft && make compile && make 
	
	cc $(FLGS) $(SRCS) $(LIB) $(MINX_FLAG) -o $(NAME)
	echo "╔══════════════════════════╗"
	echo "║ ✅ Compiled Successfully!║"
	echo "╚══════════════════════════╝"
	@rm -f $(COUNT_FILE)
	
bonus: $(OBJECT_B) $(NAME)
	ar rcs $(NAME) $^
	

clean:
	
	$(fclean)
	$(RM)  $(SRCS)
	$(RM)  $(OBJS_CLI)
	cd ./libft && make clean
		@rm -f $(COUNT_FILE)

fclean: clean

	$(RM) $(NAME)
		@rm -f $(COUNT_FILE)


re: fclean all

exec:
	cc	-g $(FLGS)  $(SRCS) $(BONUS) -lbsd
		@rm -f $(COUNT_FILE)

norm: 
	python3 -m c_formatter_42 -c $(BONUS)
		@rm -f $(COUNT_FILE)
	
	


