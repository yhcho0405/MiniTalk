/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 10:28:01 by youncho           #+#    #+#             */
/*   Updated: 2021/07/06 00:37:41 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	char	*head;
	char	*tail;
	size_t	len;

	if (!s1 || !set)
		return ((char *)s1);
	head = (char *)s1;
	tail = (char *)s1 + ft_strlen(s1);
	while (*head && find_set(*head, set))
		head++;
	while (*(tail - 1) && head < tail && find_set(*(tail - 1), set))
		tail--;
	len = tail - head + 1;
	ret = malloc(len);
	if (!ret)
		return (0);
	ft_strlcpy(ret, head, len);
	return (ret);
}
