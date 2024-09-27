/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:51:26 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/23 10:28:41 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

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
	char *str = "Hello World!\n";
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
}
