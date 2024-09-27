/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:51:26 by sabrifer          #+#    #+#             */
/*   Updated: 2024/09/22 20:49:35 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

// lógica da ft_putnbr
void	printme(int bit, int i)
{
	//static int	total = 0;

	//if (i == 0)
	printf("%d\n", bit);
	//total += bit;
	//if (i == 7)
	//	printf("%d\n", total);
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

	return (0);
}
