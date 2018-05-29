/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circulate_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 02:38:38 by eliu              #+#    #+#             */
/*   Updated: 2018/05/29 02:40:31 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		circulate_index(int index)
{
	printf("Index before entering circulate: %d\n", index);
	while (index < 0)
	{
		index = index + MEM_SIZE;
	}
	while (index >= MEM_SIZE)
	{
		index = index - MEM_SIZE;
	}
	printf("Index after exiting circulate: %d\n", index);
	return (index);
}
