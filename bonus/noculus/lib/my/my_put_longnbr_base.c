/*
** my_put_longnbr_base.c for longnbrbase in /home/arzel_p/lib/my
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Tue Nov 10 14:55:59 2015 Paskal Arzel
** Last update Tue Nov 10 14:59:01 2015 Paskal Arzel
*/

long long	my_put_longnbr_base(long long a, int baselen)
{
  long long	f;
  long long	b;

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
      b = (a / f >= 10) ? a / f + 87 : a / f + 48;
      my_putchar(b);
      a = a % f;
      f = f / baselen;
    }
}
