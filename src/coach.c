/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coach.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 20:57:30 by hmuravch          #+#    #+#             */
/*   Updated: 2019/01/15 20:58:42 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	add_coach(t_coach **list, t_coach *new_coach)
{
	if (new_coach)
		new_coach->next = *list;
	*list = new_coach;
}
