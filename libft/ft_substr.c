/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:14:13 by youncho           #+#    #+#             */
/*   Updated: 2021/07/06 00:36:46 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	sl;

	if (!s)
		return (0);
	sl = ft_strlen(s);
	if (start >= sl)
		start = sl;
	else if (start + len > sl)
		len = sl - start;
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (0);
	ft_memcpy(ret, s + start, len);
	ret[len] = 0;
	return (ret);
}
