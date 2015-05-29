/*
** server.c for minitalk in /home/sayyou_y/rendu/PSU-System-Unix/PSU_2014_minitalk
** 
** Made by Youssef Sayyouri
** Login   <sayyou_y@epitech.net>
** 
** Started on  Sat Mar 21 14:19:21 2015 Youssef Sayyouri
** Last update Sun Mar 22 17:52:02 2015 Youssef Sayyouri
*/

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include "../include/my.h"

char	*dec_to_bin(int dec)
{
  int	i;
  int	x;
  char	*bin;

  i = 128;
  x = 0;
  if ((bin = malloc(sizeof(char) * 7)) == NULL)
    {
      my_putstr("Error: Malloc failed!\n");
      exit(EXIT_FAILURE);
    }
  while (i != 0)
    {
      if (dec >= i)
	{
	  dec = dec - i;
	  bin[x] = '1';
	}
      else
	bin[x] = '0';
      i = i / 2;
      x++;
    }
  return (bin);
}

void	send_char(int serv_pid, char c)
{
  if (c == '1')
    {
      if (kill(serv_pid, SIGUSR1) == -1)
	{
	  my_putstr("Error: Server connection lost !\n");
	  exit(EXIT_FAILURE);
	}
    }
  else
    {
      if (kill(serv_pid, SIGUSR2) == -1)
	{
	  my_putstr("Error: Server connection lost !\n");
	  exit(EXIT_FAILURE);
	}
    }
}

void	binary(int serv_pid, char c)
{
  int	i;
  char	*binary;

  i = 0;
  binary = dec_to_bin(c);
  while (i < 8)
    {
      usleep(1000);
      send_char(serv_pid, binary[i]);
      i++;
    }
  free(binary);
}

int	main(int ac, char **av)
{
  int	i;
  int	serv_pid;
  char	*str;

  if (ac != 3)
    {
      my_putstr("Usae: ./client [ServerPID] [Message]\n");
      return (0);
    }
  i = 0;
  if (my_str_isnum(av[1]) == -1)
    {
      my_putstr("Usage: The ServerPID is a number only !\n");
      return (0);
    }
  else
    serv_pid = my_getnbr(av[1]);
  str = av[2];
  while (str[i] != '\0')
    binary(serv_pid, str[i++]);
  return (0);
}
