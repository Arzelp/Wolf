/*
** my_putstrss.c for putstrsans in /home/arzel_p/sandbox/infaddtrololol
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Wed Oct 21 16:16:04 2015 Paskal Arzel
** Last update Thu Oct 22 17:45:39 2015 Paskal Arzel
*/

void    *my_putstrss(char *res, int lenres)
{
  int   i;

  i = 0;
  if (res[0] == '-')
    {
      i++;
      my_putchar('-');
    }
  while (res[i] < 48 || res[i] > 57)
    i++;
  while (res[i] == '0' && i < lenres)
    i++;
  while (res[i])
    {
      my_putchar(res[i]);
      i++;
    }
}
