/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 18:52:32 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/24 22:18:32 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void	print_commands(t_ops *o, t_label *l)
{
	int i;
	while (o)
	{
		if (l && o->index == l->index)
		{
			ft_printf("%-10d:%8s:\n", l->index, l->label_name);
			l = l->next;
		}
		ft_printf("%-5d(%-3d):", o->index, o->size);
		ft_printf("%12s", o->op_name);
		i = -1;
		while (++i < op_table[(int)o->op_code - 1].args)
			ft_printf("%12s", o->arg_name[i]);
		ft_printf("\n%11s", " ");
		ft_printf("%12d", o->op_code);
		if (op_table[(int)o->op_code - 1].descriptor)
			ft_printf("%6hhu", o->descriptor);
		else
			ft_printf("%6s", " ");
		i = -1;
		while (++i < op_table[(int)o->op_code - 1].args)
			ft_printf("%12d", o->args[i]);
		ft_printf("\n\n");
	 	o = o->next;
	} 
}

int		get_total_size(t_ops *ops)
{
	while (ops->next)
		ops = ops->next;
	return (ops->index + ops->size);
}

void	write_header(int fd, t_header *header)
{
	unsigned int	magic_number;
	int				tmp;

	magic_number = COREWAR_EXEC_MAGIC;
	tmp = convert_b_endian(magic_number);
	write(fd, &tmp, 4);
	write(fd, header->prog_name, PROG_NAME_LENGTH + 4);
	tmp = convert_b_endian(header->prog_size);
	write(fd, &tmp, sizeof(unsigned int));
	write(fd, header->comment, COMMENT_LENGTH + 4);
}

void	write_op(int fd, t_ops *op)
{
	short	s;
	int		d;
	char	c;
	int		i;

	write(fd, &(op->op_code), 1);
	if (op_table[(int)op->op_code - 1].descriptor)
		write(fd, &(op->descriptor), 1);
	i = -1;
	while (++i < op_table[(int)op->op_code - 1].args)
	{
		if (op->arg_sizes[i] == 1)
		{
			c = op->args[i];
			write(fd, &c, 1);
		}
		else if (op->arg_sizes[i] == 2)
		{
			s = op->args[i];
			s = convert_b_endian_short(s);
			write(fd, &s, 2);
		}
		else if (op->arg_sizes[i] == 4)
		{
			d = op->args[i];
			d = convert_b_endian(d);
			write(fd, &d, 4);
		}
	}

}

void	write_file(int fd, t_ops *ops, t_label *labels, t_header *header)
{
	labels = 0;
	header->prog_size = get_total_size(ops);
	write_header(fd, header);
	while (ops)
	{
		write_op(fd, ops);
		ops = ops->next;
	}
}














