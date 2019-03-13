/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:57:46 by hmuravch          #+#    #+#             */
/*   Updated: 2019/01/14 20:07:28 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int                 validate_arg_types(t_coach *coach, t_op *op)
{
    int             i;

    i = -1;
    while (++i < op->amt_args)
        if (!(coach->arg_type[i] & op->arg_type[i]]))
            return (0);
    return (1);
}

int                 validate_args(t_coach *coach, t_cw *cw, t_op *op)
{
	int				i;
	unsigned int	shift;
	char			r_id;
	int				check;

	i = -1;
	shift = 1 + (op->codage ? 1 : 0);
	while (++i < op->amt_args)
	{
		r_id = cw->map[(coach->pc + shift) % MEM_SIZE];
		if ((coach->arg_type[i] == T_REG) && !(r_id >= 1 && r_id <= 16)
			return (0);
		shift += shift_size(coach->arg_type[i], op);
	}
	return (1);
}