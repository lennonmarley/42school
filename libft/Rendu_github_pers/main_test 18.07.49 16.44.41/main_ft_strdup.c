/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:30:37 by yismail           #+#    #+#             */
/*   Updated: 2015/11/28 16:31:08 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int main (void)
{
    char s [50] = "bonjourmonsieurpolochon";
    char *str;
    str = ft_strdup (s);
    printf ("%s", str);
    return (0);
}
