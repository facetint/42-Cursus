/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:32:02 by facetint          #+#    #+#             */
/*   Updated: 2023/10/03 11:32:09 by facetint         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, char c)
{
	int	slide;
	int	error;

	slide = 7;
	error = 0;
	while (slide >= 0)
	{
		if ((c >> slide & 1) == 0)
			error = kill(pid, SIGUSR1);
		else
			error = kill(pid, SIGUSR2);
		slide--;
		usleep(200);
	}
	if (error == -1)
	{
		ft_putstr("Invalid PID\n");
		exit(1);
	}
}

void	sig_handler(int signum, siginfo_t *siginfo, void *unused)
{
	static int	received = 0;

	(void)unused;
	(void)siginfo;
	if (signum == SIGUSR2)
	{
		if (!received)
		{
			ft_putstr("Message received by server\n");
			received = 1;
		}
	}
}

int	main(int ac, char **av)
{
	struct sigaction	action;
	int					pid;
	int					i;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = sig_handler;
	sigaction(SIGUSR2, &action, NULL);
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		i = -1;
		while (av[2][++i])
			send_signal(pid, av[2][i]);
	}
	else
		ft_putstr("Invalid arguments\n");
	return (0);
}
