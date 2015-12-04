/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:20:19 by yismail           #+#    #+#             */
/*   Updated: 2015/12/02 15:25:12 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char *d;
	int i;

	i = 0;
	if (!n)
		return (dest);
	d = dest;
	while (src[i] != '\0' && n)
	{
		dest[i] = src[i];
		i++;
		n--;
	}
	while (n)
	{
		dest[i] = '\0';
		n--;
	}
	return (d);
}
