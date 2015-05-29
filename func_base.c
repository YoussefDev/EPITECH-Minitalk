/*
** func_base.c for minitalk in /home/sayyou_y/rendu/PSU-System-Unix/PSU_2014_minitalk
** 
** Made by Youssef Sayyouri
** Login   <sayyou_y@epitech.net>
** 
** Started on  Sat Mar 21 19:52:10 2015 Youssef Sayyouri
** Last update Sun Mar 22 13:12:15 2015 Youssef Sayyouri
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    my_putchar(str[i++]);
}

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
	i++;
      else
	return (-1);
    }
  return (0);
}

int	my_getnbr(char *str)
{
  int	i;
  int	nbr;
  int	neg;

  i = 0;
  nbr = 0;
  neg = 1;
  while (str[i] == '-')
    {
      neg = neg * -1;
      i++;
    }
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
        return (nbr * neg);
      nbr = nbr * 10 + (str[i] - '0');
      i++;
    }
  return (nbr * neg);
}

void	my_put_nbr(int nbr)
{
  int	neg;

  neg = 0;
  if (nbr < 0)
    {
      my_putchar('-');
      if (nbr == -2147483648)
        {
          neg = 1;
          nbr++;
        }
      nbr = nbr * -1;
    }
  if (nbr >= 10)
    my_put_nbr(nbr / 10);
  if (neg == 1)
    {
      neg = 0;
      my_putchar(nbr % 10 + '1');
    }
  else
    my_putchar(nbr % 10 + '0');
}
