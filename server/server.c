/*
** server.c for minitalk in /home/sayyou_y/rendu/PSU-System-Unix/PSU_2014_minitalk/server
** 
** Made by Youssef Sayyouri
** Login   <sayyou_y@epitech.net>
** 
** Started on  Sat Mar 21 16:55:59 2015 Youssef Sayyouri
** Last update Wed Apr  1 16:45:03 2015 Youssef Sayyouri
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "../include/my.h"

int	bin_to_dec(char *bin)
{
  int	i;
  int	pow;
  int	result;

  i = 0;
  pow = 7;
  result = 0;
  while (pow >= 0)
    {
      if (bin[i] == '1')
	result = result + my_pow(2, pow);
      pow--;
      i++;
    }
  return (result);
}

void		get_binary(int	b)
{
  static char	*binary;
  static int	i = 0;

  if (i >= 0 && i <= 6)
    {
      if (i == 0)
	if ((binary = malloc(sizeof(char) * 7)) == NULL)
	  {
	    my_putstr("Error: malloc failed !\n");
	    exit(EXIT_FAILURE);
	  }
      binary[i++] = b + '0';
    }
  else if (i == 7)
    {
      binary[i++] = b + '0';
      my_putchar(bin_to_dec(binary));
      i = 0;
      free(binary);
    }
}

void		my_sig(int	sig)
{
  if (sig == SIGUSR1)
    get_binary(1);
  else if (sig == SIGUSR2)
    get_binary(0);
}

void		get_sig()
{
  usleep(1000);
  if (signal(SIGUSR1, my_sig) == SIG_ERR || signal(SIGUSR2, my_sig) == SIG_ERR)
    {
      my_putstr("Error: signal failed\n");
      exit(EXIT_FAILURE);
    }
}

int		main()
{
  my_putstr("Server PID : [");
  my_put_nbr(getpid());
  my_putstr("]\n");
  while (42)
    get_sig();
  return (0);
}
