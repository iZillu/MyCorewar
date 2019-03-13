/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 00:04:43 by hmuravch          #+#    #+#             */
/*   Updated: 2019/01/16 00:07:12 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		lfork(t_cw *cw, t_coach *coach, t_op *op)
{
	int		shift;
    t_coach	*new_coach;

	coach->shift++;
	shift = parse_args(cw, coach, 1, op);
	new_coach = clone_coach(coach, shift % IDX_MOD);
	add_coach(&(cw->coach), new_coach);
	cw->amt_coaches++;
}