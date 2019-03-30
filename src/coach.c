/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coach.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 20:57:30 by hmuravch          #+#    #+#             */
/*   Updated: 2019/03/30 20:57:22 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				add_coach(t_coach **list, t_coach *new_coach)
{
	if (new_coach)
		new_coach->next = *list;
	*list = new_coach;
}

void				set_coach(t_cw *cw)
{
	int				i;
	unsigned int	pos;

	i = 0;
	pos = 0;
	while (++i <= cw->amt_players)
	{
		add_coach(&(cw->coach), initialize_coach(&cw->player[i - 1], pos));
		cw->amt_coaches++;
		pos += MEM_SIZE / cw->amt_players;
	}
}
