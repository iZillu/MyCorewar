# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmuravch <hmuravch@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/31 20:25:25 by hmuravch          #+#    #+#              #
#    Updated: 2019/03/31 20:30:15 by hmuravch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re mre

ASM := asm
VM := corewar

ASM_PATH := compiler/
VM_PATH := vm/


all:
	@ make -C $(ASM_PATH)
	@ make -C $(VM_PATH)
	@ ln -fs $(ASM_PATH)$(ASM) $(ASM)
	@ ln -fs $(VM_PATH)$(VM) $(VM)
	@ chmod 744 $(ASM) $(VM)

mre:
	@ make mre -C $(ASM_PATH)
	@ make mre -C $(VM_PATH)
	@ ln -fs $(ASM_PATH)$(ASM) $(ASM)
	@ ln -fs $(VM_PATH)$(VM) $(VM)
	@ chmod 744 $(ASM) $(VM)
clean:
	@ make clean -C $(ASM_PATH)
	@ make clean -C $(VM_PATH)
fclean:
	@ make fclean -C $(ASM_PATH)
	@ make fclean -C $(VM_PATH)
	@ rm -f $(ASM) $(VM)
re: fclean all