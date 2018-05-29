/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 23:23:05 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/29 04:46:54 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_op		g_ops[OP_NUMBER + 1];

int main(int argc, char **argv)
{
	t_vm	vm;
	
	if (argc < 2)
		simple_usage(-1, argv[0]);
	init_vm(&(vm));
	parser_args(argc, argv, &(vm));
	if (!read_files(vm.players ,&vm))
		return (1);
	// init_op is here for testing reasons
	init_ops(g_ops);
	ft_printf("%x\n", vm.champs[0].processes->pc);
	//ft_printf("procceses->pc = |%x|\n", vm.champs[0].processes->pc);
	//ft_printf("pendjeada = |%d|\n", vm.champs[0].lives_counted);
	controller(&vm);
	//play_game(vm);
	dump_memory(vm);
	// declare_winner(&(vm));
}
