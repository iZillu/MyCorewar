/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 11:14:00 by hmuravch          #+#    #+#             */
/*   Updated: 2019/01/14 20:47:15 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_error_manager.h"

t_cw		*initializer_cw(void)
{
    t_cw    *cw;

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
