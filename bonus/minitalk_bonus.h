/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 22:28:07 by ulayus            #+#    #+#             */
/*   Updated: 2022/12/10 15:33:03 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <sys/types.h>
# include <limits.h>
# include "../libft/libft.h"
# define PID 0
# define CHAR 1

void	init_handlers(int flag);

typedef struct s_bit_joiner
{
	char			flag;
	pid_t			pid;
	char			c;
	char			*str;
	unsigned char	c_bit;
	pid_t			pid_bit;
	int				nb_bit;
}	t_bit_joiner;	

#endif
