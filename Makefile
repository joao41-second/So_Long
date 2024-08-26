# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 06:17:31 by jperpect          #+#    #+#              #
#    Updated: 2024/08/26 01:56:23 by jperpect         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLGS = -Wall -Wextra -Werror

MAKEFLAGS += -s

FILES = main.c ./src/maps_chek/main_map_chek.c ./src/maps_chek/vaid_unes.c  ./src/mandatory/main_mandatory.c  ./src/mandatory/imgs.c ./src/maps_chek/valid_map_componets.c ./src/maps_chek/valid_str.c

BONUS = ./src/bonus/main.c ./src/maps_chek/main_map_chek.c ./src/maps_chek/vaid_unes.c  ./src/bonus/main_mandatory.c  ./src/bonus/imgs.c ./src/maps_chek/valid_map_componets.c \
	./src/bonus/mobs.c ./src/maps_chek/valid_str.c ./src/bonus/random.c ./src/bonus/imgs_2.c ./src/bonus/imgs_3.c ./src/bonus/imgs_4.c ./src/bonus/map_if.c


SRCS = $(FILES:.c=.o)
BON = $(BONUS:.c=.o)

LIB = ./libft/libft.a ./libft/libftprintf.a ./libft/get_next_line.a 

MINX_FLAG = -Lminilibx-linux -lmlx_Linux -lX11 -lXext

AR = ar rcs

CC = cc 

RM = rm -f

CAT = cat number.txt 

NAME = so_long

MINIX = ./minilibx-linux/libmlx.a

MINILIBX_PATH	= ./minilibx-linux




COUNT_FILE = count.txt

# Verifica se o arquivo existe; se não, cria com valor inicial 0
ifeq ($(wildcard $(COUNT_FILE)),)
    $(shell echo 0 > $(COUNT_FILE))
endif


COUNT = $(shell cat $(COUNT_FILE))


$(MINIX):
	$(MAKE) all -C $(MINILIBX_PATH)
#.SILENT:

$(NAME) : $(MINIX) $(SRCS)
	cd libft && make compile && make 
	cc $(FLGS) $(SRCS) $(LIB) $(MINX_FLAG) -o $(NAME)
	echo "╔══════════════════════════╗"
	echo "║ ✅ Compiled Successfully!║"
	echo "╚══════════════════════════╝"
	@rm -f $(COUNT_FILE)

all: $(NAME) $(BONUS)
%.o:%.c 
	@cc -c $(FLGS) -o $@ $< && clear && echo $(COUNT) && sleep 0.2
	$(eval COUNT=$(shell echo $$(( $(COUNT) + 1 ))))

	# Salva o novo valor de COUNT no arquivo
	@echo $(COUNT) > $(COUNT_FILE)

bonus:$(BON)
	cd libft && make compile && make 
	
	cc $(FLGS) $(BONUS) $(LIB) $(MINX_FLAG) -o $(NAME)
	echo "╔══════════════════════════╗"
	echo "║ ✅ Compiled Successfully!║"
	echo "╚══════════════════════════╝"
	@rm -f $(COUNT_FILE)
	

clean: $(fclean)
	$(RM)  $(SRCS)
	$(RM)  $(BON)
	$(RM)  $(OBJS_CLI)
	cd ./libft && make clean
		@rm -f $(COUNT_FILE)
fclean: $(clean)
	$(RM) $(NAME)
	@rm -f $(COUNT_FILE)
	make clean


re: fclean all

exec:
	cc	-g $(FLGS)  $(SRCS) $(BONUS) -lbsd
		@rm -f $(COUNT_FILE)

norm: 
	 yes y|	python3 -m c_formatter_42 -c $(FILES)
		@rm -f $(COUNT_FILE)

normi:
	norminette $(FILES)
	norminette $(BONUS)
	cd ./libft && norminette
		@rm -f $(COUNT_FILE)
	


