/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:39:27 by hmuravch          #+#    #+#             */
/*   Updated: 2019/03/26 06:45:04 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sti(t_cw *cw, t_coach *coach, t_op *op)
{
	int	id;
	int	res;
	int	pos_1;
	int	pos_2;

	// printf("ALO\n");
	// printf("%u\n", coach->shift);
	coach->shift += 2;
	// printf("%u\n", coach->shift);
	id = cw->map[(coach->pc + coach->shift) % MEM_SIZE];
	coach->shift++;
	res = coach->reg[id];
	pos_1 = parse_args(cw, coach, 2, op);
	pos_2 = parse_args(cw, coach, 3, op);
	int_to_bytecode(cw->map, (coach->pc + ((pos_1 + pos_2) % IDX_MOD)), res, DIR_SIZE);
}
