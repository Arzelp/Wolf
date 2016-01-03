/*
** my_square_root.c for my_square_root.c in /home/arzel_p/sandbox
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Fri Oct  2 14:47:53 2015 Paskal Arzel
** Last update Sun Oct 18 15:38:05 2015 Paskal Arzel
*/

int	my_square_root(int nb)
{
  int	a;

  a = 1;
  while (a <= 46341 && a <= nb && nb >= 0)
    {
      if (nb == a * a)
	  return a;
      a = a + 1;
    }
  return (0);
}
