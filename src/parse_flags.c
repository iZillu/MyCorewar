/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:18:16 by hmuravch          #+#    #+#             */
/*   Updated: 2019/03/18 20:19:58 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

# define PL(i)		cw->player[i]

static const char		g_usage[] = "Usage: ./corewar "
"[-v N] [(-d|-dump) N] [--ncurses [--stealth] [--start-in N] "
"[(--venom|--skibidi)]] [-n N champion.cor] <champion1.cor> <...>\n"
"\t(-d|-dump) N\t\t: dumps memory after N cycles then exits\n"
"\t--ncurses\t\t: ncurses output mode\n"
"\t\t\t\t--start-in N\t: waits N cycles, then starts the ncurses mode\n"
"\t\t\t\t--stealth\t: hides the real contents of the memory in ncurses mode\n"
"\t\t\t\t--no-stat\t: turn off stat(3rd) window in ncurses mode\n"
"\t\t\t\t--(venom|skibidi|bigshaq) : "
"playing last chosen sounds in ncurses mode\n"
"\t-n N champion.cor\t: sets the N of the next player\n"
"\t-v N\t\t\t: verbosity levels, can be added together to enable several\n"
"\t\t\t\t- 0\t: Show only essentials\n"
"\t\t\t\t- 1\t: Show lives\n"
"\t\t\t\t- 2\t: Show cycles\n"
"\t\t\t\t- 4\t: Show operations (Params are NOT litteral ...)\n"
"\t\t\t\t- 8\t: Show deaths\n";

static const char		*g_errs[] = {"", "Too little arguments",
	"Wrong parameter passed to '-d' argument",
	// ERR_PLAYERS_NUM, "At least one player needed for the game",
	"Wrong parameter passed to '-n' argument",
	"Wrong parameter passed to '-v' argument",
	"'--start-in' can't be set-up without '--ncurses' argument",
	"'--stealth' can't be set-up without '--ncurses' argument",
	"'--venom' can't be set-up without '--ncurses' argument",
	"'--skibidi' can't be set-up without '--ncurses' argument",
	"'--bigshaq' can't be set-up without '--ncurses' argument",
	"'--no-stat' can't be set-up without '--ncurses' argument"
};

bool					ft_usage(const int num_err)
{
	const bool		inv_error = num_err < 0 || num_err > 6;
	char			*str_err;

	if (!inv_error)
		str_err = (num_err == 0) ? strerror(num_err) : ((char **)g_errs)[num_err];
	else
		str_err = "";
	dprintf(2, (inv_error) ? "%.s%.s\n\n%s" : "%s%s\n\n%s",
	"Error: ", str_err, g_usage);
	exit(1);
}

bool					ft_puterr(const int num_err, const char *str_err
	, const int i1, const int i2)
{
	const char		*errs[] = {"%sCannot read .cor file: %s\n",
	"%sFile %s does not have a magic number in its header\n",
	"%sFile %s has too large source code (%u bytes > %u bytes)\n"};

	dprintf(2, errs[num_err], "Error: ", str_err, i1, i2);
	exit(2);
}

int				ft_read_data(const int fd, void *buf, const int nb)
{
	int			ret;

	ret = read(fd, buf, nb);
	if (ret < 0)
		ft_usage(0);
	return (ret);
}

unsigned int	ft_read_bnum(const int fd, const int cnum)
{
	int					i;
	unsigned int		res;
	unsigned char		buf[cnum];

	i = 0;
	res = 0;
	ft_bzero(&buf, cnum);
	ft_read_data(fd, buf, cnum);
	while (i < cnum)
	{
		res <<= 8;
		res |= buf[i++];
	}
	return (res);
}

void			ft_fill_map(t_cw *cw, int pl_num)
{
	int				step;
	int				i;
	unsigned char	*tmp_map;

	tmp_map = cw->map;
	step = MEM_SIZE / pl_num;
	i = -1;
	while (++i < pl_num)
	{
		// argc();
		ft_memcpy(tmp_map, PL(i).code, PL(i).code_size);
		tmp_map += step * sizeof(char); 
	}
	cw->last_player = &PL(cw->amt_players - 1);
}

void			ft_init_arena(int pl_num, char **file_name, t_cw *cw)
{
	int				i;
	int				ret;
	unsigned int	magic;

	i = -1;
	while (++i < pl_num)
	{
		PL(i).id = UINT_MAX - i;
		if ((PL(i).fd = open(file_name[i], O_RDONLY)) == -1)
			ft_puterr(0, file_name[i], 0, 0);
		magic = ft_read_bnum(PL(i).fd, sizeof(int));
		if (magic != COREWAR_EXEC_MAGIC)
			ft_puterr(1, file_name[i], 0, 0);
		
		ft_read_data(PL(i).fd, PL(i).name, PROG_NAME_LENGTH);
		
		lseek(PL(i).fd, sizeof(int), SEEK_CUR);
		PL(i).code_size = ft_read_bnum(PL(i).fd, sizeof(int));
		
		ft_read_data(PL(i).fd, PL(i).comment, COMMENT_LENGTH);
		
		lseek(PL(i).fd, sizeof(int), SEEK_CUR);
		ret = ft_read_data(PL(i).fd, PL(i).code, MEM_SIZE);
		if (ret > PL(i).code_size || ret > CHAMP_MAX_SIZE
			|| PL(i).code_size > CHAMP_MAX_SIZE)
			ft_puterr(2, file_name[i], PL(i).code_size, CHAMP_MAX_SIZE);
		close(PL(i).fd);
	}
	ft_fill_map(cw, pl_num);
}

void			parse_flags(int	argc, char **argv, t_cw *cw)
{
	int			i;
	int			j;
	char		*tmp;
	char		*file_name[4];

	i = -1;
	ft_bzero((void *)&file_name, sizeof(file_name));
	while (++i < argc && cw->amt_players < 4)
	{
		if ((ft_strequ(argv[i], "-dump") || ft_strequ(argv[i], "-d")) 
			&& (cw->f_dump = true))
			cw->cycles_to_dump = ft_atoi(argv[++i]);
		else if (ft_strequ(argv[i], "-n"))
		{
			j = ft_atoi(argv[++i]);
			if (j > 4 || j < 1)
				break ;
			if (!file_name[j - 1])
				file_name[j - 1] = argv[++i];
			else
			{	
				tmp = file_name[j - 1];
				file_name[j - 1] = argv[++i];
				j= -1;
				while (++j < 4 && file_name[j])
					;
				if (j == 4)
					break ;
				else
					file_name[j] = tmp;					
			}
			cw->amt_players++;
		}
		else if (i > 0)
		{
			j = 0;
			while (file_name[j])
				j++;
			file_name[j] = argv[i];
			cw->amt_players++;
		}
	}
	ft_init_arena(cw->amt_players, file_name, cw);
}
