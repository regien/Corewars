/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 03:18:56 by eliu              #+#    #+#             */
/*   Updated: 2018/05/16 04:49:52 by eliu             ###   ########.fr       */
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

t_process		*st(char first, char second)
{
	t_process	*process;

	process = NULL;
	// If the first parameter is a value:
	//	{
		// If we are storing in a register:
		value_at_address_of(second) = value_at_address_of(first);
		
		// If we are storing in a number:
second = store(value_of_address_at(first), (PC + value_at_address(second) % IND_MOD));
		store(value_of_address_at(first), (PC +  % IND_MOD), second);
	//	}
	return (process);
}


