/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouisse <ytouisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 21:12:34 by ytouisse          #+#    #+#             */
/*   Updated: 2022/12/09 14:42:51 by ytouisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_received = 0;

void	char_to_bin(int pid, unsigned char c)
{
	int				i;
	unsigned char	mask;

	i = 7;
	mask = 1u << i;
	while (mask)
	{
		g_received = 0;
		if (mask & c)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		if (!g_received)
			pause();
		i--;
		mask >>= 1;
	}
}

void	handle_string(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		char_to_bin(pid, msg[i]);
		i++;
	}
	char_to_bin(pid, 0);
}

void	handler(int signal, siginfo_t *client, void *ucontext)
{
	(void)ucontext;
	(void)client;
	if (signal == SIGUSR1)
		g_received = 1;
	else if (signal == SIGUSR2)
	{
		ft_putstr_fd("Congrats!! Your Message sent to the server.", 1);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char *argv[])
{
	pid_t				pid;
	struct sigaction	sig;

	if (argc != 3)
	{
		ft_putstr_fd("HINT : ./client <pid> <message_to_send>\n", 1);
		exit(EXIT_FAILURE);
	}
	sig.sa_flags = SA_SIGINFO | SA_RESTART;
	sig.sa_sigaction = handler;
	sigemptyset(&(sig.sa_mask));
	sigaction(SIGUSR2, &sig, NULL);
	sigaction(SIGUSR1, &sig, NULL);
	pid = ft_atoi(argv[1]);
	if (!pid)
	{
		ft_putstr_fd("Please enter the real PID value!\n", 1);
		exit(EXIT_FAILURE);
	}
	handle_string(pid, argv[2]);
}
