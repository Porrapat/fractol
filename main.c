#include <mlx.h>
#include <stdio.h>
#include <math.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_point_double
{
	double	x;
	double	y;
}				t_point_double;

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

int	white_screen(void *mlx, void *win, int w, int h)
{
	int	x;
	int	y;

	x = w;
	while (x--)
	{
		y = h;
		while (y--)
		{
			mlx_pixel_put(mlx,win,x,y,0xFFFFFF);
		}
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	white_screen_image(t_data *data, int w, int h)
{
	int	x;
	int	y;

	x = w;
	while (x--)
	{
		y = h;
		while (y--)
		{
			my_mlx_pixel_put(data,x,y,0xFFFFFF);
		}
	}
}



void draw_line_image(t_data *data, t_point p1, t_point p2, int color)
{
	double deltaX = p2.x - p1.x; // 10
	double deltaY = p2.y - p1.y; // 0

	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));

	deltaX /= pixels; // 1
	deltaY /= pixels; // 0

	double pixelX = p1.x;
	double pixelY = p1.y;
	while (pixels)
	{
		my_mlx_pixel_put(data, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
}

void draw_reg_image(t_data *data, t_point p1, t_point p2, int color)
{
	draw_line_image(data, (t_point){p1.x, p1.y}, (t_point){p1.x, p2.y}, color);
	draw_line_image(data, (t_point){p1.x, p1.y}, (t_point){p2.x, p1.y}, color);
	draw_line_image(data, (t_point){p1.x, p2.y}, (t_point){p2.x, p2.y}, color);
	draw_line_image(data, (t_point){p2.x, p1.y}, (t_point){p2.x, p2.y}, color);
}

int	main(void)
{
	t_vars	vars;
	t_data	img;
	t_point p1;
	t_point p2;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");

	img.img = mlx_new_image(vars.mlx, 640, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	white_screen_image(&img, 640, 480);

	// p1.x = 10;
	// p1.y = 10;
	// p2.x = 200;
	// p2.y = 300;
	// draw_line_image(&img, (t_point){10, 10}, p2, 0xFF0000);
	// draw_line_image(&img, (t_point){40, 100}, p2, 0x990000);
	// draw_reg_image(&img, p1, p2);

	draw_reg_image(&img, (t_point){10, 10}, (t_point){40, 100}, 0xDD0000);
	draw_reg_image(&img, (t_point){50, 50}, (t_point){100, 100}, 0xDD0000);

	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);

	mlx_loop(vars.mlx);
}
