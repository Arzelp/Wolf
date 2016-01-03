/*
** my_strstr.c for strstr in /home/arzel_p/sandbox
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Mon Oct  5 15:39:50 2015 Paskal Arzel
** Last update Thu Oct  8 16:37:01 2015 Paskal Arzel
*/

int	strfind(char *str, char *tofind, int a, int b)
{
  int	c;
  int	d;

  c = 0;
  while (c <= a)
    {
      if (str[c] == tofind[0])
	{
	  d = c;
	  while (str[c] == tofind[c - d])
	    {
	      c = c + 1;
	      if (c == d + b)
		return d;
	    }
        }
      c = c + 1;
    }
  return '\0';
}

char	*my_strstr(char *str, char *tofind)
{
  int	a;
  int	b;

  a = 0;
  b = 0;
  while (str[a] != '\0')
    a = a + 1;
  while (tofind[b] != '\0')
    b = b + 1;
  b = strfind(str, tofind, a, b);
  while (str[b] != '\0')
    {
      my_putchar(str[b]);
      b = b + 1;
    }
  my_putstr(str);
}
