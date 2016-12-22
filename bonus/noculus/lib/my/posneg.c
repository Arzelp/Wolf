/*
** minmax.c for minmax in /home/arzel_p/sandbox/infaddtrololol
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Mon Oct 19 16:18:58 2015 Paskal Arzel
** Last update Wed Oct 21 16:11:03 2015 Paskal Arzel
*/

int	posneg(char *n)
{
  int	signe;

  signe = 0;
  if (n[0] == '-')
    signe = 1;
  return signe;
}
