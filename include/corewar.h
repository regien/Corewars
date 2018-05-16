/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:26:06 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/15 17:43:30 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

typedef struct s_process
{
	char	*PC;
	int		regs[16];
	char	carry;
	int		cycle_counter;
	char	state;
	char	live;
}				t_process;

typedef struct	s_champ
{
	char		plyr_nbr;
	char		*name[128]
	char		*comment[2048]
	int			size;
	t_process	*processes;
}				t_champ;

typedef struct	s_vm
{
	char	memory[MEM_SIZE];
	int		cycles;
	int		cycle_to_die;
	t_champ	champs[MAX_PLAYERS];
}				t_vm;
