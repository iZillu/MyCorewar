/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:04:59 by hmuravch          #+#    #+#             */
/*   Updated: 2019/03/31 17:39:10 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	st(t_cw *cw, t_coach *coach, t_op *op)
{
	int	id;
	int	res;
	int	position;

	(void)op;
	coach->shift += 2;
	id = cw->map[calc_pos(coach->pc + coach->shift)];
	res = coach->reg[id];
	coach->shift++;
	if (coach->arg_type[1] == T_IND)
	{
		position = bytecode_to_int(cw->map, IND_SIZE,
			coach->pc + coach->shift);
		int_to_bytecode(cw->map,
			coach->pc + (position % IDX_MOD), res, DIR_SIZE);
		coach->shift += 2;
	}
	else
	{
		position = cw->map[calc_pos(coach->pc + coach->shift)];
		coach->reg[position] = res;
		coach->shift++;
	}
}
