/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 11:02:06 by hmuravch          #+#    #+#             */
/*   Updated: 2019/01/10 18:14:02 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			main(int argc, char **argv)
{
	t_cw	*cw;

	if (argc >= 2)
	{
		cw = initializer_cw();
		parse_flags(argc--, argv++, cw);
        // init_players();
		// fill_map();
		start_game(cw);

	}
	else
		ft_printf("ERROR: No arguments");
	return (0);
}