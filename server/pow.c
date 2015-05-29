/*
** pow.c for minitalk in /home/sayyou_y/rendu/PSU-System-Unix/PSU_2014_minitalk/server
** 
** Made by Youssef Sayyouri
** Login   <sayyou_y@epitech.net>
** 
** Started on  Sun Mar 22 17:24:07 2015 Youssef Sayyouri
** Last update Sun Mar 22 17:24:26 2015 Youssef Sayyouri
*/

int	my_pow(int nb, int power)
{
  int	result;

  result = 1;
  while (power > 0)
    {
      result *= nb;
      power--;
    }
  return (result);
}
