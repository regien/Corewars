/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:00:25 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/24 21:52:24 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int		main(int argc, char **argv)
{
	int				fd;
	t_ops			*ops;
	t_label			*labels;
	t_header		header;

	asm_init_ops(op_table);
	if (argc < 2)
		return (ft_printf("Usage: ./asm name_of_file.s\n"));
	if ((fd = open(argv[1], O_RDONLY)) < 3)
		return (ft_printf("invalid file\n"));
	ops = 0;
	labels = 0;
	if (set_header(&header, fd))
		return (1);
	if (!(ops = set_argument_list(fd, &labels)))
		return (1);
	if (set_label_vars(labels, ops))
		return (1);
	if ((fd = open("zork.cor", O_WRONLY | O_TRUNC)) < 3)
		return (1);
	write_file(fd, ops, labels, &header);

	//print_commands(ops, labels);
	/*ft_printf("name: %s\n", header.prog_name);
	ft_printf("comment: %s\n\n", header.comment);
	while (ops)
	{
		ft_printf("op: %s%\n", ops->op_name);
		ft_printf("op_code: %d\n", ops->op_code);
		ft_printf("size: %d\n", ops->size);
		ft_printf("index: %d\n", ops->index);
		ft_printf("size0: %d\n", ops->arg_sizes[0]);
		ft_printf("size1: %d\n", ops->arg_sizes[1]);
		ft_printf("size2: %d\n", ops->arg_sizes[2]);
		if (op_table[(int)ops->op_code - 1].descriptor)
			ft_printf("descriptor byte: %d\n", ops->descriptor);
		ft_printf("\n");
		ops = ops->next;
	}*/
	return (0);
}


	//check if file is valid OK
	//write magic number 
	//write everything on ram
	//get name OK
	//write size
	//err if there is no NAME_CMD OK
	//write name
	//get comment OK
	//err if there is no COMMENT_CMD OK
	//write comment
	//write command
	//err if command doesn't exist OK
	//err if there is more than one command per line
	//write descriptor
	//write arguments
	//err if there is more args than possible
	//err if argument is greater than possibl
	//err if type is not compatible
	//if argument is indirect, do math if its not label. add to list if it is
	//if comment, skip
	//if label, add label name and place in memory for linkedlist
	//err if label does not exist
	//if labels are not formed by label_chars
	//check if label names are only valid chars and not repeated
