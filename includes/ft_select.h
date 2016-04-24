/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:02:48 by rle-mino          #+#    #+#             */
/*   Updated: 2016/04/24 12:54:42 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "libft.h"
# include <fcntl.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <signal.h>

# define DEBUG fpf("\x1B[36m%d - %s - %s\n\x1B[0m",__LINE__, __FILE__, __func__)

enum
{
	NO_ARG,
	MALLER,
	ENV_ERROR,
	W_RET,
	W_NORET
};

typedef struct		s_args
{
	char			*name;
	struct s_args	*next;
	struct s_args	*prev;
	int				selected;
	int				x;
	int				y;
	int				is_first;
}					t_arg;

typedef struct		s_select
{
	struct s_args	*first;
	size_t			max_len;
	char			*term_name;
	struct winsize	*io;
	int				nb_arg;
	struct s_args	*tmp;
	int				space;
}					t_select;

int					sel_error(int info);
int					init_env(t_select *sel);
void				ft_select(t_select *sel, int *pos);
void				argv_to_list(char **argv, t_select *sel);
void				display_arg(t_arg *arg, t_select *sel);
int					putint(int c);
void				cursor_move(int *pos, t_select *sel);
void				move_right(int *pos, t_select *sel);
void				move_left(int *pos, t_select *sel);
void				move_up(int *pos, t_select *sel);
void				move_down(int *pos, t_select *sel);
int					env_sw(void);
t_arg				*get_first(t_arg *args, int nb_arg);
void				res_and_quit(int sig);
void				suspend(int sig);
void				restart(int sig);
void				restart_display(int sig);
int					get_fd(int fd);
t_select			*get_sel(t_select *sel);
t_arg				*get_list(t_arg *l);
int					is_del_or_back(char *buffer);
void				delete_arg(t_select *sel, int *pos);
void				select_arg(t_select *sel, int *pos);
void				sel_buf(char *buffer, int *pos, t_select *sel);
void				end_select(t_select *sel, int info);

#endif
