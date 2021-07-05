/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:31:41 by youncho           #+#    #+#             */
/*   Updated: 2021/07/06 00:32:54 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_words(char const *s, char c)
{
	size_t	ret;
	int		chk;

	ret = 0;
	chk = 0;
	while (*s)
	{
		if (*s != c && !chk)
		{
			chk = 1;
			ret++;
		}
		else if (*s == c && chk)
			chk = 0;
		s++;
	}
	return (ret);
}

char	**allocate_fail(char **tmp, size_t idx)
{
	size_t	i;

	i = 0;
	while (i < idx)
		free(tmp[i++]);
	free(tmp);
	return (0);
}

int	init_split(char const *s, char c, size_t *idx, char ***ret)
{
	if (!s)
		return (0);
	*idx = 0;
	*ret = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1) + 1);
	if (!*ret)
		return (0);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	*tmp;
	size_t	idx;
	int		init;

	init = init_split(s, c, &idx, &ret);
	if (!init)
		return (0);
	while (*s)
	{
		if (*s == c)
		{
			s++;
			continue ;
		}
		tmp = (char *)s;
		while (*s && *s != c)
			s++;
		ret[idx] = (char *)malloc(s - tmp + 1);
		if (!ret[idx])
			return (allocate_fail(ret, idx));
		ft_strlcpy(ret[idx++], tmp, s - tmp + 1);
	}
	ret[idx] = 0;
	return (ret);
}
