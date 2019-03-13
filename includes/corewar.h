/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 09:23:30 by hmuravch          #+#    #+#             */
/*   Updated: 2019/03/11 18:01:15 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	COREWAR_H

# define COREWAR_H

# include "libft.h"
# include "op.h"
# include <stdlib.h>
# include <stdio.h>

# define CONVERT(X) (((X) < 0) ? (-(X)) : (X))

typedef struct			s_player
{
	int					id;
	int					code_size;
	char				*name;
	char				*comment;
	char				*code;
	size_t				current_amt_lives;	// number of reports that player is alive during current cycles_to_die period
	size_t				previous_amt_lives; // number of reports that player is alive during previous cycles_to_die period
	ssize_t				last_cycle_check;			// cycle's number, on which player was assigned as alive last time

}						t_player;

typedef	struct			s_coach
{
	char				op_id;
	unsigned int		carry : 1;
	unsigned int		id;
	unsigned int		shift; 				// number of bytes to shift
	unsigned int		cycles_to_wait;
	ssize_t				last_cycle_check;			// cycle's number when live operator was executed last time
	char				arg_type[4];		// types of op's each argument before operator execution
	int					pc;					// address of the next operator to execute at memory (change name of var)
	int					reg[17];
	t_player			*player;			// owner
	struct	s_coach		*next;

}						t_coach;

struct					s_operations
{
	char				*name;
	unsigned char		amt_args;
	unsigned char		args[3];
	unsigned char		op_id;
	unsigned int		cycles;
	char				*description;
	bool				codage;
	bool				label_size;
	void				(*func)(t_cw *, t_coach *, t_op *);
}						t_op;


typedef struct			s_cw
{
	char				map[MEM_SIZE];
	t_player			player[MAX_PLAYERS];
	size_t				amt_players;
	t_player			*last_player;
	t_coach				*coach;
	size_t				amt_lives;
	size_t				amt_coaches;
	ssize_t				cycles;				// number of cycles that was passed after start
	size_t				prev_cycles_alive;
	ssize_t				cycle_to_dump;
	ssize_t				cycles_to_die;		// game param
	ssize_t				cycles_after_check;	// number of cycles that was passed after last rules check
	size_t				amt_checks;			// game param
	bool				f_dump;
	bool				print_aff;

}						t_cw;

void					abort(char *s);
void                    print_help(void);
void					check_cycles_to_die(t_cw *cw);
void					parse_flags(int	argc, char **argv, t_cw *cw);
void					parse_types(t_cw *cw, t_coach *coach, t_op *op);
void					convert_integer(char *map, int position, int value, int size);
int						convert_bytecode(const char *map, int size, int position);
int						shift_size(char arg_type, t_op *op);
int						validate_arg_types(t_coach *coach, t_op *op);
int 	                validate_args(t_coach *coach, t_cw *cw, t_op *op);
int						parse_args(t_cw *cw, t_coach *coach, int num, t_op *op);
unsigned int			update_shift(t_coach *coach, t_op *op);
t_cw					*initializer_cw(void);
t_coach					*clone_coach(t_coach *crnt_coach, int shift)

/*
**						OPERATIONS
*/

void					add(t_cw *cw, t_coach *coach, t_op *op);
void					aff(t_cw *cw, t_coach *coach, t_op *op);
void					and(t_cw *cw, t_coach *coach, t_op *op);
void					fork(t_cw *cw, t_coach *coach, t_op *op);
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
