/*
** my.h for my.h in /home/arzel_p/rendu/gfx_wolf3d/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Sun Dec 13 16:48:02 2015 Paskal Arzel
** Last update Fri Nov 18 17:53:07 2016 Paskal Arzel
*/


#ifndef MY_H_
#define MY_H_

#include "lapin.h"

#define COLOR_SKYNIGHT 0x331100
#define COLOR_SKYDAY 0xFFCC33
#define COLOR_GROUNDNIGHT 0x33CC00
#define COLOR_GROUNDDAY 0x005511
#define X_SPRINT 50
#define Y_SPRINT 750
#define SIZE_SPRINT 30

typedef struct s_list
{
  t_bunny_window	*win;
  bool			*keysym;
  char			*name;
  char			**map;
  float			posx;
  float			posy;
  int			height;
  int			width;
  float			angle;
  float			light;
  float			view;
  float			coke;
  float			sprint;
  int			cdnight;
  const bool		*keys;
  bool			night;
  bool			sprinting;
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

char	**creatmap(t_bunny_ini *ini, int width, int height);
int	desscol(t_list *list, t_bunny_pixelarray *pix, int i, int height);
int	calcdistance(t_list *list, t_pos *scrpos);
void	vol();
int	doit(t_bunny_pixelarray *pix1, t_bunny_pixelarray *pix2, t_list *list);
int	creatlist(t_list *list, t_bunny_window *win, t_bunny_ini *ini);
t_color *makecolor(t_list *list, int height, t_color *color);
int	checkup(char nb, t_bunny_pixelarray *pix,
		t_bunny_position *pos);
int	minisquaredrunk(t_bunny_pixelarray *pix, t_bunny_position *pos);
int	minisquareundrunk(t_bunny_pixelarray *pix, t_bunny_position *pos);
int	goleft(t_list *list, int posx, int posy, float radangle);
int	godown(t_list *list, int posx, int posy, float radangle);
float	colonmakerx(t_list *list, float vx, float vy);
float	colonmakery(t_list *list, float vx, float vy, float df);
int	minisquarelight(t_bunny_pixelarray *pix, t_bunny_position *pos);
int	minimap(t_bunny_pixelarray *pix, t_list *list);
int	my_square(t_bunny_pixelarray *pix, t_bunny_position *pos);
int	whereami(t_bunny_pixelarray *pix, t_list *list);
int	checkview(t_list *list);
int	checkdestruct(t_list *list, float radangle);
int	checkcreate(t_list *list, float radangle);
int	minisquarewall(t_bunny_pixelarray *pix, t_bunny_position *pos);
int	minisquareground(t_bunny_pixelarray *pix, t_bunny_position *pos);
int	minisquaretp(t_bunny_pixelarray *pix, t_bunny_position *pos);
void	controls(t_list	*list);
int	goright(t_list *list, int posx, int posy, float radangle);
int	checktp(t_list *list);
int	goup(t_list *list, int posx, int posy, float radangle);
t_color	*setcolor(int argb1, int argb2, int argb3, int transp);
int	drawit2(t_bunny_pixelarray *pix, t_list *list);
int	updown(t_list *list, float radangle);
int	drawit(t_bunny_pixelarray *pix, t_list *list);
void    tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color);
int	lenscope(char *str);
char	*getscope(char *str);
int	my_getcnbr(const char *str);
void	sprinter(t_bunny_pixelarray *pix, t_list *list);
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
int	getmap(char *str, t_list *list);
double	vecnorm(t_bunny_position *coord0, t_bunny_position *coord1);
void	my_fill(t_bunny_pixelarray *pix,
		t_color *color);
void    tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color);
void	go(t_bunny_position *curpos, double angle, t_bunny_position *newpos,
	   int move);
int	cielsol(t_bunny_pixelarray *pix, t_list *list);

#endif
