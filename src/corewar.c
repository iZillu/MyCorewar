/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 11:02:06 by hmuravch          #+#    #+#             */
/*   Updated: 2019/03/29 21:38:24 by hmuravch         ###   ########.fr       */
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
		// ft_printf("GG WP\n");
		print_start(cw);
		// ft_printf("GG WP\n");
		start_game(cw);
		// ft_printf("GG WP\n");
		// int i = -1;
		// while (++i < cw->amt_players)
		// 	ft_printf("%i\n", cw->player[i].id);
		print_result(cw);
		// ft_printf("GG WP\n");
	}
	else
		ft_printf("ERROR: No arguments");
	// ft_printf("LOL EZ\n");
	return (0);
}

//	TODO: 
//			1. Validate size of champ (Error: File champs/42.cor has too large a code (993 bytes > 682 bytes)).
//			2. sti, 25 cycle
//			3. live ???
//			4. take func 'calc_position'
