/*
** my_strcpy.c for my_strcpy in /home/arzel_p/sandbox
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Mon Oct  5 11:46:31 2015 Paskal Arzel
** Last update Mon Oct  5 12:29:03 2015 Paskal Arzel
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
}
