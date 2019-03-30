/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:39:27 by hmuravch          #+#    #+#             */
/*   Updated: 2019/03/30 22:30:43 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sti(t_cw *cw, t_coach *coach, t_op *op)
{
	int	id;
	int	res;
	int	pos_1;
	int	pos_2;
	// if (cw->cycles == 2535) {
		// ft_printf("coach->reg[id]: %d\n", coach->reg[4]);
	// }
	// printf("ALO\n");
	// printf("%u\n", coach->shift);
	coach->shift += 2;
	// printf("%u\n", coach->shift);
	// id = cw->map[calc_pos(coach->pc + coach->shift)];
	id = cw->map[calc_pos(coach->pc + coach->shift)];
	// printf("%i\n", id);
	coach->shift++;
	res = coach->reg[id];
	// if (cw->cycles == 3647) {
	// 	ft_printf("r_id :%d, coach->carry: %d, value: %d\n", id, coach->carry, res);
	// }
	pos_1 = parse_args(cw, coach, 2, op);
	pos_2 = parse_args(cw, coach, 3, op);
	int_to_bytecode(cw->map, (coach->pc + ((pos_1 + pos_2) % IDX_MOD)), res, DIR_SIZE);
}

// cw->arena[calc_pos(pc + step)]