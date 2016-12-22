##
## MakeFile for make in /home/arzel_p/rendu/Piscine_C_J10/lib/my
##
## Made by paskal arzel
## Login   <arzel_p@epitech.net>
##
## Started on  Fri Oct  9 10:24:46 2015 Paskal Arzel
## Last update Thu Dec 22 15:34:47 2016 Paskal Arzel
##

NAME		=	wolf3d
LIB			=	-L/home/arzel_p/.froot/lib/ -llapin \
				-L/usr/local/lib \
				-lsfml-audio \
				-lsfml-graphics \
				-lsfml-window \
				-lsfml-system \
				-lm \
				-ldl -lstdc++ \
				-lmy -L ./lib/my

FLAG		=	-I./include/ -W -Wall -ansi -pedantic -I/home/arzel_p/.froot/include -g

SPR			=	src/sprite/

SRC			=	src/wolf3d.c \
				src/my_fill.c \
				src/my_set_pixel.c \
				src/inilist.c \
				src/resize.c \
				src/getscope.c \
				src/creatlist.c \
				src/freeall.c \
				src/control.c \
				src/moves.c \
				src/minimap.c \
				src/vecnorm.c \
				src/go.c \
				src/colonmaker.c \
				src/draw.c \
				src/whereami.c \
				src/sprinter.c \
				src/getpixel.c \
				jpo/sprint.c \
				$(SPR)load_sprite.c


OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc $(OBJ) $(LIB) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.c.o:
	gcc -c $< -o $@ $(FLAG)
