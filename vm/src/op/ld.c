/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 21:03:06 by hmuravch          #+#    #+#             */
/*   Updated: 2019/03/31 19:19:41 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ld(t_cw *cw, t_coach *coach, t_op *op)
{
	int	id;
	int	res;

	coach->shift += 2;
	res = parse_args(cw, coach, 1, op);
	id = cw->map[calc_pos(coach->pc + coach->shift)];
	coach->reg[id] = res;
	coach->carry = res ? false : true;
	coach->shift++;
}
