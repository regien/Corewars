# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adubugra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/07 18:20:10 by adubugra          #+#    #+#              #
#    Updated: 2018/05/15 18:12:22 by adubugra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CWR	= corewar
ASM	= asm

# src / obj files
SRC		= 

SRCALL	= $(SRC)
SRCALL	+= corewar.c
SRCALL	+= assembler.c

SRCPS	= $(SRC)
SRCPS	+= corewar.c

SRCCH	= $(SRC)
SRCCH	+= assembler.c

OBJ	= $(addprefix $(OBJDIR),$(SRCALL:.c=.o))
OBJCH	= $(addprefix $(OBJDIR),$(SRCCH:.c=.o))
OBJPS	= $(addprefix $(OBJDIR),$(SRCPS:.c=.o))

# compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

# ft library
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft

# directories
SRCDIR	= ./src/
INCDIR	= ./include/
OBJDIR	= ./obj/

all: obj $(FT_LIB) $(CWR)

test: obj $(FT_LIB) $(TESTER)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	make -C $(FT)

$(CWR): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJCH) $(FT_LNK) -lm -o $(CWR)
	$(CC) $(CFLAGS) $(OBJPS) $(FT_LNK) -lm -o $(ASM)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(TESTER)
	make -C $(FT) fclean

re: fclean all
