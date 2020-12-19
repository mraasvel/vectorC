# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/12/16 13:54:49 by mraasvel      #+#    #+#                  #
#    Updated: 2020/12/19 22:53:25 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libvect.a
SRC = $(shell find $(SRCDIR) -name "*.c" -exec basename {} \;)
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

# dirs
OBJDIR = obj
SRCDIR = src

#compilation
CC = gcc
CFLAGS = -Wall -Werror -Wextra
IFLAGS = -I .

all: $(NAME)
.PHONY: all clean fclean re

$(NAME): $(OBJ) libvect.h
	ar rcs $@ $(OBJ)
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) -c -o $@ $(CFLAGS) $< $(IFLAGS)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	/bin/rm -rf $(OBJ)
fclean: clean
	/bin/rm -rf $(NAME)
re: fclean all
