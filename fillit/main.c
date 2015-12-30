/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaustry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 17:14:38 by jaustry           #+#    #+#             */
/*   Updated: 2015/12/30 17:20:09 by jaustry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		pieces;

	if (argc != 2)
		ERROR;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ERROR;
	pieces = get_pieces(fd);

	return (0);
}

int		get_pieces(int fd)
{
	char	buf[21];
	ssize_t	r;

	while (r = (read(fd, buf, 21)))
	{
		verify_piece(buf);
		verify_n(buf);
		verify_link(buf);
	}
	printf("%s\n", "super");
	return (0);
}

void		verify_piece(char *buf)
{
	int a;
	int p;
	int d;
	int n;

	a = 0;
	p = 0;
	d = 0;
	n = 0;
	while (a <= 21)
	{
		if (buf[a] == '#')
			d++;
		if (buf[a] == '.')
			p++;
		if (buf[a] == '\n')
			n++;
	a++;
	}
	if (d != 4)
		ERROR;
	if (p != 12)
		ERROR;
	//if ((n != 5) || (n != 4))
	//	ERROR;
	printf("%s\n", "1");
}

void		verify_n(char *buf)
{
	int a;

	a = 0;
	while (a <= 3)
	{
		if (buf[a * 5 + 4] != '\n')
			ERROR;
		a++;
	}
	printf("%s\n", "2");
}

void		verify_link(char *buf)
{
  int n;
  int j;

  n = 0;
  j = 0;

  while (n < 20)
	{
		if (buf[n] == '#')
		  {
			if (buf[n + 5] == '#')
			  j++;
			if (buf[n - 5] == '#')
			  j++;
			if (buf[n + 1] == '#')
			  j++;
			if (buf[n - 1] == '#')
			  j++;
		  }	
		n++;
	}
	printf("%s\n", "3");
	if (j < 6)
		ERROR;
}

