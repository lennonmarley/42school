/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:20:19 by yismail           #+#    #+#             */
/*   Updated: 2015/11/28 18:07:46 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

int ft_strlen (char *c)
{
	int cpt;
  
	cpt = 0;
	while (*c != '\0')
    {
		c++;
		cpt++;
    }
	return (cpt);
}

char *ft_strncpy (char *dest, char *src, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = ft_strlen(src);
	  while (src[i] != '\0' && i <= n && i <= j)
	{
		dest[i] = src[i];
		i++;
	}
	  while (src[i] == '\0' && dest[i])
      {
        dest[i] = '\0';
          i++;
      }
	  return(dest);
}
