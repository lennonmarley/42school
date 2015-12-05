/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:19:22 by yismail           #+#    #+#             */
/*   Updated: 2015/12/02 15:21:00 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
  int i;
  
  i = 0;
  while (s1[i] != '\0')
    {
      if (s1[i] != s2[i])
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
      i++;
    }
  return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
