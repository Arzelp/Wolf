/*
** my_getnbr.c for my_getmnbr in /home/arzel_p/sandbox
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
**
** Started on  Sat Oct 10 16:27:53 2015 Paskal Arzel
** Last update Sun Jan  3 16:49:37 2016 Paskal Arzel
*/

#include <stdlib.h>

int	posineg(char *str, int i, int nb)
{
  int	c;

  c = 0;
  i = 0;
  while (str[i] == '+' || str[i] == '-')
    {
      if (str[i] == '-')
	c++;
      i++;
    }
  if (c % 2 == 1)
    nb = nb * -1;
  return (nb);
}

int	multipl(int i, int a, char *str)
{
  long	d;
  long	f;
  int	p;

  d = 0;
  p = i;
  f = 1;
  while (str[i] >= 48 && str[i] <= 57)
    {
      f = f * 10;
      i++;
    }
  f = f / 10;
  i = p;
  while (str[i] >= 48 && str[i] <= 57)
    {
      d = d + (str[i] - 48) * f;
      f = f / 10;
      i++;
      if (d > 2147483647 || d < -2147483648)
	return (0);
    }
  return (d);
}

int	my_getnbr(char *str)
{
  int	i;
  int	a;
  int	nb;
  int	b;

  if (str == NULL)
    return (-1);
  i = 0;
  while (str[i] == '+' || str[i] == '-')
    i++;
  b = i;
  while (str[i] >= 48 && str[i] <= 57)
      i++;
  a = i;
  i = b;
  nb = multipl(i, a, str);
  nb = posineg(str, i, nb);
  return (nb);
}
