/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_label_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:50:48 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/25 17:00:51 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int		get_label_arg(int arg_num, t_ops *ops, t_label *labels)
{
	char	*str;
	int		i;

	str = ops->arg_name[arg_num];
	if (!str)
		return (1);
	i = 0;
	while (str[i] == DIRECT_CHAR || str[i] == LABEL_CHAR)
		i++;
	while (labels)
	{
		if (!ft_strcmp(labels->label_name, &str[i]))
			break ;
		labels = labels->next;
	}
	if (!labels)
		return (ft_printf_err("unkown label %s\n", ops->arg_name[arg_num]));
	ops->args[arg_num] = labels->index - ops->index;
	ops->arg_name[arg_num] = ft_strdup(&str[i]);
	free(str);
	return (0);
}

void	clean_label(t_label *labels)
{
	t_label *buf;
	int		i;

	buf = labels;
	i = 0;
	while (buf)
	{
		while (buf->label_name[i] && buf->label_name[i] != LABEL_CHAR)
			i++;
		buf->label_name[i] = 0;
		buf = buf->next;
	}
}

int		set_label_vars(t_label *labels, t_ops *ops)
{
	int		ret;

	ret = 0;
	clean_label(labels);
	while (ops)
	{
		if (ops->label_arg[0])
			ret = get_label_arg(0, ops, labels);
		if (ops->label_arg[1])
			ret = get_label_arg(1, ops, labels);
		if (ops->label_arg[2])
			ret = get_label_arg(2, ops, labels);
		if (ret)
			break ;
		ops = ops->next;
	}
	return (ret);
}
