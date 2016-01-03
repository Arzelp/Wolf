/*
** vecnorm.c for vecnorm in /home/arzel_p/rendu/gfx_wolf3d/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Sun Dec 13 15:32:47 2015 Paskal Arzel
** Last update Wed Dec 16 09:06:40 2015 Paskal Arzel
*/

#include <stdlib.h>
#include <math.h>
#include "my.h"
#include "lapin.h"

double	vecnorm(t_bunny_position *coord0, t_bunny_position *coord1)
{
  double	vecnorm;

  vecnorm = pow(coord1->x - coord0->x, 2) + pow(coord1->y - coord0->y, 2);
  vecnorm = sqrt(vecnorm);
  return (vecnorm);
}
