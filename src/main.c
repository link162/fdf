/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 11:11:40 by ybuhai            #+#    #+#             */
/*   Updated: 2019/10/29 19:19:46 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_case(char *str, t_fdf *fdf)
{
	int i;

	i = 0;
	if (fdf->map)
		while (i < fdf->heigth)
			free(fdf->map[i++]);
	if (fdf->map)
		free(fdf->map);
	if (str)
		ft_printf("%s\n", str);
	free(fdf);
	get_next_line(-5, NULL);
	exit(1);
}

int		len_width(char *line)
{
	int i;
	int z;
	int res;

	i = 0;
	z = 0;
	res = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			z = 0;
		else if (z == 0)
		{
			z = 1;
			res++;
		}
		i++;
	}
	return (res);
}

void	check_size(int fd, t_fdf *fdf)
{
	static int	i;
	int			z;
	char		*line;

	z = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (i == 0)
		{
			fdf->width = len_width(line);
			i++;
		}
		if (fdf->width != len_width(line))
		{
			free(line);
			error_case(ERR_FILE, fdf);
		}
		z++;
		free(line);
	}
	fdf->heigth = z;
}

int		main(int argc, char **argv)
{
	int		fd;
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	ft_bzero(fdf, sizeof(t_fdf));
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 1)
			ft_printf(ERR_FILE);
		else
		{
			check_size(fd, fdf);
			close(fd);
			fd = open(argv[1], O_RDONLY);
			if (fd < 1)
				ft_printf(ERR_FILE);
			fdf->name = &argv[0][2];
			read_map(fd, fdf);
		}
	}
	else
		ft_printf("Usage: ./fdf <map_name>\n");
	free(fdf);
}
