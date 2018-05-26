/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:26:06 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/25 17:23:39 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
#include "../libft/libft.h"
#include <stdio.h>

#define IND_SIZE				2
#define REG_SIZE				4
#define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

#define MAX_ARGS_NUMBER			4
#define MAX_PLAYERS				4
#define MEM_SIZE				(4*1024)
#define IDX_MOD					(MEM_SIZE / 8)

#define CHAMP_MAX_SIZE			(MEM_SIZE / 6)
#define COMMENT_CHAR			'#'
#define LABEL_CHAR				':'
#define DIRECT_CHAR				'%'
#define SEPARATOR_CHAR			','
#define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"
#define NAME_CMD_STRING			".name"
#define COMMENT_CMD_STRING		".comment"
#define REG_NUMBER				16
/*
** types of arguments accepted
*/
#define CYCLE_TO_DIE			1536
#define CYCLE_DELTA				50
#define NBR_LIVE				21
#define MAX_CHECKS				10
/*
** types of arguments accepted
*/
typedef char	t_arg_type;

#define T_REG					1
#define T_DIR					2
#define T_IND					4
#define T_LAB					8
/*
**header definitions
*/
# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

# define FETCH 1
# define WAIT 2
# define EXEC 3

typedef struct	s_ops
{
	char			*op_name;
	char			**arg_name;
	int				index;
	int				size;
	char			op_code;
	char			descriptor;
	int				args[3];
	char			arg_sizes[3];
	char			label_arg[3];
	struct s_ops	*next;
}				t_ops;

typedef struct 	s_label
{
	int				index;
	char			*label_name;
	struct s_label	*next;
}				t_label;

typedef struct	s_header
{
  char				prog_name[PROG_NAME_LENGTH + 5];
  unsigned int		prog_size;
  char				comment[COMMENT_LENGTH + 5];
}				t_header;

typedef struct	s_op
{
	char		truncate;
	char		args; //number of args
	char		descriptor; //the byte that describes what the following are -- ops with only one option of arg has no descriptor
	int			cycles;
	char		accepted_args[3];
	char		op_code;
}				t_op;

t_op	op_table[16];

int				convert_b_endian(unsigned int num);

int				convert_b_endian_short(unsigned short num);
/*
**ASS_NAME_COMMENT
*/
int				set_header(t_header *h, int fd);
/*
**ASM_GET_COMMANDS
*/
t_ops			*set_argument_list(int fd, t_label **label_root);

int				set_label_vars(t_label *labels, t_ops *ops);
/*
**ASM_CONSTRUCTORS
*/
t_ops			*init_op(void);

t_ops			*add_ops(t_ops **root, t_ops **last, char *str);

t_label			*add_label(t_label **root, t_label *new);

t_label			*init_label(void);
/*
**ASM_OP_TABLE
*/
int				get_op_code(char *op_name, t_ops *op);
/*
**ASM_OP_BUILDER
*/
int				set_op_name(char **strreal, t_ops *op);

int				set_arguments(char **strreal, t_ops *op);

int				set_size(t_ops *op);

int				get_arguments_and_sizes(t_ops *op);
/*
**ASM_OP_BUILDER_HELPERS
*/
int				check_argument(char *str);

void			remove_comments(char *str);
/*
**ASM_INIT_OPS
*/
void			asm_init_ops(t_op *ops);
void			asm_set_ops_accepted_args(t_op *ops);
/*
**ASM_PRINT
*/
void			print_commands(t_ops *o, t_label *l);

void			write_file(int fd, t_ops *ops, t_label *labels, t_header *header);
#endif
