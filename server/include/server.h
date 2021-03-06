/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** server header
*/

#ifndef SERVER_H_
# define SERVER_H_

# define MISS_FLAG	"Missing some flags, please use -help\n"
# define FLAG_SIZE	6
# define FOOD		0
# define LINEMATE	1
# define DERAUMERE	2
# define SIBUR		3
# define MENDIANE	4
# define PHIRAS		5
# define THYSTAME	6

# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <time.h>
# include <stdlib.h>

typedef struct	server_s
{
	struct	protoent	*pe;
	int					fd;
	struct sockaddr_in	s_in;
	struct sockaddr_in	s_in_client;
	socklen_t			s_in_size;
}				server_t;

typedef struct	player_s
{
	int			level;
	int			posx;
	int			posy;
	int 		hp;
	char		*team;
	time_t		action;
}				player_t;

typedef struct		client_s
{
	int				id;
	int				fd;
	char			buf_idx;
	char			*buff[10];
	player_t		player;
	int				ressources[7];
	struct client_s	*next;
	struct client_s	*prev;
}					client_t;

typedef struct		tile_s
{
	int				x;
	int				y;
	int				ressources[7];
	struct tile_s	*up;
	struct tile_s	*down;
	struct tile_s	*right;
	struct tile_s	*left;
	client_t		*clients;
}					tile_t;

typedef	struct	map_s
{
	tile_t		*first;
	tile_t		*last;
	int			width;
	int			height;
}				map_t;

typedef struct	info_s
{
	int			port;
	int			width;
	int			height;
	int			nb_cli;
	int			freq;
	int			client_fd;
	char		**name;
	fd_set		readfds;
	client_t	*clients;
	map_t		map;
	server_t	server;
}				info_t;

typedef struct	flag_s
{
	char	*flag;
	int	(*func)(char **, int, info_t *);
}		flag_t;

int select(int, fd_set *, fd_set *,
			fd_set *, struct timeval *);
int	flag_cmd(char **, int, int *);
int	fill_info(int, char **, info_t *);
int	my_perror(char *, int);
int	flag_p(char **, int, info_t *);
int	flag_x(char **, int, info_t *);
int	flag_y(char **, int, info_t *);
int	flag_n(char **, int, info_t *);
int	flag_c(char **, int, info_t *);
int	flag_f(char **, int, info_t *);

/*
**	handle_clients.c
*/

void	get_client(info_t *info);
int		handle_clients(info_t *info);

/*
**	init_server.c
*/

int		init_serveur(int port, server_t *server);

#endif /* !SERVER_H_ */
