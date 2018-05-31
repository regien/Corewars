/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:04:29 by gmalpart          #+#    #+#             */
/*   Updated: 2018/05/30 22:58:04 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Just initiliazing some values to 0, prefer to do it outside the main
** for space purposes.
*/

void		init_vm(t_vm *vm)
{
	int		i;
	t_flags *holder;

	i = -1; // clear vm memory
	while (++i < MEM_SIZE)
		vm->memory[i] = 0;
	vm->last_to_live = 0;
	vm->nbr_checks = 0;
	vm->nbr_lives = 0;
	vm->players = 0;
	vm->cycles = 0;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->cycle_to_die_last = CYCLE_TO_DIE;
	holder = &(vm->flags_args);
	holder->visual = 0;
	holder->dump = 0;
	holder->nbrdump = 0;
	// DUMMY TESTING
	vm->flags_args.aff = 1;

	vm->total_lives = 0;
	vm->cycle_to_die_last = CYCLE_TO_DIE;
}

int		set_dump_number(int ac, int *i, char **av, t_flags *flags)
{
	int temp;

	*i = *i + 1;
	if (*i >= ac)
		simple_usage(-1, av[0]);
	if ((av[*i]))
	{
		check_for_chars(av[*i]);
		temp = ft_atoi(av[*i]);
		if (temp < 0)
			general_exit(g_ivlid_dump, -1);
		flags->dump = 1;
		flags->nbrdump = ft_atoi(av[*i]); // you might modify the atoi for a atoll
	}
	else
		general_exit(g_ivlid_dump, -1);
	return (1);
}

void	parser_args(int ac, char **av, t_vm *vm)
{
	int		i;
	char	dump_cont;

	dump_cont = 0;
	i = 0;
	while (++i < ac)
	{
		if ((ft_strequ(av[i], "--help") != 0 || \
		ft_strequ(av[i], "-h") != 0))
			simple_usage(-1, av[0]);
		else if (ft_strequ(av[i], "-dump") != 0)
		{
			set_dump_number(ac, &i, av, &(vm->flags_args));
			dump_cont++;
			if (dump_cont >= 2)
				general_exit(g_ivlid_dump, -1);
		}
		else if (ft_strequ(av[i], "-n") != 0)
			get_nbr_player(ac, &(i), av, vm);
		else if (check_name_champ(av[i]) == 1)
			wrap_set_up_player(ac, &(i), av, vm);
		else
			simple_usage(-1, av[0]);
	}
	check_duplicate_players(vm);
}
