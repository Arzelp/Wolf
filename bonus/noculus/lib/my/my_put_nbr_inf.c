/*
** my_put_nbr_inf.c for put_nbr_int in /home/arzel_p/lib/my
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Fri Oct 23 21:36:49 2015 Paskal Arzel
** Last update Fri Oct 23 21:47:01 2015 Paskal Arzel
*/

void	my_put_nbr_inf(char *nb)
{
  int	i;

  i = 0;
  while (nb[i] != '\0')
    {
      my_putchar(nb[i]);
      i++;
    }
}
