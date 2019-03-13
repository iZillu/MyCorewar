/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 22:11:02 by hmuravch          #+#    #+#             */
/*   Updated: 2019/01/18 09:56:32 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sub(t_cw *cw, t_coach *coach, t_op *op)
{
	int	id_1;
	int	id_2;
	int	id_3;

	coach->shift += 2;
	id_1 = cw->map[(coach->pc + coach->shift) % MEM_SIZE]
	coach->shift++;
	id_2 = cw->map[(coach->pc + coach->shift) % MEM_SIZE]
	coach->shift++;
	id_3 = cw->map[(coach->pc + coach->shift) % MEM_SIZE]
	coach->reg[id_3] = coach->reg[id_1] - coach->reg[id_2];
	coach->carry = coach->reg[id_3] ? false : true;
	coach->shift++;
}
