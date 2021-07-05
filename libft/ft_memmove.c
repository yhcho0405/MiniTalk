/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 22:11:32 by youncho           #+#    #+#             */
/*   Updated: 2021/07/06 00:37:57 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*ret;

	if (!dst && !src)
		return (0);
	ret = dst;
	if (src < dst)
	{
		src += len;
		dst += len;
		while (len--)
			*((char*)--dst) = *((char*)--src);
	}
	else
		while (len--)
			*((char *)dst++) = *((char *)src++);
	return (ret);
}
