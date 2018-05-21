/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:26:06 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/21 05:43:22 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
#include "../libft/libft.h"
#include <stdio.h>

#define IND_SIZE				2
#define REG_SIZE				2
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


/*
** flag structure
*/
typedef struct		s_flags
{
	char			visual;
	char			dump; // boolean to check for dump
	unsigned int	nbrdump; // cycle to dump mem
}					t_flags;

typedef struct	s_command_args
{
	int		v[3];
	char	type[3];
	char	args_size;
}				t_command_args;

typedef struct	s_op
{
  	int		(*func_to_be)();
	char	truncate;
	char	args;
	int		descriptor; //ops with only one option of arg has no descriptor
	int		cycles;
}				t_op;

typedef struct	s_process
{
  	t_op			ops[16];
	int				curr_op;
	t_command_args	arg;
	char			*pc;
	int				regs[REG_NUMBER];
	char			carry;
	int				cycle_counter;
	char			state;
	char			live;
}				t_process;

typedef struct	s_champ
{
	int				fd;
	char			plyr_nbr;
	char			name[PROG_NAME_LENGTH + 5]; //assembler has to add 4 extra empty bytes to each
	char			comment[COMMENT_LENGTH + 5];
	unsigned int	size;
	t_process		*processes;
}					t_champ;

typedef struct	s_vm
{
	char			memory[MEM_SIZE];
	int				players;
	int				cycles;
	int				cycle_to_die;
	t_champ			champs[MAX_PLAYERS];
	t_flags			flags_args; // adition of flags in main_vm
}					t_vm;


typedef struct		header_s
{
  unsigned int		magic;
  char				prog_name[PROG_NAME_LENGTH + 1];
  unsigned int		prog_size;
  char				comment[COMMENT_LENGTH + 1];
}					header_t;

void		set_vm_memory(t_vm *vm, int i, int players);

t_process	*set_process(char *pc_start);


void		fetch(t_process *process);

void		init_ops(t_op *ops);

void		controller(t_vm *vm);

void		dump_memory(t_vm vm);

// 			Function protyping 

void			live(t_process *process);

t_process		*add(char first, char second, char third);
t_process		*sub(char first, char second, char third);


t_process		*zjmp(char index);
t_process		*ft_fork(char index);
t_process		*lfork(char index);
t_process		*aff(char rejester);


t_process		*or(char first, char second, char third);
t_process		*and(char first, char second, char third);
t_process		*xor(char first, char second, char third);


t_process		*ld(char first, char second);
t_process		*ldd(char first, char second);
t_process		*lldi(char first, char second, char third);

t_process		*st(char first, char second);
t_process		*sti(char first, char second, char third);


// REFACTORIZING - gmalpart and some mod in alex's functions

extern char		g_ivlid_dump[];
extern char		g_ivlid_nbr[];
extern char		g_ivlid_chmp[];
extern char		g_ivlid_nbrpls[];
extern char		g_ivlid_dupl[];
extern char		g_usage[];

/*
** PARSER.c
*/

void			init_vm(t_vm *vm);
int				set_dump_number(int ac, int *i, char **av, t_flags *flags);
void			set_up_player(t_vm vm, int temp, char *str);
void			parser_args(int ac, char **av, t_vm *vm);

/*
** SET_UP_PLAYERS.c
*/

void			get_nbr_player(int ac, int *i, char **av, t_vm *vm);
void			set_up_player_nbr(int nbr_player, t_vm *vm, t_champ *champs);
void			set_up_player_fd(int ac, char **av, int *i, t_vm *vm);
void			wrap_set_up_player(int ac, int *i, char **av, t_vm *vm);

/*
** ERROR_HANDELING.c
*/

void		general_exit(char *str, int code);
void		check_duplicate_players(t_vm *vm);
int			simple_usage(int code, char *str);
int			check_name_champ(char *str);
int			check_for_chars(char *str);

/*
** READ_FILE.c
** i made some modifications to this file, basically changing everything
** to a void to use `general_exit` to display the string as an error and
** displaying customize errors
**
** MAIN CHANGE
** Now is executed when a player is being setting up
*/

int			read_files(int players, t_vm *vm);
int			set_champ_name(t_champ *champ);
int			set_champ_size(t_champ *champ);
int			set_champ_comment(t_champ *champ);

/*
** CHECKER.c
** modifications so far, is that i change the printfs to ft_putstr_fd
** and set the fd to 2 in case of error
*/

int			check_magic_number(int fd);

/*
** CONVERSIONS.c
*/

void		convert_big_endian(unsigned int *num);
void		convert_big_endian_short(unsigned short *num);

#endif
