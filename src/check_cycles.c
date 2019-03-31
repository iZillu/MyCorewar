/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cycles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:33:27 by hmuravch          #+#    #+#             */
/*   Updated: 2019/03/31 18:36:27 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline void	respawn_live_nums(t_cw *cw)
{
	int				i;

	i = -1;
	while (++i < cw->amt_players)
	{
		cw->player[i].prev_lives = cw->player[i].crnt_lives;
		cw->player[i].crnt_lives = 0;
	}
	cw->amt_lives = 0;
}

static inline void	clear_dead_coaches(t_cw *cw)
{
	t_coach *prev;
	t_coach	*crnt;
	t_coach	*del;

	prev = NULL;
	crnt = cw->coach;
	while (crnt)
	{
		del = crnt;
		if ((cw->cycles_to_die <= 0 || ((cw->cycles - del->last_cycle_check) \
		>= cw->cycles_to_die)) && cw->amt_coaches--)
		{
			crnt = crnt->next;
			if (cw->coach == del)
				cw->coach = crnt;
			if (prev)
				prev->next = crnt;
			ft_memdel((void **)&del);
		}
		else
		{
			prev = crnt;
			crnt = crnt->next;
		}
	}
}

void				check_cycles_to_die(t_cw *cw)
{
	cw->amt_checks++;
	clear_dead_coaches(cw);
	if (cw->amt_checks == MAX_CHECKS || cw->amt_lives >= NBR_LIVE)
	{
		cw->cycles_to_die -= CYCLE_DELTA;
		cw->amt_checks = 0;
	}
	respawn_live_nums(cw);
	cw->cycles_after_check = 0;
}
