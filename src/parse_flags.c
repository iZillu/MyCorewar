/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <vdzhanaz@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:18:16 by hmuravch          #+#    #+#             */
/*   Updated: 2019/03/31 20:18:11 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static const char		g_usage[] = "Usage: ./corewar "
"[-v N] [(-d|-dump) N]\n"
"\t(-d|-dump) N\t\t: dumps memory after N cycles, then exits\n"
"\t-n N champion.cor\t: sets the N of the next player\n";

void					ft_abort(char *s)
{
	if (!s[0] || errno)
		perror(s);
	else
	{
		ft_putendl_fd(s, 2);
		ft_putendl_fd(g_usage, 2);
	}
	exit(1);
}

void					ft_init_arena(int pl_num, char **file_name, t_cw *cw)
{
	int				i;
	int				ret;
	unsigned int	magic;

	i = -1;
	while (++i < pl_num)
	{
		PL(i).id = UINT_MAX - i;
		if ((PL(i).fd = open(file_name[i], O_RDONLY)) == -1)
			ft_abort(ERR_INVALID_FILE);
		magic = ft_read_bnum(PL(i).fd, sizeof(int));
		if (magic != COREWAR_EXEC_MAGIC)
			ft_abort(ERR_INVALID_HEADER);
		ft_read_data(PL(i).fd, PL(i).name, PROG_NAME_LENGTH);
		lseek(PL(i).fd, sizeof(int), SEEK_CUR);
		PL(i).code_size = ft_read_bnum(PL(i).fd, sizeof(int));
		ft_read_data(PL(i).fd, PL(i).comment, COMMENT_LENGTH);
		lseek(PL(i).fd, sizeof(int), SEEK_CUR);
		ret = ft_read_data(PL(i).fd, PL(i).code, MEM_SIZE);
		if (ret > PL(i).code_size || ret > CHAMP_MAX_SIZE
			|| PL(i).code_size > CHAMP_MAX_SIZE)
			ft_abort(ERR_CODE_SIZE);
		close(PL(i).fd);
	}
	ft_fill_map(cw, pl_num);
}

int						ft_parse_n(int i, char **av, char **file_name, t_cw *cw)
{
	int		j;
	char	*tmp;

	j = ft_read_num(av[++i]);
	if (j > 4 || j < 1)
		ft_abort(ERR_INV_PAR);
	if (!file_name[j - 1])
		file_name[j - 1] = av[++i];
	else
	{
		tmp = file_name[j - 1];
		file_name[j - 1] = av[++i];
		j = -1;
		while (++j < 4 && file_name[j])
			;
		if (j == 4)
			ft_abort(ERR_INV_PAR);
		else
			file_name[j] = tmp;
	}
	cw->amt_players++;
	return (i);
}

void					parse_flags(int ac, char **av, t_cw *cw)
{
	int		i;
	int		j;
	char	*file_name[4];

	i = 0;
	ft_bzero((void *)&file_name, sizeof(file_name));
	while (++i < ac && (cw->amt_players < 4 || ft_strequ(av[i], "-dump") ||
		ft_strequ(av[i], "-d")))
	{
		if ((ft_strequ(av[i], "-dump") || ft_strequ(av[i], "-d"))
			&& (cw->f_dump = true))
			cw->cycles_to_dump = ft_read_num(av[++i]);
		else if (ft_strequ(av[i], "-n"))
			i = ft_parse_n(i, av, file_name, cw);
		else if (!(j = 0))
		{
			while (file_name[j])
				j++;
			file_name[j] = av[i];
			cw->amt_players++;
		}
	}
	(i < ac) ? ft_abort("Too many players") : (void)0;
	ft_init_arena(cw->amt_players, file_name, cw);
}
