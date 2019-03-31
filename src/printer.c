/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <vdzhanaz@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:08:00 by hmuravch          #+#    #+#             */
/*   Updated: 2019/03/31 20:11:31 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_start(t_cw *cw)
{
	int	i;

	i = -1;
	ft_printf("Introducing contestants...\n");
	while (++i < cw->amt_players)
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			i + 1,
			cw->player[i].code_size,
			cw->player[i].name,
			cw->player[i].comment);
}

void	print_map(unsigned char *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("0x%0.4x : ", i);
		j = -1;
		while (++j < 64)
			ft_printf("%.2x ", map[i + j]);
		ft_printf("\n");
		i += 64;
	}
}

void	print_result(t_cw *cw)
{
	ft_printf("Contestant %d, \"%s\", has won !\n", -(cw->last_player->id),
		cw->last_player->name);
}
