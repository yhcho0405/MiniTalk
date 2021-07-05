/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:33:18 by youncho           #+#    #+#             */
/*   Updated: 2021/07/06 00:39:00 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;

	ret = (char *)malloc(ft_strlen(s1) + 1);
	if (!ret)
		return (0);
	ft_memcpy(ret, s1, ft_strlen(s1) + 1);
	return (ret);
}
