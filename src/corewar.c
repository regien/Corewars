/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 23:23:05 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/22 16:33:55 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

int main(int argc, char **argv)
{
	t_vm	vm;
	
	if (argc < 2)
		simple_usage(-1, argv[0]);
	init_vm(&(vm));
	parser_args(argc, argv, &(vm));
	if (!read_files(vm.players ,&vm))
		return (1);
	ft_printf("%x\n", vm.champs[0].processes->pc);
	controller(&vm);
	//play_game(vm);
	dump_memory(vm);
}
