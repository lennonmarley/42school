/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 09:11:01 by yismail           #+#    #+#             */
/*   Updated: 2016/11/19 09:11:28 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrlen(char *c, size_t len)
{
	size_t		i;

	i = 0;
	while (c[i] != '\0' && i <= len)
	{
		ft_putchar(c[i]);
		i++;
	}
}
