/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 11:02:06 by hmuravch          #+#    #+#             */
/*   Updated: 2019/03/31 18:29:01 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			main(int argc, char **argv)
{
	t_cw	*cw;

	if (argc >= 2)
	{
		cw = initialize_cw();
		parse_flags(argc--, argv++, cw);
		set_coach(cw);
		print_start(cw);
		start_game(cw);
		print_result(cw);
	}
	else
		ft_printf("ERROR: No arguments");
	return (0);
}
