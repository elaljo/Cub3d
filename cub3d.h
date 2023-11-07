/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:19:14 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/07 01:07:09 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define MOVE_FORWARD 13
# define MOVE_BACKWARD 1
# define MOVE_LEFT 0
# define MOVE_RIGHT 2
# define ESC 53

# define WIDTH		1400
# define HEIGHT		900
# define TITLE		"cub3D"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_map{
	char	**str;
	char	**main;
	int		x;
	int		y;
	int		tex_width;
	int		tex_height;
	void	*ptr_1_img;
	void	*ptr_0_img;
	void	*ptr_p_img;
}				t_map;

typedef struct e_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_data {
	t_image			image;
	t_map				map;
	void			*mlx_ptr;
	void			*win_ptr;
	double			scale;
	double			zoom;
	double			mouse_x;
	double			mouse_y;
}				t_data;

void	ft_init_data(t_data *data);
void	ft_init_image(t_data *data);


//				BONJAH
// 		>---------------------<
int			close_window(t_data *data);
int			keygenerator(int key_code, t_data *data);
//parsing
void		print_and_exit_param(void);
void		open_fd_check(int *fd, char *file);
void		read_map(int fd, t_data *data);
void		find_cor_player(t_data *data);
//	errors
void		print_and_exit(char *freestr);
//-> gnl
char		*get_next_line(int fd);
char		*ft_read(char *all, int fd);
char		*cut(char *str);
char		*copy_to_xyata(char *str);
char		*ftt_strcpy(char *dst, char *src);
char		*ftt_strjoin(char *s1, char *s2);
char		*ftt_strchr(const char *s, int c);
size_t	ftt_strlen(const char *s);
//-> split
char	**ftt_split(char const *s, char c);
int		count_words(char const *s, char delimiter);
int		count_chars(char const *s, char delimiter, int lens);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
