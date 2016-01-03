/*
** my_find_prime_sup.c for my_find_prime_sup in /home/arzel_p/sandbox
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Fri Oct  2 22:58:35 2015 Paskal Arzel
** Last update Fri Oct  9 17:25:18 2015 Paskal Arzel
*/

int	findi(int nb)
{
  int	a;
  int	d;

  a = 2;
  while (a < nb)
    {
      d = nb % a;
      if (d == 0)
        {
	  a = 2;
	  nb = nb + 1;
	  findi(nb);
        }
      a = a + 1;
    }
  return nb;
}

int	my_find_prime_sup(int nb)
{
  int	b;
  int	c;

  if (nb <= 2)
    return (2);
  c = findi(nb);
  return c;
}
