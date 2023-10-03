/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:35:37 by facetint          #+#    #+#             */
/*   Updated: 2023/10/03 14:37:21 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int signum, siginfo_t *siginfo, void *unused)
{
	static char	byte = 0;
	static int	slide = 7;

	(void)unused;
	if (signum == SIGUSR2)
		byte += 1 << slide;
	if (slide == 0)
	{
		ft_putchar(byte);
		byte = 0;
		slide = 8;
		kill(siginfo->si_pid, SIGUSR2);
	}
	slide--;
}

int	main(void)
{
	struct sigaction	action;
	int					pid;

	action.sa_sigaction = sig_handler;
	action.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	if (sigaction(SIGUSR1, &action, NULL) == -1 || \
		sigaction(SIGUSR2, &action, NULL) == -1)
		ft_putstr("Sigaction error\n");
	while (1)
		pause();
	return (0);
}
