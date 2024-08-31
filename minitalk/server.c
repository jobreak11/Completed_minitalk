/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:23:50 by gyeepach          #+#    #+#             */
/*   Updated: 2024/08/31 10:01:02 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

static t_global_state g_state = {{0}, 0, 0, 0};

void handler(int signum, siginfo_t *info, void *context)
{
    (void)context;

    // รับข้อมูลจากสัญญาณ
    g_state.received_char |= (signum == SIGUSR2) << (7 - g_state.bit_count);

    if (++g_state.bit_count == 8) {  // เมื่อครบ 8 บิต
        if (g_state.received_char == '\0') {
            if (g_state.buffer_index > 0)
                write(1, g_state.buffer, g_state.buffer_index);
            g_state.buffer_index = 0;
        } 
        else 
        {
            if (g_state.buffer_index >= BUFFER_SIZE) {
                write(1, g_state.buffer, BUFFER_SIZE);
                g_state.buffer_index = 0;
            }
            g_state.buffer[g_state.buffer_index++] = g_state.received_char;
        }
        g_state.received_char = 0;
        g_state.bit_count = 0;
    }

    // ส่งสัญญาณ ACK
    if (info->si_pid > 0)
        kill(info->si_pid, SIGUSR1);
}

int main(void)
{
    struct sigaction action;

    action.sa_sigaction = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);

    ft_printf("Server PID: %d\n", getpid());

    while (1)
        pause();

    return (0);
}