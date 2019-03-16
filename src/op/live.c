/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 01:19:32 by hmuravch          #+#    #+#             */
/*   Updated: 2019/03/16 04:53:26 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			live(t_cw *cw, t_coach *coach, t_op *op)
{
	int			id;
	t_player	*player;

	coach->shift++;
	player = NULL;
	id = parse_args(cw, coach, 1, op);
	cw->amt_lives++;
	coach->last_cycle_check = cw->cycles;
	if (id <= -1 && id >= -((int)cw->amt_players))
	{
		player = &cw->player[MODULE(id - 1)];
		player->last_cycle_check = cw->cycles;
		player->crnt_lives++;
		cw->last_player = player;
	}
}
