/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 10:02:33 by hmuravch          #+#    #+#             */
/*   Updated: 2019/01/18 11:31:57 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	zjmp(t_cw *cw, t_coach *coach, t_op *op)
{
	int	position;

	coach->shift++;
	position = parse_args(cw, coach, 1, op);
	if (coach->carry)
	{
		coach->pc = coach->pc + (position % IDX_MOD);
		coach->shift = 0;
	}
}
