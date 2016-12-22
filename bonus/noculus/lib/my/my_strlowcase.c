/*
** my_strlowcase.c for strlowcase in /home/arzel_p/sandbox
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Mon Oct  5 22:43:38 2015 Paskal Arzel
** Last update Thu Oct  8 15:05:49 2015 Paskal Arzel
*/

char	*my_strlowcase(char *str)
{
  int   a;

  a = 0;
  while (str[a] != '\0')
    {
      if (str[a] >= 65 && str[a] <= 90)
	str[a] = str[a] + 32;
      a++;
    }
  return (str);
}
