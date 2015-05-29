/*
** my.h<2> for minitalk in /home/sayyou_y/rendu/PSU-System-Unix/PSU_2014_minitalk/server/include
** 
** Made by Youssef Sayyouri
** Login   <sayyou_y@epitech.net>
** 
** Started on  Sun Mar 22 17:26:41 2015 Youssef Sayyouri
** Last update Sun Mar 22 17:52:53 2015 Youssef Sayyouri
*/

#ifndef MY_H_
# define MY_H_

char	*dec_to_bin(int dec);
void	my_putchar(char c);
void	my_putstr(char *str);
void	get_binary(int	b);
void	my_sig(int	sig);
void	get_sig();
void	my_put_nbr(int nbr);
void	send_char(int serv_pid, char c);
void	binary(int serv_pid, char c);
int	my_str_isnum(char *str);
int	my_getnbr(char *str);
int	my_pow(int nb, int power);
int	bin_to_dec(char *bin);

#endif /* !MY_H_ */
