/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strncat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:50:19 by yismail           #+#    #+#             */
/*   Updated: 2015/11/26 15:50:36 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int main (void)
{
    char dest[50] = "bonjour";
    char src[50] = "monsieur";

    ft_strncat (dest, src, 3);
    printf ("%s", dest);
}
