/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:51:26 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/23 10:49:52 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	is_white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (is_white_space(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]) == 1)
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}

// lógica da ft_putnbr
void	printme(int bit, int i)
{
	static int c = 0;
	//printf("%d\n", bit);
	c = c + (bit << i);
	if (i == 7)
	{
		printf("%c", c);
		c = 0;
	}
}

int	ft_ispid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (kill(ft_atoi(str), 0) != 0)
	{
		printf("process != 0\n");
		printf("error kill ft_ispid\n");
	}
	return (1);
}

int	main(int ac, char **av)
{
	char		*str;
	pid_t		pid_server;
	
	if (ac != 3)
	{
		printf("ERROR\n");
		return (0);
	}
	if (!ft_ispid(av[1]))
	{
		printf("ERROR\n");
		return (0);
	}
	pid_server = ft_atoi(av[1]);
	str = av[2];

	
}

/*
int	main(void)
{
	int	num = 212;
	int	i = 0;
	int res = 0;

	while(i < 8)
	{
		res = num >> i;
		printme(res & 1, i);
		//printf("Right shift >> by %d: %d\n", i, num >> i);
		i++;
	}
	printf("\n");
	i = 0;
	char c = 'A';
	while(i < 8)
	{
		res = c >> i;
		printme(res & 1, i);
		//printf("Right shift >> by %d: %d\n", i, num >> i);
		i++;
	}
	printf("\n");
	i = 0;
	char *str = "The standard chunk of Lorem Ipsum used since the 1500s is reproduced below for those interested. Sections 1.10.32 and 1.10.33 from de Finibus Bonorum et Malorum by Cicero are also reproduced in their exact original form, accompanied by English versions from the 1914 translation by H. Rackham.\n";
	while (*str)
	{
		i = 0;
		while(i < 8)
		{
			res = *str >> i;
			printme(res & 1, i);
			i++;
		}	
		str++;
	}

	return (0);
}*/
