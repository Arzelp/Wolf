/*
** chainefull.c for chainefull in /home/arzel_p/sandbox/infaddtrololol
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Mon Oct 19 21:26:13 2015 Paskal Arzel
** Last update Wed Oct 21 16:16:22 2015 Paskal Arzel
*/

#include <stdlib.h>
char    *gosou(char *n1, char *n2, char *res, int e);
char	*gosw(char *np, char *nn, char *res, int e);
char	*traita2(char *res, int a, int i);

char    *gosu(char *n1, char *n2, char *res)
{
  int   b;
  int   c;
  int   e;

  e = 0;
  b = posneg(n1);
  c = posneg(n2);
  if (b == 1)
    res = gosw(n2, n1, res, e);
  else
    res = gosw(n1, n2, res, e);
  return (res);
}

char	*gosou(char *np, char *nn, char *res, int e)
{
  int	i;
  int	lenres;
  int	a;

  lenres = Max(my_strlen(np), my_strlen(nn));
  i = lenres;
  while (--i > 0)
    {
      a = np[i - 1] - nn[i] + 48;
      res = traita2(res, a, i);
    }
  a = np[lenres] - nn[lenres];
  if (e % 2 == 1)
    res[0] = '-';
  else
    res[0] = 1;
  if (res[1] == '\0')
    res[1] = 1;
  return (res);
}
