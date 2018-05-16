/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 23:23:05 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/16 01:11:28 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

int main(int argc, char **argv)
{
	t_vm	vm;
	
	if (argc < 2)
		return (0);
	vm.players = argc - 1; //test
	set_champs(&(vm.champs[0]), argv[1]);
	set_champs(&(vm.champs[1]), argv[2]);
	if (!read_files(vm.players, &vm))
		return (1);
}
