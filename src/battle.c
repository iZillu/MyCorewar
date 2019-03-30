/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:15:32 by hmuravch          #+#    #+#             */
/*   Updated: 2019/03/30 22:19:17 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_op	op_tab[17] =
{
	{0, 0, {0}, 0, 0, 0, 0, 0, NULL},
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 4, &live},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 4, &ld},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 4, &st},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 4, &add},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 4, &sub},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 4, &and},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 4, &or},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 4, &xor},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 2, &zjmp},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 2, &ldi},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 2, &sti},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 2, &my_fork},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 4, &lld},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 2, &lldi},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 2, &lfork},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 4, &aff}
};

static inline void	move_coach(t_coach *coach)
{
	coach->pc += coach->shift;
	coach->pc %= MEM_SIZE;
	coach->shift = 0;
	ft_bzero(coach->arg_type, 3);
}

static inline void	update_op_id(t_cw *cw, t_coach *crnt_coach)
{
	// static int in;
	// static int full_in;
	
	// printf("YA %i\n", in++);
	// printf("PC %i\n", crnt_coach->pc);
	crnt_coach->op_id = cw->map[crnt_coach->pc];
	// printf("CODE %i\n", crnt_coach->op_id);
	if (cw->map[crnt_coach->pc] >= 1 && cw->map[crnt_coach->pc] <= 16)
	{
		// printf("VOSHEL %i\n", full_in++);
		crnt_coach->cycles_to_wait = op_tab[crnt_coach->op_id].cycles;
	}
}

static inline void	execute_operation(t_coach *coach, t_cw *cw)
{
	t_op			*op;
	// static int i;

	// printf(" %4i   |   PC %4i   |   CYCLE_WAIT %4i \n\n", i++, coach->pc, coach->cycles_to_wait);
	op = NULL;
	if (coach->cycles_to_wait == 0)
	{
		// printf("HERE I AM\n");
		update_op_id(cw, coach);
		// printf("ID %i\n\n", coach->op_id);
	}
	if (coach->cycles_to_wait > 0)
		coach->cycles_to_wait--;
	if (coach->cycles_to_wait == 0)
	{
		// printf("I\n");
		if (coach->op_id >= 1 && coach->op_id <= 16)
		{
			// printf("got\n");
			// printf("in\n");
			op = &op_tab[coach->op_id];
			// printf("NAME IS - %s\n\n", op->name);
			parse_types(cw, coach, op);
			// printf("one %d, two %d, three %d\n", coach->arg_type[0], coach->arg_type[1], coach->arg_type[2]);
			if (validate_arg_types(coach, op) && validate_args(coach, cw, op))
			{
				// printf("ALO EBAT\n");
				op->func(cw, coach, op);
			}
			else
				coach->shift += update_shift(coach, op);
		}
		else
			coach->shift = 1;
		move_coach(coach);
		// if (coach->carry) {
		// 	ft_printf("vm->cycle: %d; hui sosi\n", cw->cycles);
		// } 
	}
}

void		start_game(t_cw *cw)
{
	t_coach	*crnt_coach;
	// static int i;

	while(cw->amt_coaches)
	{
		// printf("%zu\n", cw->amt_coaches);
		if (cw->cycles_to_dump == cw->cycles)
		{
			print_map(cw->map);
			exit(0);
		}
		++cw->cycles && cw->cycles_after_check++;
		if (cw->cycles == 1000)
			ft_printf("");
		crnt_coach = cw->coach;
		while (crnt_coach)
		{
			execute_operation(crnt_coach, cw);
			crnt_coach = crnt_coach->next;
		}
		if (cw->cycles_to_die == cw->cycles_after_check || cw->cycles_to_die <= 0)
			check_cycles_to_die(cw);
		// printf("%i\n", i++);
	}
}