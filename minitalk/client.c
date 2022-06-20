/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:37:00 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/04/10 00:55:07 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == '\v' || str[i] == '\r' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		res = res * 10 + (str[i++] - '0');
	if (res > 2147483647)
		return (-1);
	return ((int)(res * sign));
}

void	ft_kill(char av, int pid, int bit)
{
	int	err;

	if (((av >> bit) & 1) == 0)
		err = kill(pid, SIGUSR1);
	else
		err = kill(pid, SIGUSR2);
	if (err != 0)
	{
		write(1, "PID NOT CORRECT\n", 16);
		exit(0);
	}
	usleep(400);
}

int	main(int ac, char *av[])
{
	int	pid;
	int	i;
	int	bit;

	i = 0;
	pid = ft_atoi(av[1]);
	if (ac != 3 || pid <= 0)
	{
		write(1, "error\n", 6);
		exit(0);
	}
	while (av[2][i])
	{
		bit = 7;
		while (bit >= 0)
		{
			ft_kill(av[2][i], pid, bit);
			bit--;
		}
		i++;
	}
	return (0);
}
