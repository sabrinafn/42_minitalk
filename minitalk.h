#ifndef MINITALK_H
#define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/wait.h>

int	ft_isdigit(int c);
int	ft_atoi(const char *str);
void ft_putstr_fd(char *s, int fd);
void ft_putnbr_fd(int n, int fd);

#endif
