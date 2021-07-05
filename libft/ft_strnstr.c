/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:48:55 by youncho           #+#    #+#             */
/*   Updated: 2021/07/05 23:53:31 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	idx;
	size_t	nlen;
	size_t	hlen;

	if (!*n)
		return ((char *)h);
	hlen = ft_strlen(h);
	nlen = ft_strlen(n);
	if (!len || !hlen || len < nlen)
		return (0);
	idx = 0;
	while (idx + nlen <= len && idx + nlen <= hlen)
	{
		if (!ft_strncmp((char *)(h + idx), (char *)n, nlen))
			return ((char *)(h + idx));
		idx++;
	}
	return (0);
}
