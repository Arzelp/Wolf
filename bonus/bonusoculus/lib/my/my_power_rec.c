/*
** my_power_rec.c for my_power_rec in /home/arzel_p/sandbox
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Fri Oct  2 12:04:11 2015 Paskal Arzel
** Last update Mon Oct  5 11:22:03 2015 Paskal Arzel
*/

int	my_power_rec(int nb, int power)
{
  int	b;

  b = power;
  if (power < 0)
    return (0);
  if (power > 0)
    {
      nb = nb * my_power_rec(nb, power - 1);
      b = b - 1;
    }
  if (power == 0)
    return (1);
  if (b == 0)
    return (nb);
}
