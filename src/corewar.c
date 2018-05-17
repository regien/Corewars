/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 23:23:05 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/17 01:45:14 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

int main(int argc, char **argv)
{
	t_vm	vm;
	
	if (argc < 2)
		return (0);

	vm.players = argc - 1; //Gerardo, please replace these 3 lines for
	set_champs(&(vm.champs[0]), argv[1]);//the function that checks args and 
	if (argc > 2)
		set_champs(&(vm.champs[1]), argv[2]);//sets the fd and num_of_players
	if (argc > 3)
		set_champs(&(vm.champs[2]), argv[3]);//sets the fd and num_of_players
	if (!read_files(vm.players, &vm))
		return (1);
	ft_printf("%x\n", vm.champs[0].processes->pc);
	controller(&vm);
	//play_game(vm);
	//dump_memory(vm);
}
