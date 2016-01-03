/*
** my_str_isalpha.c for my_str_isalpha in /home/arzel_p/sandbox
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Mon Oct  5 22:56:47 2015 Paskal Arzel
** Last update Mon Oct  5 23:09:21 2015 Paskal Arzel
*/

int	my_str_isalpha(char *str)
{
  int a;

  a = 0;
  while (str[a] != '\0')
    {
      if ((str[a] < 97 && (str[a] < 65 || str[a] > 90)) || str[a] > 122)
	return (0);
      a = a + 1;
    }
  return (1);
}
