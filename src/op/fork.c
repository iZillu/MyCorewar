/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 20:11:06 by hmuravch          #+#    #+#             */
/*   Updated: 2019/01/15 21:02:23 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		fork(t_cw *cw, t_coach *coach, t_op *op)
{
    int		shift;
    t_coach	*new_coach;

	coach->shift++;
	shift = parse_args(cw, coach, 1, op);
	new_coach = clone_coach(coach, shift % IDX_MOD);
	add_coach(&(cw->coach), new_coach);
	cw->amt_coaches++;
}
