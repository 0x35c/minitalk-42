/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 22:28:07 by ulayus            #+#    #+#             */
/*   Updated: 2022/10/27 11:57:07 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include "libft/libft.h"

typedef struct s_bit_joiner
{
	pid_t			pid;
	char			c;
	char			*str;
	unsigned char	c_bit;
	pid_t			pid_bit;
	int				nb_bit;
}	t_bit_joiner;	

#endif
