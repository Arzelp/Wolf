/*
** my_put_unbr.c for my_put_unbr in /home/arzel_p/lib/my
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Thu Nov  5 18:43:07 2015 Paskal Arzel
** Last update Thu Nov  5 19:18:04 2015 Paskal Arzel
*/

unsigned int	my_put_unbr(unsigned int a)
{
  unsigned int  f;
  unsigned int	b;

  b = a;
  f = 1;
  if (a == 0)
    my_putchar(48);
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
