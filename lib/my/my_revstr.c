/*
** my_revstr.c for my_revstr in /home/arzel_p/sandbox
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Mon Oct  5 12:41:10 2015 Paskal Arzel
** Last update Fri Oct 16 10:10:18 2015 Paskal Arzel
*/

char	*rev(char *str, int n)
{
  int	i;
  int	f;
  int	rev[n];

  i = 0;
  while (str[i] != '\0')
    {
      rev[i] = str[i];
      i = i + 1;
    }
  i = 0;
  while (str[i] != '\0')
    {
      str[n - i] = rev[i];
      i = i + 1;
    }
}

char	*my_revstr(char *str)
{
  int	n;

  n = 0;
  while (str[n] != '\0')
    n = n + 1;
  n = n - 1;
  rev(str, n);
}
