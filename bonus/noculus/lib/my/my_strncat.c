/*
** my_strncat.c for my_strncat in /home/arzel_p/sandbox
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Tue Oct  6 17:45:46 2015 Paskal Arzel
** Last update Tue Oct  6 19:00:40 2015 Paskal Arzel
*/

int	my_strncat(char *dest, char *src, int n)
{
  int	i;
  int	a;

  i = 0;
  while (dest[i] != '\0')
    i = i + 1;
  a = 0;
  while (a < n && src[a] != '\0')
    {
      dest[i + a] = src[a];
      a = a + 1;
    }
  dest[i + a] = '\0';
}
