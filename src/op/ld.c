/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 21:03:06 by hmuravch          #+#    #+#             */
/*   Updated: 2019/03/25 21:17:52 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ld(t_cw *cw, t_coach *coach, t_op *op)
{
	int	id;

	coach->shift += 2;
	id = cw->map[(coach->pc + coach->shift) % MEM_SIZE];
	coach->reg[id] = parse_args(cw, coach, 1, op);
	coach->carry = coach->reg[id] ? false : true;
	coach->shift++;	
}
