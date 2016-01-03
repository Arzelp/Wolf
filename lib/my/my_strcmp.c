/*
** my_strcmp.c for my_strcmp in /home/arzel_p/sandbox
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Mon Oct  5 18:17:02 2015 Paskal Arzel
** Last update Thu Oct  8 14:58:48 2015 Paskal Arzel
*/

int	my_strcmp(char *s1, char *s2)
{
  int	a;
  char	b;
  char	c;
  int	diff;

  a = 0;
  diff = 0;
  while (s1[a] != '\0' || s2[a] != '\0')
    {
      diff = s1[a] - s2[a];
      if (diff != 0)
	return diff;
      a = a + 1;
    }
  if (s1[a] == '\0' && s2[a] == '\0')
    return (0);
}
