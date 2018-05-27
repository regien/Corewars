/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudo1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 21:33:29 by eliu              #+#    #+#             */
/*   Updated: 2018/05/26 23:19:27 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


// ASSUMPTIONS : 
// when fork and lfork are called, an exact copy of the original registry is
// made at the new index of the new process.
// 
// processes only care about correct parameters after being fetched.
// if the opcode changes, the function still attempts to execute the original
// op code.
// EX: 
// [01] [ff] [ff] [ff] [ff]
// OVERWRITE BY ENEMY:
// [xx] [ff] [ff] [ff] [ff]
// still executes live even though the op_code was overwritten before the time
// of actual execution.


/*
**	TODO ESTE ES PSEUDO CODE PORQUE SOY PENDEJO Y NO PUEDO ESCRIBIR ALGO MAS.
**	GATOS LOCOS PARA SIEMPRE ESE WEY.
**

	check for mods at header:
		-main mods:
			t_process
		** SUMMARY: proccess is being moved to VMstruct and no longer initializes
		in read_files	

**	gerardo | ezekiel
**		-mod structure in t_champs
			move processes to the VM

	GAME START HERE
		begining of while loop (check functions below)

// gerardo supossion:
	A TURN
		i = 0;
		while (i < vm->players)
			check_index <- look for functions
			++i;
			
	
// ezekiel NOTES:

	if PC finds an instruction 0-16 (01 - 10 in hex) wait for the proper amount
	of cycles of THAT instruction. 
	if not, increment by 1 in VM memory until it finds one.

	after the Process has waited for X cylces, attempt to execute by reading
	encoding byte to see if it can be executed properly.
	(functions that don't take an encoding cannot fail)
	(aff is an edge case where it takes an encoding byte)
	
		check to see if encoding byte matches with all parameters passed in.
		if all parameters are good, excecute function. function modifies carry
		upon evaluating to zero (final results of operations are zero) otherwise carry = 0.

		functions return the amount the index (of PC) according to the ACB. (encoding byte)

	if functions fail, still return the index (of PC) according to ACB. (encoding byte)

	//outside if cycles reaches cycle to die, kill all processes and relink lists.
		decrease cycle to die by delta cycle.
// i have no idea idea wtf MAX_CHECKS is in the header and pdf.


	live function applies to processes and champions differently. 
		a) processes stay alive by calling live (does not need to be a player number)
												(if it is, calls live for that player)
		b) champs stay alive if processes call their player number (passsed in as paramters)


	game ends when all processes are dead.
	
	the winner is declared as the last champ to call live. 


	functions with ACB:
		IF WORKS:
			execute function and move index according to ACB
	
		IF NOT WORKS:
			don't execute function and move index according to ACB

	functions without ACB:
		always work	

*/



void	new_controller(t_vm *vm)
{
	unsigned long long long long long long long long 		vm_cycle;

	while (all_processes_are_not_dead)
	{
		// vm_cylce % CYCLE_TO_DIE = 0
		if (vm_cylce >= CYCLE_TO_DIE)
		{
			kill_processes();
			CYCLE_TO_DIE
		}
		execute_processes/instruction_inorder(vm);
	}
	declare_last_champ_to_live();
}


int		op_functionx(t_vm *vm)
{
	
}
