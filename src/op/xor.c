/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 09:56:50 by hmuravch          #+#    #+#             */
/*   Updated: 2019/03/31 18:08:54 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	xor(t_cw *cw, t_coach *coach, t_op *op)
{
	int id;
	int res_1;
	int res_2;

	coach->shift += 2;
	res_1 = parse_args(cw, coach, 1, op);
	res_2 = parse_args(cw, coach, 2, op);
	id = cw->map[calc_pos(coach->pc + coach->shift)];
	coach->reg[id] = res_1 ^ res_2;
	coach->carry = coach->reg[id] ? false : true;
	coach->shift++;
}
