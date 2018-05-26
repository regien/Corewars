/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_constructors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:39:21 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/25 16:21:25 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

t_ops	*init_op(void)
{
	t_ops *new;

	new = malloc(sizeof(t_ops));
	if (!new)
		return (0);
	new->op_name = 0;
	new->index = 0;
	new->size = 0;
	new->op_code = 0;
	new->descriptor = 0;
	new->next = 0;
	new->label_arg[0] = 0;
	new->label_arg[1] = 0;
	new->label_arg[2] = 0;
	return (new);
}

t_ops	*add_ops(t_ops **root, t_ops **last, char *str)
{
	t_ops	*new;

	if (!str || !root)
		return (0);
	if ((new = init_op()) == 0)
		return (0);
	if (*root == 0)
		*root = new;
	if (set_op_name(&str, new))
		return (0);
	if (!get_op_code(new->op_name, new))
		return (0);
	if (set_arguments(&str, new))
		return (0);
	if (get_arguments_and_sizes(new))
		return (0);
	set_size(new);
	if (*root != new)
		new->index += (*last)->index + (*last)->size;
	if (*last)
		(*last)->next = new;
	*last = new;
	return (new);
}

t_label	*init_label(void)
{
	t_label	*new;

	new = malloc(sizeof(t_label));
	if (!new)
		return (0);
	new->label_name = 0;
	new->index = 0;
	new->next = 0;
	return (new);
}

t_label	*add_label(t_label **root, t_label *new)
{
	if (!new)
		return (0);
	if (*root == 0)
		return (*root = new);
	if ((*root)->next)
		new->next = (*root)->next;
	(*root)->next = new;
	return (new);
}
