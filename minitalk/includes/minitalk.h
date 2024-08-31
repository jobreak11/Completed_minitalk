/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 01:30:35 by gyeepach          #+#    #+#             */
/*   Updated: 2024/08/27 00:59:47 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <error.h>
# include "../ft_printf/ft_printf.h"


#define BUFFER_SIZE 1024

typedef struct s_global_state
{
    unsigned char buffer[BUFFER_SIZE];
    int buffer_index;
    unsigned char received_char;
    int bit_count;
} t_global_state;

int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);
int		ft_printf(const char *format, ...);

#endif