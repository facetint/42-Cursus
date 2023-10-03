/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:32:58 by facetint          #+#    #+#             */
/*   Updated: 2023/10/03 14:36:51 by facetint         ###   ########.fr       */
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
		ft_putstr("Invalid PID !\n");
		exit(1);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		i = -1;
		while (av[2][++i])
			send_signal(pid, av[2][i]);
		send_signal(pid, '\0');
	}
	else
		ft_putstr("Invalid arguments !\n");
	return (0);
}
