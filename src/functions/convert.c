/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 15:30:31 by eliu              #+#    #+#             */
/*   Updated: 2018/05/20 16:05:37 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		convert(int	x, char type)
{
	int	value;

	value = 0;
	// register
	if (type == 'r')
	{
		return (x);
	}
	// direct
	else if (type == 'd')
	{
		
		return (value);
	}	
	else if (type == 'i')
	{

		return (value);
	}
	ft_putendl("conversion error in convert.c");
	return (
}
