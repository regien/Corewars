/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 03:18:56 by eliu              #+#    #+#             */
/*   Updated: 2018/05/23 21:05:53 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Takes 2 paramters. It stores the first parameter's value (which is a reg)
**	into the second (both).
**	// To number:	
**	st (r4, 34) stores the content of r4 at the address PC + 34 % IND_MOD.
**	// To register:	
**	st (r3, r8) copies the content of r3 into r8.
*/

void	ft_st(t_process *process)
{
	if (reg(process, 0) && reg_ind(process, 1))
	{
		process->args.v[1] = process->args.v[0] == 0;
	}
}
