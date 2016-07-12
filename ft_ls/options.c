/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 18:13:07 by yismail           #+#    #+#             */
/*   Updated: 2016/07/12 04:47:09 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int R_option(char *dotslash, struct stat *buf, struct s_env env, char *option)
{
	lstat(dotslash, buf);
    if (S_ISDIR(buf->st_mode))
    {
		ft_putendl(dotslash);
        if((env.dir = opendir (dotslash)))
            read_the_path(ft_strjoin(dotslash, "/"), option, env);
		if (access(dotslash, X_OK) == -1)
        {
            ft_putendl("   ft_ls: Permission denied");
            return(-1);
        }
	}

	if (S_ISREG(buf->st_mode))
	{
		ft_putchar(9);
	}
	//print_simple_option(env.pdirent->d_name);
	//if((env.dir = opendir (dotslash)))
	//	read_the_path(ft_strjoin(dotslash, "/"), option, env);
	return (0);
}

void l_option(char *d_name, struct stat *buf)
{
    struct s_toprint l_option;

    ft_bzero(&l_option, sizeof(struct s_toprint));
	l_option.name = d_name;
    //lstat(dotslash, buf);
    ft_perm(buf, &l_option);
	ft_putnstr(l_option.perm);
    ft_infos(buf, &l_option);
    ft_putnstr(l_option.links);
    ft_putnstr(l_option.uid);
    ft_putnstr(l_option.gid);
    ft_putnstr (l_option.size);
    ft_putstrlen(l_option.time, 12);
    ft_putchar(' ');
    ft_putendl(l_option.name);
}

int choose_opt(char *dotslash, char *option, struct s_env env)
{
	struct stat buf;

	lstat(dotslash, &buf);
	if ((strchr(option, 'R')))
        R_option(dotslash, &buf, env, option);
	if ((strchr(option, 'l')))
		(strchr(option, 'R') && S_ISDIR(buf.st_mode)) ? ft_putchar('\n') : l_option(env.pdirent->d_name, &buf);
	else if (!(strchr(option, 'l')))
		ft_putendl(env.pdirent->d_name);
	return(0);
}
	
