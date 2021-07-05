/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 19:50:22 by youncho           #+#    #+#             */
/*   Updated: 2021/07/05 23:54:47 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
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
