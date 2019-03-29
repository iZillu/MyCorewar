/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 21:03:06 by hmuravch          #+#    #+#             */
/*   Updated: 2019/03/29 22:18:38 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ld(t_cw *cw, t_coach *coach, t_op *op)
{
	int	id;
	int	res;

	if (cw->cycles == 2510) {
		ft_printf("");
	}
	coach->shift += 2;
	res = parse_args(cw, coach, 1, op);
	id = cw->map[calc_pos(coach->pc + coach->shift)];
	coach->reg[id] = res;
	coach->carry = coach->reg[id] ? false : true;
	coach->shift++;
	// if (coach->reg[4]) {
	// 	ft_printf("ld: cw->cycles: %d; coach->reg[4] :%d", cw->cycles, coach->reg[4]);
	// }
}
