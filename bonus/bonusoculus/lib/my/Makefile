##
## Makefile for make in /home/arzel_p/rendu/Piscine_C_multip/lib/my
##
## Made by Paskal Arzel
## Login   <arzel_p@epitech.net>
##
## Started on  Wed Oct 28 11:54:24 2015 Paskal Arzel
## Last update Sun Jan  3 21:03:55 2016 Paskal Arzel
##

CC      = gcc -g

RM      = rm -f

SRC     = chainefull.c \
	  fullnul.c \
	  max.c \
	  min.c \
		deletele.c \
	  my_pointvalue.c \
	  my_find_prime_sup.c \
		my_get_cnbr.c \
	  my_getnbr.c \
	  my_isneg.c \
	  my_is_prime.c \
	  my_power_rec.c \
	  my_putchar.c \
	  my_putstrhid.c \
	  my_put_longnbr_base.c \
	  my_put_nbr.c \
	  my_put_nbr_base.c \
	  my_put_hexamaj.c \
	  my_put_unbr.c \
	  my_put_nbr_inf.c \
	  my_putstr.c \
	  my_putstrss.c \
	  my_revstr.c \
	  my_showmem.c \
	  my_showstr.c \
	  my_sort_int_tab.c \
	  my_square_root.c \
	  my_strcapitalize.c \
	  my_strcat.c \
	  my_strcmp.c \
	  my_strcpy.c \
	  my_str_isalpha.c \
	  my_str_islower.c \
	  my_str_isnum.c \
	  my_str_isprintable.c \
	  my_str_isupper.c \
	  my_strlen.c \
	  my_strlowcase.c \
	  my_strncat.c \
	  my_strncmp.c \
	  my_strncpy.c \
	  my_strstr.c \
	  my_strupcase.c \
	  my_swap.c \
	  posneg.c

LDFLAGS += -L./lib/my/ -lmy

CFLAGS  += -Iinclude

OBJ     = $(SRC:.c=.o)

OBJ2    = infinadd.o

LIB     = libmy.a

AR      = ar rc

RAN     = ranlib

OBJ3    = *.o

NAME    = infin_mul

all: $(NAME) clean

$(NAME): $(OBJ)
	$(CC) -c $(SRC)
	$(AR) $(LIB) $(OBJ)
	$(RAN) $(LIB)
clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ2)
	$(RM) $(OBJ3)
fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all re clean fclean
