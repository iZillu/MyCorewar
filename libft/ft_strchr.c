/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 19:39:41 by hmuravch          #+#    #+#             */
/*   Updated: 2018/09/16 22:09:06 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	to_find;

	if (s == NULL)
		return (NULL);
	to_find = (unsigned char)c;
	while (*s)
	{
		if (*s == to_find)
			return ((char *)s);
		s++;
	}
	if (to_find == '\0')
		return ((char *)s++);
	return (NULL);
}
