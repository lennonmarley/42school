#include "../get_next_line.h"

int main (int argc, char **argv)
{
    char *send;
    int fd;
    int i;

    argc = 1;
    i = 0;

    send = NULL;
    fd = open(argv[1], O_RDONLY);

    while(get_next_line(fd, &send) > 0)
    {
        if (send != NULL)
        {
            ft_putendl(send);
            free(send);
            send = NULL;
        }
		i++;
    }
    while (1)
	{
	}
}

/*	i = 0;
	argc = 1;
	fd = open (argv[1], O_RDONLY);
	send = NULL;

	get_next_line(fd, &send);
	if (send != NULL)
	{
		ft_putendl(send);
		free(send);
		send = NULL;
	}
	if (send == NULL)
		ft_putendl ("NULL");
	while (1)
	{
	}
	return (0);
}
	
*/
