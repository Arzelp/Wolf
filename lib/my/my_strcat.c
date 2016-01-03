/*
** my_strcat.c for my_strcat in /home/arzel_p/sandbox
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Tue Oct  6 10:38:39 2015 Paskal Arzel
** Last update Thu Oct  8 15:35:07 2015 Paskal Arzel
*/

char	*my_strcat(char *dest, char *src)
{
  int	n;
  int	a;

  a = 0;
  n = 0;
  while (dest[a] != '\0')
    a = a + 1;
  while (src[n] != '\0')
    {
      dest[a] = src[n];
      n = n + 1;
      a = a + 1;
    }
  dest[a] = '\0';
  return dest;
}
