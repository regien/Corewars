/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:58:56 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/24 19:06:39 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

char	*get_full_line(int fd)
{
	char	*str;
	int		i;
	int		ret;

	while ((ret = get_next_line(fd, &str)) >= 0)
	{
		if (!str)
			break ;
		i = 0;
		while (str[i] && WHITESPACE(str[i]))
			i++;
		if (str[i] == 0)
		{
			free(str);
			str = 0;
		}
		else
			break ;
	}
	if (str)
		return(&str[i]);
	return (str);
}
/*
**checks if there is a label and returns it, also moves the pointer to the command
**if there is one. Else frees the string and sets the pointer to NULL;
*/
t_label		*get_label(char **full_str)
{
	int		i;
	t_label	*new_label;
	char	*str;

	i = 0;
	str = *full_str;
	while (!WHITESPACE(str[i]) && str[i] && str[i] != LABEL_CHAR)
		i++;
	if (str[i] != LABEL_CHAR)
		return (0);
	new_label = init_label();
	new_label->label_name = ft_strsub(str, 0, (size_t)i + 1);
	*full_str = &str[i + 1];
	while (**full_str && WHITESPACE(**full_str))
		(*full_str)++;
	if (**full_str == 0)
	{
		free(*full_str);
		*full_str = 0;
	}
	return (new_label);
}

/*
**returns the list with all the ops and labels created
*/
t_ops	*set_argument_list(int fd, t_label **label_root)
{
	t_ops	*root;
	t_ops	*last;
	t_label	*buf;
	char	*str;

	last = 0;
	root = 0;
	while ((str = get_full_line(fd)) != 0)
	{
		buf = add_label(label_root, get_label(&str));
		if (!str)
			continue ;
		if (!add_ops(&root, &last, str))
			return (0);
		if (buf)
			buf->index = last->index;
	}
	return (root);
}

int		get_label_arg(int arg_num, t_ops *ops, t_label *labels)
{
	while (*(ops->arg_name[arg_num]) == DIRECT_CHAR || *(ops->arg_name[arg_num]) == LABEL_CHAR)
		(ops->arg_name[arg_num])++;
	while (labels)
	{
		if (!ft_strcmp(labels->label_name, ops->arg_name[arg_num]))
			break ;
		labels = labels->next;
	}
	if (!labels)
		return (ft_printf("ERROR, unkown label %s\n", ops->arg_name[arg_num]));
	ops->args[arg_num] = labels->index - ops->index;
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













