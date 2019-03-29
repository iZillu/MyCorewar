/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <vdzhanaz@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 23:56:24 by hmuravch          #+#    #+#             */
/*   Updated: 2019/03/28 21:37:39 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ldi(t_cw *cw, t_coach *coach, t_op *op)
{
	int	res_1;
	int	res_2;
	int	id;

	if (cw->cycles < 50) {
		
	}
	coach->shift += 2;
    id = cw->map[(coach->pc + coach->shift) % MEM_SIZE];
    res_1 = parse_args(cw, coach, 1, op);
    res_2 = parse_args(cw, coach, 2, op);
    coach->reg[id] = bytecode_to_int(cw->map,
									(coach->pc + ((res_1 + res_2) % IDX_MOD)),
										DIR_SIZE);
    coach->shift++;
}	
