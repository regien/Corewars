/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:26:06 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/16 14:12:47 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

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

typedef struct s_process
{
  //funtion pointer
	char	*pc;
	int		regs[16];
	char	carry;
	int		cycle_counter;
	char	state;
	char	live;
}				t_process;

typedef struct	s_champ
{
	int				fd;
	char			plyr_nbr;
	char			name[PROG_NAME_LENGTH + 5]; //assembler has to add 4 extra empty bytes to each
	char			comment[COMMENT_LENGTH + 5];
	unsigned int	size;
	t_process		*processes;
}				t_champ;

typedef struct	s_vm
{
	char	memory[MEM_SIZE];
	int		players;
	int		cycles;
	int		cycle_to_die;
	t_champ	champs[MAX_PLAYERS];
}				t_vm;

typedef struct		header_s
{
  unsigned int		magic;
  char				prog_name[PROG_NAME_LENGTH + 1];
  unsigned int		prog_size;
  char				comment[COMMENT_LENGTH + 1];
}					header_t;


int			read_files(int players, t_vm *vm);

int			check_magic_number(int fd);

int			set_champ_name(t_champ *champ);

int			set_champ_comment(t_champ *champ);

int			set_champ_size(t_champ *champ);

void		set_vm_memory(t_vm *vm, int i, int players);

void		set_champs(t_champ *champ, char *filename);

t_process	*set_process(char *pc_start);

void		clear_vm_mem(t_vm *vm);

void		convert_big_endian(unsigned int *num);

void		dump_memory(t_vm vm);

// 			Function protyping 

void			live(t_process *process);

t_process		*add(char first, char second, char third);
t_process		*sub(char first, char second, char third);


t_process		*zjmp(char index);
t_process		*fork(char index);
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

