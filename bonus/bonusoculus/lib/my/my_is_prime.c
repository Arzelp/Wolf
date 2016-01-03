/*
** my_is_prime.c for my_is_prime in /home/arzel_p
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Fri Oct  2 15:53:08 2015 Paskal Arzel
** Last update Mon Oct  5 11:26:54 2015 Paskal Arzel
*/

int	my_is_prime(int nb)
{
  int	a;

  a = 2;
  if (nb == 2)
    return (1);
  while (a < nb)
    {
      if (nb % a == 0)
        return (0);
      a = a + 1;
    }
  if (nb == 0 || nb == 1)
    return (0);
  return (1);
}
