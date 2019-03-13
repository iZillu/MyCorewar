/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:04:59 by hmuravch          #+#    #+#             */
/*   Updated: 2019/01/16 18:39:13 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	st(t_cw *cw, t_coach *coach, t_op *op)
{
	int	id;
	int	res;
	int	position;

	coach->shift += 2;
	id = cw->map[(coach->pc + coach->shift) % MEM_SIZE];
	res = coach->reg[id];
	coach->shift++;
	if (coach->arg_type[2] == T_IND)
	{
		position = convert_bytecode(cw->map,
			coach->pc + coach->shift, IND_SIZE);
		convert_integer(cw->map,
			coach->pc + (position % IDX_MOD), res, DIR_SIZE);
		coach->shift += 2;
	}
	else
	{
		position = cw->map[(coach->pc + coach->shift) % MEM_SIZE];
		coach->reg[position] = res;
		coach->shift++;
	}
}
