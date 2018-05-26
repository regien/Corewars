/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 01:05:08 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/25 16:41:48 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

int		check_magic_number(int fd)
{
	unsigned int	magic_nbr;

	read(fd, &magic_nbr, sizeof(unsigned int));
	convert_big_endian(&magic_nbr);
	if (magic_nbr != COREWAR_EXEC_MAGIC)
		return (ft_printf_err("file not valid... no magic number\n"));
	return (0);
}

void	set_index(int *index, int diff)
{
	*index += diff;
	if (*index >= MEM_SIZE)
		*index -= MEM_SIZE;
}
