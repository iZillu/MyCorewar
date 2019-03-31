/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 23:56:24 by hmuravch          #+#    #+#             */
/*   Updated: 2019/03/31 19:23:35 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ldi(t_cw *cw, t_coach *coach, t_op *op)
{
	int	res_1;
	int	res_2;
	int	id;

	coach->shift += 2;
	res_1 = parse_args(cw, coach, 1, op);
	res_2 = parse_args(cw, coach, 2, op);
	id = cw->map[calc_pos(coach->pc + coach->shift)];
	coach->reg[id] = bytecode_to_int(cw->map, DIR_SIZE,
									(coach->pc + ((res_1 + res_2) % IDX_MOD)));
	coach->shift++;
}
