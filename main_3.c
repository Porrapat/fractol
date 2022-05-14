#include <mlx.h>
#include <stdio.h>

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

int	main(void)
{
	t_vars	vars;
	t_data	img;
	t_data	img2;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	white_screen(vars.mlx,vars.win,640,480);

	img.img = mlx_new_image(vars.mlx, 100, 100);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 10, 10, 0x0000FF00);
	my_mlx_pixel_put(&img, 11, 10, 0x0000FF00);
	my_mlx_pixel_put(&img, 12, 10, 0x0000FF00);
	my_mlx_pixel_put(&img, 13, 10, 0x0000FF00);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 100, 100);
	
	mlx_loop(vars.mlx);
}
