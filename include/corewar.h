/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:26:06 by adubugra          #+#    #+#             */
/*   Updated: 2018/06/01 21:16:27 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
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

#define OP_NUMBER				16

/*
** types of arguments accepted
*/

#define CYCLE_TO_DIE			1536
#define CYCLE_DELTA				50
#define NBR_LIVE				21
#define MAX_CHECKS				10
//#define CYCLE_COUNTER			1 //eliu | added it for organization

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

# define FETCH	1
# define WAIT	2
# define EXEC	3

/*
** flag structure
*/

struct					s_vm;
struct					s_champ;
struct					s_process;
// eliu: fixed indentation for merge
typedef struct			s_flags
{
	char				visual;
	char				dump; // boolean to check for dump
	unsigned int		nbrdump; // cycle to dump mem
	char				aff;
}						t_flags;

/*
**	not currently initializes
**	Make it match to types.c
*/

typedef struct			s_command_args
{
	int					v[3];
	// argument lectures
	// -> convert to litle endian
	// 3 is the maximen but this is read at the moment of execution
	char				type[3];
	// type [0] = 1  | 01 -> REG_CODE
	// type [1] = 2  | 10 -> DIR_SIZE
	// type [2] = 3  | 11 -> IND_SIZE
	char				args_size; // move to process
	// after reading the arguments and the encoding byte, it moves
	// the index.
	// index + args_size
}						t_command_args;


typedef struct			s_process
{
	struct s_champ		*father_champ;
	int					player_number; // only eliu branch
	int					curr_op;
	t_command_args		arg;
	char				*pc;
	int					index;
	int					regs[REG_NUMBER + 1]; // have to be initiliazed
	// regs[0] == not_used
	// regs[1] == player_number
	// everything else is set to 0; right now is initialized to -1 - somewhere
	char				carry;
	int					cycle_counter; // cycles to execute
	char				state; // review if this is being used
	// 1 FETCH
	// 2 WAIT
	// 3 EXEC
	char				live; // might be deleted , see constructor.c
	char				process_alive; //replace it for live
	char				player_alive; // adding it
	//unsigned int		cycle_to_execute; (cycle + wait_op_cycles)
	int					store_vm; // only eliu branch
	struct s_process	*next;
//	struct s_process	*prev;
	int					contador_delete_me;
}						t_process;

typedef struct			s_champ
{
	int					fd;
	char				plyr_nbr;
	char				name[PROG_NAME_LENGTH + 5]; //assembler has to add 4 extra empty bytes to each
	char				comment[COMMENT_LENGTH + 5];
	unsigned int		size;
	struct s_process	*processes;
	//gmalpart|eliu : move to the VM_structure
	int					lives_counted; // review if this is being used
}						t_champ;

// eliu: added int: cycle_delta

typedef struct			s_vm
{
	int					last_to_live;
	unsigned int		total_lives;
	int				nbr_checks;
	int					nbr_lives; // not currently in use - taco
	char				memory[MEM_SIZE];
	int					players;
//	int					cycles;
	unsigned int		cycles;
	int					cycle_to_die;
	unsigned int					cycle_to_die_last;
	struct s_champ		champs[MAX_PLAYERS];
	struct s_flags		flags_args; // adition of flags in main_vm
	//struct s_process	*processes;
}						t_vm;


/*
**	GERARDO - EZEKIEL mod
**	t_op[17] is a global variable so you dont have to allocate each time
**	it used to be a function pointer in printf format just for testing
*/

typedef struct			s_op
{
  	int					(*func_to_be)(t_vm *, t_champ *, t_process *);
	char				truncate;
	char				args; //number of args
	int					descriptor; //the byte that describes what the following are -- ops with only one option of arg has no descriptor
	int					cycles;
}						t_op;

typedef struct			header_s
{
  unsigned int			magic;
  char					prog_name[PROG_NAME_LENGTH + 1];
  unsigned int			prog_size;
  char					comment[COMMENT_LENGTH + 1];
}						header_t;

extern char				g_ivlid_dump[];
extern char				g_ivlid_nbr[];
extern char				g_ivlid_chmp[];
extern char				g_ivlid_nbrpls[];
extern char				g_ivlid_dupl[];
extern char				g_usage[];
extern t_op				g_ops[OP_NUMBER + 1];

/*
** PARSER_ARG.c
*/

void					init_vm(t_vm *vm);
int						set_dump_number(int ac, int *i, char **av, t_flags *flags);
void					set_up_player(t_vm vm, int temp, char *str);
void					parser_args(int ac, char **av, t_vm *vm);

/*
** SET_UP_PLAYERS.c
*/

void					get_nbr_player(int ac, int *i, char **av, t_vm *vm);
void					set_up_player_nbr(int nbr_player, t_vm *vm, t_champ *champs);
void					set_up_player_fd(int ac, char **av, int *i, t_vm *vm);
void					wrap_set_up_player(int ac, int *i, char **av, t_vm *vm);
	
/*
** ERROR_HANDELING.c
*/

void					general_exit(char *str, int code);
void					check_duplicate_players(t_vm *vm);
int						simple_usage(int code, char *str);
int						check_name_champ(char *str);
int						check_for_chars(char *str);

/*
** READ_FILE.c
** i made some modifications to this file, basically changing everything
** to a void to use `general_exit` to display the string as an error and
** displaying customize errors
**
** MAIN CHANGE
** Now is executed when a player is being setting up
*/

int						read_files(int players, t_vm *vm);
int						set_champ_name(t_champ *champ);
int						set_champ_size(t_champ *champ);
int						set_champ_comment(t_champ *champ);
//void					set_vm_memory(t_vm *vm, int i, int players);
void					set_vm_memory(t_vm *vm, int i, int players, t_champ *champ);

/*
** CHECKER.c
** modifications so far, is that i change the printfs to ft_putstr_fd
** and set the fd to 2 in case of error
**
** gmalpart:
** set_index is not actually currently in use or its gonna be modified
** by index_mod
*/

int						check_magic_number(int fd);
void					set_index(int *index, int diff);

/*
** CONVERSIONS.c
*/

void					convert_big_endian(unsigned int *num);
void					convert_big_endian_short(unsigned short *num);


/*
** INIT_OPS.c
** have 4 static functions inside
** REMINDER, making them static and delete FT_PUT if not used
*/

void					init_ops(t_op *ops);

/*
** FETCH_AND_EXEC.c
** REMINDER, get_type && set_arg are static, declare it
*/

void					fetch(t_process *process);
void					execute(t_vm *vm, t_process *process);

/*
** CONSTRUCTOR.c
*/

//void					set_champs(t_champ *champ, char *filename);
t_process				*set_process(char *pc_start, int mem_start, int player);
t_process				*add_process(t_champ *champ, int index);
//void					kill_process(t_process *p);

/*
** FUNCTION_CONTROLLER.c
*/

void					kill_processes(t_process **newhead);
void					controller(t_vm *vm);

/*
** WINNER.c
*/

int						procceses_alive(t_vm *vm);
int						solid_winner(t_process *proccesses);
void					display_information_winner(t_champ *champ);
void					declare_winner(t_vm *vm);


/*
** PRINT.c
*/

void					dump_memory_wrapper(t_vm vm);
void					dump_memory(t_vm vm);

/*
** FUNCTIONS
**
** Each functions has his own file inside src/functions
*/

int						ft_live(t_vm *vm, t_champ *champ, t_process *process);
int						ft_add(t_vm *vm, t_champ *champ, t_process *process);
int						ft_sub(t_vm *vm, t_champ *champ, t_process *process);
int						ft_zjmp(t_vm *vm, t_champ *champ, t_process *process);
int						ft_fork(t_vm *vm, t_champ *champ, t_process *process);
int						ft_lfork(t_vm *vm, t_champ *champ, t_process *process);
int						ft_aff(t_vm *vm, t_champ *champ, t_process *process);
int						ft_or(t_vm *vm, t_champ *champ, t_process *process);
int						ft_and(t_vm *vm, t_champ *champ, t_process *process);
int						ft_xor(t_vm *vm, t_champ *champ, t_process *process);
int						ft_ld(t_vm *vm, t_champ *champ, t_process *process);
int						ft_lld(t_vm *vm, t_champ *champ, t_process *process);
int						ft_ldi(t_vm *vm, t_champ *champ, t_process *process);
int						ft_lldi(t_vm *vm, t_champ *champ, t_process *process);
int						ft_st(t_vm *vm, t_champ *champ, t_process *process);
int						ft_sti(t_vm *vm, t_champ *champ, t_process *process);

/*
** TYPE_COMBINATIONS.c
**
** function parameter types
*/

char					any(t_process *process, int x);
char					reg_dir(t_process *process, int x);
char					dir_ind(t_process *process, int x);
char					reg_ind(t_process *process, int x);

/*
** TYPES.c
*/

char					reg_bounds(int reg);
char					reg(t_process *process, int x);
char					dir(t_process *process, int x);
char					ind(t_process *process, int x);


/*
** ENDIANESS.c
*/

void					read_4_bytes(t_vm *vm, t_process *process, int index, int i);
void				 	read_2_bytes(t_vm *vm, t_process *process, int index, int i);
void					store_big_endian(t_vm *vm, int value, int index);

/*
** CONVERT_REGISTERS.c
*/

void					print_regs(int a[]);
void					convert_if_register_number_to_value(t_process *process, int arg);
void					copy_registers(t_process *process, t_process *new);

/*
** CIRCULATE_INDEX.C
*/

int						circulate_index(int index);


/*
** FIND_VALUES.c
*/

void					find_direct(t_vm *vm, t_process *process, int index, int i);
void					find_register(t_vm *vm, t_process *process, int index, int i);
int 					find_arg_size(t_process *process, int i);
void					find_value(t_vm *vm, t_process *process, int jndex, int param);
void					store_values(t_vm *vm, t_process *process, int jndex, int argc);

#endif
