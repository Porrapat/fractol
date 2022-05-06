#include "mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	color_map_1(void *mlx, void *win,int w,int h)
{
	int	x;
	int	y;
	int	color;

	x = w;
	while (x--)
	{
		y = h;
		while (y--)
		{
			color = (x*255)/w+((((w-x)*255)/w)<<16)+(((y*255)/h)<<8);
			mlx_pixel_put(mlx,win,x,y,color);
		}
	}
}

// color_map_1(win1,WIN1_SX,WIN1_SY);

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 600, "Fractol");
	img.img = mlx_new_image(mlx, 600, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

	int x;
	int y;

	x = 1;
	y = x;
	while(x < 600)
	{
		mlx_pixel_put(mlx,mlx_win,x,y,0x00FFFF00);
		x++;
		y = x;
	}
	mlx_loop(mlx);
	
	// mlx_pixel_put(mlx,mlx_win,2,2,0x00FF0000);
	// mlx_pixel_put(mlx,mlx_win,3,3,0x00FF0000);
	// mlx_pixel_put(mlx,mlx_win,4,4,0x00FF0000);
	// mlx_pixel_put(mlx,mlx_win,5,5,0x00FF0000);
	

	// color_map_1(mlx,mlx_win,1024,768);
	// int x;
	// int y;

	// x = 0;
	// y = 0;
	// while(x < 1024)
	// {
	// 	while(y < 768)
	// 	{
	// 		my_mlx_pixel_put(&img, x, y, 0x0000FFFF);
	// 		y++;
	// 	}
	// 	x++;
	// }
	// my_mlx_pixel_put(&img, 5, 5, 0x000000FF);
	// my_mlx_pixel_put(&img, 6, 6, 0x000000FF);
	// my_mlx_pixel_put(&img, 7, 7, 0x000000FF);
	// my_mlx_pixel_put(&img, 8, 8, 0x000000FF);
	// mlx_pixel_put(mlx, mlx_win, 5, 5, 0x00FF0000);
	// mlx_pixel_put(mlx, mlx_win, 6, 6, 0x00FF0000);
	// mlx_pixel_put(mlx, mlx_win, 7, 7, 0x00FF0000);
	// mlx_pixel_put(mlx, mlx_win, 8, 8, 0x00FF0000);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	
}
