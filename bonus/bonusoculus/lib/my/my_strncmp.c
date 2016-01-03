/*
** my_strncmp.c for my_strncmp in /home/arzel_p/sandbox
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Mon Oct  5 18:49:10 2015 Paskal Arzel
** Last update Thu Oct  8 14:59:42 2015 Paskal Arzel
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int   a;
  char  b;
  char  c;
  int   diff;

  a = 0;
  diff = 0;
  while (a < n)
    {
      diff = s1[a] - s2[a];
      if (diff != 0)
        return diff;
      a = a + 1;
    }
  if (a >= n)
    return (0);
}
