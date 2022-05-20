/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:18:59 by porrapat          #+#    #+#             */
/*   Updated: 2022/02/07 13:22:55 by porrapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nh;
	size_t	nn;

	if (needle[0] == '\0')
		return ((char *) haystack);
	if (haystack[0] == '\0' || len == 0)
		return (NULL);
	nh = 0;
	nn = 0;
	while (1)
	{
		if (needle[nn] == '\0')
			return ((char *)(haystack + nh - nn));
		if (haystack[nh] == needle[nn])
			nn++;
		else
		{
			nh -= nn;
			nn = 0;
		}
		if (haystack[nh] == '\0' || (nh >= len && haystack[nh] != '\0'))
			return (NULL);
		nh++;
	}
}
