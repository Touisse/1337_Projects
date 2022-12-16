/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouisse <ytouisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 21:12:34 by ytouisse          #+#    #+#             */
/*   Updated: 2022/12/16 19:47:45 by ytouisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int signal)
{
	static int	received = 0;

	if (signal == SIGUSR1)
		received = 1;
	else
	{
		ft_putstr_fd("Congrats!! Your Message sent to the server.", 1);
		ft_putchar_fd('\n', 1);
		exit(EXIT_SUCCESS);
	}
}

static	void	send_string(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(500);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(500);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_putstr_fd("How To Use : ./client [pid] [message_to_send]\n", 1);
		exit(EXIT_FAILURE);
	}
	ft_putstr_fd("How Many Characters Sent    : ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	pid = ft_atoi(argv[1]);
	if (!pid)
	{
		ft_putstr_fd("Please enter the real PID value!\n", 1);
		exit(EXIT_FAILURE);
	}
	send_string(pid, argv[2]);
	while (1)
		pause();
	return (0);
}
