/*
** my_convert_base.c for convrt_base in /home/arzel_p/lib/my
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Thu Nov  5 19:34:59 2015 Paskal Arzel
** Last update Mon Nov  9 23:13:46 2015 Paskal Arzel
*/

void	my_put_nbr_base(unsigned int a, int baselen)
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
      b = (a / f >= 10) ? a / f + 87 : a / f + 48;
      my_putchar(b);
      a = a % f;
      f = f / baselen;
    }
}
