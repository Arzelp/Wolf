/*
** my_str_isprintable.c for my_str_isprinalsjsjosgjsf in /home/arzel_p/sandbox
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Mon Oct  5 23:26:41 2015 Paskal Arzel
** Last update Mon Oct  5 23:32:26 2015 Paskal Arzel
*/

int	my_str_isprintable(char *str)
{
  int a;

  a = 0;
  while (str[a] != '\0')
    {
      if (str[a] < 32 || str[a] > 126)
        return (0);
      a = a + 1;
    }
  return (1);
}
