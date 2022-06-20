/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:37:20 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/04/10 01:08:59 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

// void    handle_sigtstp(int sig)
// {
//     printf("Stop not allowed\n");
// }

int	g_pid;

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write (1, "-2147483648", 11);
	else if (n <= 9)
		ft_putchar(n + '0');
	else if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
		ft_putnbr(n);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

char	convert(char *str)
{
	int		i;
	char	result;
	int		power;

	i = 0;
	power = 1;
	result = 0;
	while (str[i])
		i++;
	while (--i >= 0)
	{
		result += power * (str[i] - '0');
		power *= 2;
	}
	return (result);
}

void	handle_f(int sig, siginfo_t *info, void *p)
{
	static char	str[9];
	static int	count;
	char		c;

	p = NULL;
	if (g_pid != info->si_pid)
	{
		g_pid = info->si_pid;
		str[0] = '\0';
		count = 0;
	}
	if (sig == SIGUSR1)
		str[count++] = '0';
	else if (sig == SIGUSR2)
		str[count++] = '1';
	if (count == 8)
	{
		str[count] = '\0';
		c = convert(str);
		count = 0;
		if (c == '\0')
			kill(info->si_pid, SIGUSR1);
		write(1, &c, 1);
	}
}

int	main(int ac, char *av[])
{
	struct sigaction	sa;
	int					i;

	(void)ac;
	(void)av;
	i = getpid();
	ft_putnbr(i);
	sa.sa_sigaction = &handle_f;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
		pause();
	return (0);
}
