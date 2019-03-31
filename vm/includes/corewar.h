/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 09:23:30 by hmuravch          #+#    #+#             */
/*   Updated: 2019/03/31 20:49:04 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "op.h"
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include "corewar_error_manager.h"

# define MODULE(X)			(((X) < 0) ? (-(X)) : (X))
# define ID(X)				((X) - 1)
# define PL(i)				cw->player[i]

typedef struct s_player		t_player;
typedef struct s_coach		t_coach;
typedef struct s_cw			t_cw;
typedef struct s_op			t_op;

struct						s_player
{
	int						id;
	int						fd;
	int						code_size;
	char					code[MEM_SIZE];
	char					name[PROG_NAME_LENGTH + 1];
	char					comment[COMMENT_LENGTH + 1];
	size_t					crnt_lives;
	size_t					prev_lives;
	ssize_t					last_cycle_check;

};

struct						s_coach
{
	unsigned int			id;
	unsigned int			carry : 1;
	unsigned int			shift;
	unsigned int			cycles_to_wait;
	ssize_t					last_cycle_check;
	unsigned char			op_id;
	unsigned char			arg_type[3];
	int						pc;
	int						reg[17];
	t_player				*player;
	struct s_coach			*next;

};

struct						s_cw
{
	bool					f_dump;
	bool					print_aff;
	unsigned char			map[MEM_SIZE];
	t_player				player[MAX_PLAYERS];
	t_player				*last_player;
	t_coach					*coach;
	int						amt_players;
	size_t					amt_lives;
	size_t					amt_checks;
	size_t					amt_coaches;
	size_t					prev_cycles_alive;
	ssize_t					cycles;
	ssize_t					cycles_to_dump;
	ssize_t					cycles_to_die;
	ssize_t					cycles_after_check;

};

struct						s_op
{
	char					*name;
	unsigned char			amt_args;
	unsigned char			arg_type[3];
	unsigned char			op_id;
	unsigned int			cycles;
	char					*description;
	bool					codage;
	int						label_size;
	void					(*func)(t_cw *, t_coach *, t_op *);
};

void						print_help(void);
void						ft_abort(char *s);
void						set_coach(t_cw *cw);
void						start_game(t_cw *cw);
void						print_start(t_cw *cw);
void						print_result(t_cw *cw);
void						check_cycles_to_die(t_cw *cw);
void						parse_flags(int	ac, char **av, t_cw *cw);
void						print_map(unsigned char *map);
void						add_coach(t_coach **list, t_coach *new_coach);
void						parse_types(t_cw *cw, t_coach *coach, t_op *op);
void						int_to_bytecode(unsigned char *map, int pos,
							int value, int size);
int							bytecode_to_int(const unsigned char *map,
							int size, int pos);
int							shift_size(char arg_type, t_op *op);
int							validate_arg_types(t_coach *coach, t_op *op);
int							validate_args(t_coach *coach, t_cw *cw, t_op *op);
int							parse_args(t_cw *cw, t_coach *coach,
							int num, t_op *op);
unsigned int				update_shift(t_coach *coach, t_op *op);
t_cw						*initialize_cw(void);
t_coach						*clone_coach(t_coach *crnt_coach, int shift);
t_coach						*initialize_coach(t_player	*player, int pc);
int							ft_read_data(const int fd, void *buf, const int nb);
unsigned int				ft_read_bnum(const int fd, const int cnum);
int							ft_read_num(char *src);
void						ft_fill_map(t_cw *cw, int pl_num);

/*
**						OPERATIONS
*/

void						add(t_cw *cw, t_coach *coach, t_op *op);
void						aff(t_cw *cw, t_coach *coach, t_op *op);
void						and(t_cw *cw, t_coach *coach, t_op *op);
void						my_fork(t_cw *cw, t_coach *coach, t_op *op);
void						ld(t_cw *cw, t_coach *coach, t_op *op);
void						ldi(t_cw *cw, t_coach *coach, t_op *op);
void						lfork(t_cw *cw, t_coach *coach, t_op *op);
void						live(t_cw *cw, t_coach *coach, t_op *op);
void						lld(t_cw *cw, t_coach *coach, t_op *op);
void						lldi(t_cw *cw, t_coach *coach, t_op *op);
void						or(t_cw *cw, t_coach *coach, t_op *op);
void						st(t_cw *cw, t_coach *coach, t_op *op);
void						sti(t_cw *cw, t_coach *coach, t_op *op);
void						sub(t_cw *cw, t_coach *coach, t_op *op);
void						xor(t_cw *cw, t_coach *coach, t_op *op);
void						zjmp(t_cw *cw, t_coach *coach, t_op *op);
int							calc_pos(int pos);

/*
**						END
*/

#endif
