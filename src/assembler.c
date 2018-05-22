/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:00:25 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/22 14:55:00 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incude/asm.h"

int		main(int argc, char **argv)
{
	//check if file is valid
	//write magic number
	//write everything on ram
	//get name
	//write size
	//err if there is no NAME_CMD
	//write name
	//get comment
	//err if there is no COMMENT_CMD
	//write comment
	//write command
	//err if command doesn't exist
	//write descriptor
	//write arguments
	//err if argument is greater than possible
	//if argument is indirect, do math if its not label. add to list if it is
	//if comment, skip
	//if label, add label name and place in memory for linkedlist
	//if labels are not formed by label_chars

}
