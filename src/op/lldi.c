/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:09:04 by hmuravch          #+#    #+#             */
/*   Updated: 2019/01/16 16:21:12 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	lldi(t_cw *cw, t_coach *coach, t_op *op)
{
	int	res_1;
	int	res_2;
	int	id;

	coach->shift += 2;
    id = cw->map[(coach->pc + coach->shift) % MEM_SIZE];
    res_1 = parse_args(cw, coach, 1, op);
    res_2 = parse_args(cw, coach, 2, op);
    coach->reg[id] = convert_bytecode(cw->map,
										coach->pc + (res_1 + res_2),
											DIR_SIZE);
    coach->shift++;
}	
