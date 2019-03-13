/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 11:14:00 by hmuravch          #+#    #+#             */
/*   Updated: 2019/03/13 22:58:27 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_error_manager.h"

t_cw			*initializer_cw(void)
{
    t_cw    	*cw;

    if (!(cw = (t_cw *)ft_memalloc(sizeof(t_cw))));
        abort(ERR_CW_INIT);
    cw->amt_players = 0;
	cw->last_player = NULL;
	cw->coach = NULL;
	cw->amt_coaches = 0;
	cw->cycles = 0;
	cw->cycles_to_die = CYCLE_TO_DIE;
	cw->cycles_after_check = 0;
	cw->checks_num = 0;
    return (cw);
}

t_coach			*initializer_coach(t_player	*player, int pc)
{
	t_coach		*coach;
	static int	id;

	if (!(coach = (t_coach *)ft_memalloc(sizeof(t_coach))))
		abort(ERR_COACH_INIT);
	coach->id = ++id;
	coach->op_id = 0;
	coach->carry = false;
	coach->pc = pc;
	coach->last_cycle_check = 0;
	coach->cycles_to_wait = 0;
	coach->reg[0] = -(player->id);
	coach->player = player;
	coach->next = NULL;
	return (coach);
}
