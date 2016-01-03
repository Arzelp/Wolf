/*
** my_put_nbr.c for my_put_nbr in /home/arzel_p/sandbox
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
**
** Started on  Tue Oct  6 12:16:11 2015 Paskal Arzel
** Last update Sun Dec 13 19:31:19 2015 Paskal Arzel
*/

void	my_put_nbr(int a)
{
  int	f;
  int	b;

  b = a;
  f = 1;
  if (a < 0)
    {
      my_putchar('-');
      my_put_nbr(-a);
    }
  while (b >= 10)
    {
      b = b / 10;
      f = f * 10;
    }
  while (f >= 1)
    {
      my_putchar(a / f + 48);
      a = a % f;
      f = f / 10;
    }
}
