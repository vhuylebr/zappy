/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** server header
*/

#ifndef SERVER_H_
# define SERVER_H_

# define MISS_FLAG		"Missing some flags, please use -help\n"
# define FLAG_SIZE		6
# define FOOD 			0
# define LINEMATE 		1
# define DERAUMERE		2
# define SIBUR			3
# define MENDIANE		4
# define PHIRAS			5
# define THYSTAME		6
# define IA_CMD_SIZE	12
# define GUI_CMD_SIZE	9

# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <time.h>
# include <stdbool.h>

typedef enum {
	NONE,
	UP,
	RIGHT,
	DOWN,
	LEFT
} orientation;

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
	orientation	orientation;
	time_t		action;
	time_t		next_eat;
}				player_t;

typedef struct		client_s
{
	int				id;
	int				fd;
	char			buf_idx;
	char			*buff[10];
	player_t		player;
	bool			is_gui;
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
}					tile_t;

typedef struct	info_s
{
	int			port;
	int			width;
	int			height;
	int			id;
	int			nb_cli;
	int			freq;
	char		**name;
	fd_set		readfds;
	client_t	*clients;
	tile_t		*map;
	server_t	server;
}				info_t;

typedef struct	flag_s
{
	char	*flag;
	int	(*func)(char **, int, info_t *);
}				flag_t;

typedef struct	cmd_s
{
	char	*cmd;
	void	(*func)(info_t *, client_t *, char **);
}				cmd_t;

int		get_cli_num(client_t *, char *, int);
tile_t	*get_tile(int, int, info_t *);
void	print_ressources(int[7], int);
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

/*
** word_tab.c
*/

char	**my_str_to_wordtab(char *str, char c);
void	free_tab(char **tab);

/*
** handle_commands.c
*/

int		check_function(info_t *info, client_t *client, char **cmds);

/*
** tools.c
*/

int	get_max_fd(client_t *clients);

/*
** handle_client_list.c
*/

void add_client(info_t *info, int fd);
void	del_elem_from_list(info_t *info, client_t *client);

/*
** init_map.c
*/

void	init_map(info_t *info);

/*
** IA cmd
*/

void	forward(info_t *, client_t *, char **);
void	right(info_t *, client_t *, char **);
void	left(info_t *, client_t *, char **);
void	look(info_t *, client_t *, char **);
void	inventory(info_t *, client_t *, char **);
void	broadcast(info_t *, client_t *, char **);
void	connect_nbr(info_t *, client_t *, char **);
void	fork_player(info_t *, client_t *, char **);
void	eject(info_t *, client_t *, char **);
void	take(info_t *, client_t *, char **);
void	set(info_t *, client_t *, char **);
void	incantation(info_t *, client_t *, char **);

/*
** GUI cmd
*/

void	msz(info_t *, client_t *, char **);
void	bct(info_t *, client_t *, char **);
void 	mct(info_t *, client_t *, char **);
void	tna(info_t *, client_t *, char **);
void	ppo(info_t *, client_t *, char **);
void	plv(info_t *, client_t *, char **);
void	pin(info_t *, client_t *, char **);
void	sgt(info_t *, client_t *, char **);
void	sst(info_t *, client_t *, char **);

#endif /* !SERVER_H_ */
