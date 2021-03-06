/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 21:04:55 by hmuravch          #+#    #+#             */
/*   Updated: 2019/03/31 19:27:21 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_coach	*clone_coach(t_coach *crnt_coach, int shift)
{
	int		i;
	t_coach	*new_coach;

	i = 0;
	shift = calc_pos(crnt_coach->pc + shift);
	new_coach = initialize_coach(crnt_coach->player, shift);
	while (++i < REG_NUMBER)
		new_coach->reg[i] = crnt_coach->reg[i];
	new_coach->carry = crnt_coach->carry;
	new_coach->last_cycle_check = crnt_coach->last_cycle_check;
	return (new_coach);
}

int		bytecode_to_int(const unsigned char *map, int size, int position)
{
	int		i;
	int		res;
	bool	minus;

	i = 0;
	res = 0;
	minus = (bool)(map[(position) % MEM_SIZE] & 128);
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

void	int_to_bytecode(unsigned char *map, int position, int value, int size)
{
	int		i;

	i = 0;
	while (size)
	{
		map[calc_pos(position + size - 1)] =
		(unsigned char)((value >> i) & 255);
		i += 8;
		size--;
	}
}

int		parse_args(t_cw *cw, t_coach *coach, int arg_num, t_op *op)
{
	int		id;
	int		res;
	int		position;

	res = 0;
	position = 0;
	id = cw->map[calc_pos(coach->pc + coach->shift)];
	if (coach->arg_type[ID(arg_num)] == T_REG)
		res = coach->reg[id];
	else if (coach->arg_type[ID(arg_num)] == T_DIR)
		res = bytecode_to_int(cw->map, op->label_size,
		calc_pos(coach->pc + coach->shift));
	else if (coach->arg_type[ID(arg_num)] == T_IND)
	{
		position = bytecode_to_int(cw->map, IND_SIZE,
		calc_pos(coach->pc + coach->shift));
		if (coach->op_id != 1 && coach->op_id != 13)
			position = position % IDX_MOD;
		res = bytecode_to_int(cw->map, DIR_SIZE, coach->pc + position);
	}
	coach->shift += shift_size(coach->arg_type[ID(arg_num)], op);
	return (res);
}
