/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 20:25:25 by hmuravch          #+#    #+#             */
/*   Updated: 2019/03/27 15:43:39 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline void	fill_types(t_coach *coach, char	shift_codage, int id)
{
	if (shift_codage == 1)
				coach->arg_type[id] = T_REG;
	if (shift_codage == 2)
				coach->arg_type[id] = T_DIR;
	if (shift_codage == 3)
				coach->arg_type[id] = T_IND;
}

void				parse_types(t_cw *cw, t_coach *coach, t_op *op)
{
	char			codage;
	char			shift_codage;

	if (op->codage)
	{
		codage = cw->map[(coach->pc + 1) % MEM_SIZE];
		if (op->amt_args >= 1)
		{
			shift_codage = ((codage & 192) >> 6);
			fill_types(coach, shift_codage, 0);
		}
		if (op->amt_args >= 2)
		{
			shift_codage = ((codage & 48) >> 4);
			fill_types(coach, shift_codage, 1);
		}
		if (op->amt_args >= 3)
		{
			shift_codage = ((codage & 12) >> 2);
			fill_types(coach, shift_codage, 2);
		}
	}
	else
		coach->arg_type[0] = op->arg_type[0];
}