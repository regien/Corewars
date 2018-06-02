# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/22 16:31:53 by gmalpart          #+#    #+#              #
#    Updated: 2018/06/01 05:55:31 by eliu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CWR	= corewar
ASM	= asm

# src / obj files
SRC		=	read_file.c \
			constructor.c \
			checker.c \
			print.c \
			init_ops.c \
			fetch_and_exec.c \
			function_controller.c \
			conversions.c \
			parseargs.c \
			set_up_player.c \
			error_handling.c \
			winner.c

FUNCTION_PATH = src/functions/
FUNCTION_FILES = live.c \
				ld.c \
				st.c \
				add.c \
				sub.c \
				and.c \
				or.c \
				xor.c \
				zjmp.c \
				ldi.c \
				sti.c \
				fork.c \
				lld.c \
				lldi.c \
				lfork.c \
				aff.c \
				register_functions.c \
				find_value.c \
				endianess.c

FUNCTION_HELPERS = types.c \
				   type_combinations.c

FUNCTION_ALL =	$(FUNCTION_FILES) \
				 $(FUNCTION_HELPERS)

#PENDEJADA = $(SRC) $(FUNCTION_FILES) $(FUNCTION_HELPERS)

# 3
SRCALL	= $(SRC) 
SRCALL	+= corewar.c
#SRCALL	+= assembler.c

SRCCW	= $(SRC)
SRCCW	+= corewar.c

#SRCAS	= $(SRC)
#SRCAS	+= assembler.c

DIRFUNCT = ./src/functions/

OBJ	= $(addprefix $(OBJDIR),$(SRCALL:.c=.o))
OBJCW	= $(addprefix $(OBJDIR),$(SRCCW:.c=.o))
OBJFUNCS = $(addprefix $(OBJFUNCDIR),$(FUNCTION_ALL:.c=.o))
#OBJAS	= $(addprefix $(OBJDIR),$(SRCAS:.c=.o))

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

# Redo the objs directory for the src/functions
OBJFUNCDIR = ./obj/


all: obj $(FT_LIB) $(CWR)

test: obj $(FT_LIB) $(ASM)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<

#special call for .c files inside src/functions/
$(OBJFUNCDIR)%.o:$(DIRFUNCT)%.c
	$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	make -C $(FT)

$(CWR): $(OBJ) $(OBJFUNCS)
	$(CC) $(CFLAGS) $(OBJCW) $(OBJFUNCS) $(FT_LNK) -lm -o $(CWR)
#	$(CC) $(CFLAGS) $(OBJAS) $(FT_LNK) -lm -o $(ASM)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean

fclean: clean
	rm -rf $(CWR)
	rm -rf $(ASM)
	make -C $(FT) fclean

re: fclean all
