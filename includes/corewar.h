/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 09:23:30 by hmuravch          #+#    #+#             */
/*   Updated: 2019/03/27 19:24:10 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	COREWAR_H

# define COREWAR_H

# include "libft.h"
# include "op.h"
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>

# define MODULE(X)	(((X) < 0) ? (-(X)) : (X))
# define ID(X)		((X) - 1)

typedef struct s_player		t_player;
typedef struct s_coach		t_coach;
typedef struct s_cw			t_cw;
typedef struct s_operations	t_op;

typedef struct			s_player
{
	int					id;
	int					fd;
	int					code_size;
	char				code[MEM_SIZE];
	char				name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
	size_t				crnt_lives;	// number of reports that player is alive during current cycles_to_die period
	size_t				prev_lives; // number of reports that player is alive during previous cycles_to_die period
	ssize_t				last_cycle_check;			// cycle's number, on which player was assigned as alive last time

}						t_player;

typedef	struct			s_coach
{
	unsigned int		id;
	unsigned int		carry : 1;
	unsigned int		shift; 				// number of bytes to shift
	unsigned int		cycles_to_wait;
	ssize_t				last_cycle_check;	// cycle's number when live operator was executed last time
	unsigned char		op_id;
	unsigned char		arg_type[3];		// types of op's each argument before operator execution
	int					pc;					// address of the next operator to execute at memory (change name of var)
	int					reg[17];
	t_player			*player;			// owner
	struct	s_coach		*next;

}						t_coach;

typedef struct			s_cw
{
	bool				f_dump;
	bool				print_aff;

	unsigned char		map[MEM_SIZE];
	t_player			player[MAX_PLAYERS];
	t_player			*last_player;
	t_coach				*coach;

	int					amt_players;
	size_t				amt_lives;
	size_t				amt_checks;			// game param
	size_t				amt_coaches;
	size_t				prev_cycles_alive;
	ssize_t				cycles;				// number of cycles that was passed after start
	ssize_t				cycles_to_dump;
	ssize_t				cycles_to_die;		// game param
	ssize_t				cycles_after_check;	// number of cycles that was passed after last rules check

}						t_cw;

typedef struct			s_operations
{
	char				*name;
	unsigned char		amt_args;
	unsigned char		arg_type[3];
	unsigned char		op_id;
	unsigned int		cycles;
	char				*description;
	bool				codage;
	int					label_size;
	void				(*func)(t_cw *, t_coach *, t_op *);
}						t_op;


void                    print_help(void);
void					ft_abort(char *s);
void					set_coach(t_cw *cw);
void					start_game(t_cw *cw);
void					print_start(t_cw *cw);
void					print_result(t_cw *cw);
void					check_cycles_to_die(t_cw *cw);
void					parse_flags(int	ac, char **av, t_cw *cw);
void					print_map(unsigned char *map); 
void					add_coach(t_coach **list, t_coach *new_coach);
void					parse_types(t_cw *cw, t_coach *coach, t_op *op);
void					int_to_bytecode(unsigned char *map, int position, int value, int size);
int						bytecode_to_int(const unsigned char *map, int size, int position);
int						shift_size(char arg_type, t_op *op);
int						validate_arg_types(t_coach *coach, t_op *op);
int 	                validate_args(t_coach *coach, t_cw *cw, t_op *op);
int						parse_args(t_cw *cw, t_coach *coach, int num, t_op *op);
unsigned int			update_shift(t_coach *coach, t_op *op);
t_cw					*initialize_cw(void);
t_coach					*clone_coach(t_coach *crnt_coach, int shift);
t_coach					*initialize_coach(t_player	*player, int pc);

/*
**						OPERATIONS
*/

void					add(t_cw *cw, t_coach *coach, t_op *op);
void					aff(t_cw *cw, t_coach *coach, t_op *op);
void					and(t_cw *cw, t_coach *coach, t_op *op);
void					my_fork(t_cw *cw, t_coach *coach, t_op *op);
void					ld(t_cw *cw, t_coach *coach, t_op *op);
void					ldi(t_cw *cw, t_coach *coach, t_op *op);
void					lfork(t_cw *cw, t_coach *coach, t_op *op);
void			    	live(t_cw *cw, t_coach *coach, t_op *op);
void					lld(t_cw *cw, t_coach *coach, t_op *op);
void					lldi(t_cw *cw, t_coach *coach, t_op *op);
void					or(t_cw *cw, t_coach *coach, t_op *op);
void					st(t_cw *cw, t_coach *coach, t_op *op);
void					sti(t_cw *cw, t_coach *coach, t_op *op);
void					sub(t_cw *cw, t_coach *coach, t_op *op);
void					xor(t_cw *cw, t_coach *coach, t_op *op);
void					zjmp(t_cw *cw, t_coach *coach, t_op *op);

/*
**						END
*/

#endif
