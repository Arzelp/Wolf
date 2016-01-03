/*
** my_put_hexamaj.c for my_put_hexamaj in /home/arzel_p/lib/my
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Fri Nov  6 20:33:12 2015 Paskal Arzel
** Last update Mon Nov  9 23:42:14 2015 Paskal Arzel
*/

void	my_put_hexamaj(unsigned int a, int baselen)
{
  unsigned int   f;
  unsigned int   b;

  b = a;
  f = 1;
  if (a == 0)
    my_putchar('0');
  if (a < 0)
    {
      my_putchar('-');
      my_put_nbr(-a);
    }
  while (b >= baselen)
    {
      b = b / baselen;
      f = f * baselen;
    }
  while (f >= 1)
    {
      b = (a / f >= 10) ? a / f + 55 : a / f + 48;
      my_putchar(b);
      a = a % f;
      f = f / baselen;
    }
}
