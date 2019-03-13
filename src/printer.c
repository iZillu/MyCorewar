/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:08:00 by hmuravch          #+#    #+#             */
/*   Updated: 2019/01/14 19:55:01 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_help(void)
{
    ft_printf("Usage: ./corewar [-a (-dump|-d) <num> (-shed|-s) <num> -l"\
							" <num>] [-v] [-n <num>] <champion.cor> <...>\n");

	exit(0);
}