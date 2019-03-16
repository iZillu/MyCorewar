/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coach.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 20:57:30 by hmuravch          #+#    #+#             */
/*   Updated: 2019/03/16 07:49:57 by hmuravch         ###   ########.fr       */
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
	unsigned int	pc;

	i = 1;
	pc = 0;
	while (i <= cw->amt_players)
	{
		add_coach(&(cw->coach), initialize_coach(&cw->player[i - 1], pc));
		cw->amt_coaches++;
		pc += MEM_SIZE / cw->amt_players;
		i++;
	}
}