/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 11:02:06 by hmuravch          #+#    #+#             */
/*   Updated: 2019/03/16 08:48:56 by hmuravch         ###   ########.fr       */
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
		ft_printf("GG WP\n");
		start_game(cw);
		ft_printf("GG WP\n");
	}
	else
		ft_printf("ERROR: No arguments");
	ft_printf("LOL EZ\n");
	return (0);
}

//	TODO: 
//			1. Validate size of champ (Error: File champs/42.cor has too large a code (993 bytes > 682 bytes)).
//	(DONE)	2. MAGIC header, smth go wrong, ya ebal, vernite 2 chasa vremeni. 
//			3. arg_type[3 ? 4] in t_coach & t_op
