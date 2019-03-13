/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstafter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 07:09:59 by hmuravch          #+#    #+#             */
/*   Updated: 2018/10/17 05:50:09 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstafter(t_list *alst, t_list *new)
{
	if (alst && new)
	{
		while (alst->next)
			alst = alst->next;
		alst->next = new;
	}
}
