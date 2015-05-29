##
## Makefile for minitalk in /home/sayyou_y/rendu/PSU-System-Unix/PSU_2014_minitalk
## 
## Made by Youssef Sayyouri
## Login   <sayyou_y@epitech.net>
## 
## Started on  Sat Mar 21 16:54:16 2015 Youssef Sayyouri
## Last update Mon Mar 23 15:27:12 2015 Youssef Sayyouri
##

CC	= gcc -D _BSD_SOURCE -D _POSIX_SOURCE

RM	= rm -f

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -ansi -pedantic
CFLAGS	+= -I.

NAME_S	= ./server/server

NAME_C	= ./client/client

SRC_S	= func_base.c		\
	  ./server/server.c	\
	  ./server/pow.c	\

SRC_C	= func_base.c		\
	  ./client/client.c	\

OBJS_S	= $(SRC_S:.c=.o)

OBJS_C	= $(SRC_C:.c=.o)

all		: $(NAME_S) $(NAME_C)

$(NAME_S)	: $(OBJS_S)
		  $(CC) $(OBJS_S) -o $(NAME_S) $(CFLAGS)

$(NAME_C)	: $(OBJS_C)
		  $(CC) $(OBJS_C) -o $(NAME_C) $(CFLAGS)

clean	:
	  $(RM) $(OBJS_S) $(OBJS_C)

fclean	: clean
	  $(RM) $(NAME_S) $(NAME_C)

re	: fclean all

.PHONY	: all clean flcean re
