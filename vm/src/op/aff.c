/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 20:24:28 by hmuravch          #+#    #+#             */
/*   Updated: 2019/03/31 18:07:52 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	aff(t_cw *cw, t_coach *coach, t_op *op)
{
	int	id;

	(void)op;
	coach->shift += 2;
	id = cw->map[calc_pos(coach->pc + coach->shift)];
	coach->shift++;
	if (cw->print_aff)
		ft_printf("Aff: %c\n", (char)coach->reg[id]);
}
