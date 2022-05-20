/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:18:59 by porrapat          #+#    #+#             */
/*   Updated: 2022/02/07 13:22:55 by porrapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dstc;
	const char	*srccc;

	if ((dst == src) || n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	dstc = (char *)dst;
	srccc = (const char *)src;
	while (n--)
		dstc[n] = srccc[n];
	return (dst);
}
