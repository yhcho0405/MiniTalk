/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 19:50:22 by youncho           #+#    #+#             */
/*   Updated: 2020/10/07 20:03:51 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n--)
	{
		if (*((char *)s1) != *((char *)s2))
			return ((unsigned char)*(char *)s1 - (unsigned char)*(char *)s2);
		s1++;
		s2++;
	}
	return (0);
}
