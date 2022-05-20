/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <ppetchda@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                              +#+#+#+#+#+     +#+           */
/*   Created: 2022/03/13 20:13:59 by ppetchda          #+#    #+#             */
/*   Updated: 2022/03/13 20:18:35 by ppetchda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strmycat(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

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
