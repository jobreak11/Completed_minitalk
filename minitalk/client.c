/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeepach <gyeepach@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:23:56 by gyeepach          #+#    #+#             */
/*   Updated: 2024/08/27 01:05:58 by gyeepach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

volatile sig_atomic_t g_acknowledged = 0;

static void handler(int sig)
{
    (void)sig;
    g_acknowledged = 1;
}

static void send_byte_to_bit(unsigned char byte, int pid)
{
  int i;
  
  i = 7;
  while (i >= 0) 
  {
    g_acknowledged = 0;
      if (byte & (1 << i))
          kill(pid, SIGUSR2);
      else
          kill(pid, SIGUSR1);
    while (!g_acknowledged)
    {
    } 
    --i;
  }
}

static void send_message(int pid, const char *message)
{
    size_t i = 0;

    while (message[i] != '\0')
    {
        send_byte_to_bit((unsigned char)message[i], pid);
        i++;
    }
    send_byte_to_bit('\0', pid);  // ส่งสัญญาณสิ้นสุดข้อความ
}

int main(int argc, char *argv[])
{
    struct sigaction action;
    int pid;

    if (argc != 3)
    {
        write(2, "Usage: ./client <PID> <message>\n", 32);
        return (EXIT_FAILURE);
    }

    pid = ft_atoi(argv[1]);

    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(SIGUSR1, &action, NULL);

    send_message(pid, argv[2]);

    return (EXIT_SUCCESS);
}
