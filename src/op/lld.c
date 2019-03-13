/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 09:47:39 by hmuravch          #+#    #+#             */
/*   Updated: 2019/01/16 15:06:04 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	lld(t_cw *cw, t_coach *coach, t_op *op)
{
    int	id;
	int	res;

	coach->shift += 2;
	id = cw->map[(coach->pc + coach->shift) % MEM_SIZE];
	coach->reg[id] = parse_args(cw, coach, 1, op);
	coach->carry = coach->reg[id] ? false : true;
	coach->shift++;	
}
