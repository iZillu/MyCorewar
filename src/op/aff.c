/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 20:24:28 by hmuravch          #+#    #+#             */
/*   Updated: 2019/03/16 01:42:55 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	aff(t_cw *cw, t_coach *coach, t_op *op)
{
    int	id;

    (void)op;
	coach->shift += 2;
    id = cw->map[(coach->pc + coach->shift) % MEM_SIZE];
    coach->shift++;
    if (cw->print_aff)
        ft_printf("Aff: %c\n", (char)coach->reg[id]);
}
