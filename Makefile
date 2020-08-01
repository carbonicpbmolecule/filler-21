NAME		=	jirwin.filler
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -O2

FILLER_SRC	=	main.c				free.c			\
				init.c				parse_player.c	\
				parse_board.c		parse_token.c	\
				calc_heat_map.c		calc_coords.c	\
				parse_size.c

LIB_DIR		=	libft
LIB			=	libft/libft.a
INC			=	libft/inc
LIB_H		=	libft/inc/libft.h

FILLER_H	=	filler.h

all: $(NAME)

$(LIB) : $(LIB_DIR)
	make -C $(LIB_DIR)

$(NAME): $(FILLER_SRC) $(LIB) $(INC) $(LIB_H) $(FILLER_H)
	$(CC) $(FLAGS) -o $(NAME) $(FILLER_SRC) $(LIB) -I $(INC)

clean:
	rm -f $(NAME)

fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all
