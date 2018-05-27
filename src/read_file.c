/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 22:22:19 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/22 16:34:07 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

int		read_files(int players, t_vm *vm)
{
	int	i;

	i = 0;
//	clear_vm_mem(vm); clear vm its now a 2 lines while loop in init_vm
	while (i < players)
	{
		if (check_magic_number(vm->champs[i].fd))
			return (0);
		if (set_champ_name(&(vm->champs[i])))
			return (0);
		if (set_champ_size(&(vm->champs[i])))
			return (0);
		if (set_champ_comment(&vm->champs[i]))
			return (0);
		set_vm_memory(vm, i, vm->players);
		i++;
	}
	return (1);

}

int		set_champ_name(t_champ *champ)
{
	int r;

	r = read(champ->fd, champ->name, PROG_NAME_LENGTH + 4);
	(champ->name)[PROG_NAME_LENGTH + 4] = '\0';
	//ft_printf("name: %s\n", champ->name);
	if (!champ->name[0])
	{
		ft_putstr_fd("name starts with null terminator\n", 2);
		return (1);
	}
	return (0);
}


int		set_champ_size(t_champ *champ)
{
	read(champ->fd, &(champ->size), 4);
	convert_big_endian(&(champ->size));
	//ft_printf("size: %d\n", champ->size);
	if (champ->size == 0 || champ->size > CHAMP_MAX_SIZE)
	{
		ft_putstr_fd("champ is too big..., or no champ\n", 2);
		return (1);
	}
	return (0);
}

int		set_champ_comment(t_champ *champ)
{
	read(champ->fd, champ->comment, COMMENT_LENGTH + 4);
	(champ->comment)[COMMENT_LENGTH + 4] = '\0';
	if (!champ->comment[0])
	{
		ft_putstr_fd("comment starts with null terminator\n", 2);
		return (1);
	}
	return (0);
}

void	set_vm_memory(t_vm *vm, int i, int players)
{
	int mem_start;

	mem_start = MEM_SIZE / players * i;
//	vm->champs[i].processes = set_process(&(vm->memory[0]), mem_start);
	read(vm->champs[i].fd, &(vm->memory[mem_start]), vm->champs[i].size);
	//ft_printf("memory: %x\n", vm->memory[mem_start + vm->champs[i].size - 1]);
}
