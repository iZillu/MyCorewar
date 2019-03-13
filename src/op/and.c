/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 20:34:12 by hmuravch          #+#    #+#             */
/*   Updated: 2019/01/18 10:01:16 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void    and(t_cw *cw, t_coach *coach, t_op *op)
{
    int id;
    int res_1;
    int res_2;

    coach->shift += 2;
    id = cw->map[(coach->pc + coach->shift) % MEM_SIZE];
    res_1 = parse_args(cw, coach, 1, op);
    res_2 = parse_args(cw, coach, 2, op);
    coach->reg[id] = res_1 & res_2;
    coach->carry = coach->reg[id] ? false : true;
    coach->shift++;
}
