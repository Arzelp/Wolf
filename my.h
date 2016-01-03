/*
** my.h for my.h in /home/arzel_p/rendu/gfx_wolf3d/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Sun Dec 13 16:48:02 2015 Paskal Arzel
** Last update Wed Dec 16 10:03:14 2015 Paskal Arzel
*/

#include "lapin.h"

typedef struct s_list
{
  t_bunny_window	*win;
  char			*name;
  char			**map;
  float			posx;
  float			posy;
  int			height;
  int			width;
  float			angle;
  t_bunny_ini		*ini;
}t_list;

typedef struct s_pos
{
  float	x;
  float	y;
}t_pos;

typedef struct s_vect
{
  float x;
  float y;
}t_vect;

int	desscol(t_bunny_pixelarray *pix, int i, int height);
int	calcdistance(t_list *list, t_pos *scrpos);
void	vol();
int	drawit(t_bunny_pixelarray *pix, t_list *list);
int	lenscope(char *str);
char	*getscope(char *str);
int	my_getcnbr(const char *str);
float	my_getnbrfloat(char *str);
int	my_getnbr(char *str);
void	my_putchar(char c);
void	my_putstr(char *str);
int	calcx(t_list *list, float vx, float vy);
int	calcy(t_list *list, float vx, float vy);
void	my_put_nbr(int a);
t_bunny_response	mainresp(t_bunny_event_state state,
				 t_bunny_keysym keysym,
				 void *_data);
void	getmap(char *str, t_list *list);
double	vecnorm(t_bunny_position *coord0, t_bunny_position *coord1);
void	my_fill(t_bunny_pixelarray *pix,
		t_color *color);
void    tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color);
void	go(t_bunny_position *curpos, double angle, t_bunny_position *newpos,
	   int move);
int	cielsol(t_bunny_pixelarray *pix);
