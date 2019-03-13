/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_shift.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:37:25 by hmuravch          #+#    #+#             */
/*   Updated: 2019/01/14 22:29:27 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					shift_size(char arg_type, t_op *op)
{
	if (arg_type == T_REG)
		return (1);
	else if (arg_type == T_DIR)
		return (op->label_size);
	else if (arg_type == T_IND)
		return (2);
	return (0);
}

unsigned int		update_shift(t_coach *coach, t_op *op)
{
	int				i;
	unsigned int	shift;

	i = -1;
	shift = 1 + (op->codage ? 1 : 0);
	while (++i < op->amt_args)
		shift += shift_size(coach->arg_type[i], op);
	return (shift);
}