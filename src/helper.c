/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 11:16:30 by hmuravch          #+#    #+#             */
/*   Updated: 2019/03/25 21:17:25 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <errno.h>

void	ft_abort(char *s)
{
    if (errno)
        perror(s);
    else
        ft_putendl_fd(s, 2);
    exit (0);
}