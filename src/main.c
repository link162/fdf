/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 11:11:40 by ybuhai            #+#    #+#             */
/*   Updated: 2019/04/11 12:59:19 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_case(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

void	fdf(int fd)
{
	t_fdf fdf;

	ft_bzero(&fdf, sizeof(t_fdf));
	read_map(&fdf, fd);
}

int		main(int argc, char **argv)
{
	int fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 1)
			ft_printf(ERR_FILE);
		else
			fdf(fd);
	}
	else
		ft_printf("Usage: ./fdf <map_name>\n");
}
