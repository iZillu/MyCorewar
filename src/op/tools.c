/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 21:04:55 by hmuravch          #+#    #+#             */
/*   Updated: 2019/01/18 15:54:49 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_coach		*clone_coach(t_coach *crnt_coach, int shift)
{
	int		i;
	t_coach	*new_coach;

	i = 0;
	shift = (coach->pc + shift) % MEM_SIZE;
	// new_coach = init_coach(crnt_coach->player, shift); 
	while (++i < REG_NUMBER)
		new_coach->reg[i] = crnt_coach->reg[i];
	new_coach->carry = crnt_coach->carry;
	new_coach->last_cycle_check = crnt_coach->last_cycle_check;
	return (new_coach);
}

int			convert_bytecode(const char *map, int size, int position)
{
	int		i;
	int		res;
	bool	minus;

	i = 0;
	res = 0;
	minus = (map[(position) % MEM_SIZE] & 128) ? true : false ;
	while (size)
	{
		if (minus)
			res += ((map[(position + size - 1) % MEM_SIZE] ^ 255) << (i * 8));
		else
			res += map[(position + size - 1) % MEM_SIZE] << (i * 8);
		i++;
		size--;
	}
	if (minus)
		res = ~res;
	return (res);
}

void		convert_integer(char *map, int position, int value, int size)
{
	int		i;

	i = 0;
	while (size)
	{
		map[(position + size - 1) % 255] = (char)((value >> i) & 255);
		i += 8;
		size--;
	}
}

int			parse_args(t_cw *cw, t_coach *coach, int num, t_op *op)
{
	int		id;
	int		res;
	int		position;

	res = 0;
	id = cw->map[(coach->pc + coach->shift) % MEM_SIZE];
	if (coach->arg_type[num] == T_REG)
		res = coach->reg[id];
	else if (coach->arg_type[num] == T_DIR)
		res = convert_bytecode(cw->map, op->label_size, coach->pc + coach->shift);
	else if (coach->arg_type[num] == T_IND)
	{
		position = convert_bytecode(cw->map, IND_SIZE, coach->pc + coach->shift);
		if (coach->op_id != 1 && coach->op_id != 13)
			position = position % IDX_MOD;
		res = convert_bytecode(cw->map, DIR_SIZE, coach->pc + position);
	}
	coach->shift += shift_size(coach->arg_type[num], op);
	return (res);
}
