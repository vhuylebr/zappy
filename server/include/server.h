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
# define GUI_CMD_SIZE	2
# define PROB			7
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <time.h>
# include <stdbool.h>

typedef struct info_s info_t;

typedef enum {
	NONE,
	UP,
	RIGHT,
	DOWN,
	LEFT
} orientation;

typedef	struct	coord_s {
	int	x;
	int	y;
}		coord_t;

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
}				player_t;

typedef struct		client_s
{
	int				id;
	int				fd;
	char			buf_idx;
	char			*buff[11];
	player_t		player;
	bool			is_gui;
	int				ressources[7];
	bool			is_connected;
	bool			is_set;
	bool			is_log;
	bool			is_admin;
	time_t			time;
	time_t			food_time;
	void			(*func)(info_t *, struct client_s *, char **);
	int				wait_time;
	char			*user_name;
	struct client_s	*next;
	struct client_s	*prev;
}					client_t;

typedef	struct				client_list_s
{
	client_t				*client;
	struct client_list_s	*next;
}							client_list_t;


typedef	struct				gui_list_s
{
	client_t				*gui;
	struct gui_list_s		*next;
}							gui_list_t;

typedef struct		tile_s
{
	int				x;
	int				y;
	int				ressources[7];
	struct tile_s	*up;
	struct tile_s	*down;
	struct tile_s	*right;
	struct tile_s	*left;
	client_list_t	*clients_list;
}					tile_t;

typedef struct	team_s
{
	int		nb_cli;
	char	*name;
}				team_t;

struct	info_s
{
	int			is_end;
	int			port;
	int			width;
	int			height;
	int			id;
	int			nb_cli;
	int			freq;
	team_t		**team;
	fd_set		readfds;
	client_t	*clients;
	gui_list_t	*gui;
	tile_t		*map;
	server_t	server;
	time_t		ressource_spawn;
};

typedef struct	flag_s
{
	char	*flag;
	int	(*func)(char **, int, info_t *);
}				flag_t;

typedef struct	cmd_s
{
	char	*cmd;
	void	(*func)(info_t *, client_t *, char **);
	int		freq;
}				cmd_t;

typedef struct 	incantation_s
{
	int	level;
	int	nb_player;
	int	linemate;
	int	deraumere;
	int	sibur;
	int	mendiane;
	int	phiras;
	int	thystame;
}				incantation_t;

team_t	*get_team(team_t **, char *);
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

void	check_function(info_t *, client_t *);

/*
** tools.c
*/

void	remove_buff(char *buff[10]);
int	get_max_fd(client_t *clients);

/*
** handle_client_list.c
*/

void	add_client(info_t *, int);
void	del_elem_from_list(info_t *, client_t *);
void	init_client(info_t *,client_t *);

/*
** init_map.c
*/

void	init_map(info_t *info);
int		display_inventory_tile(tile_t *tile, int fd);

/*
** handle_team.c
*/

void	team_name(info_t *, client_t *, char *);

/*
** handle_clients_tile.c
*/

int		get_client_tile_size(tile_t *);
void 	add_client_to_tile(tile_t *tile, client_t *client);
void	del_client_from_tile(tile_t *tile, client_t *client);
void	ressource_spawn(info_t *);

/*
** handle_login.c
*/

void login(info_t *, client_t *, char **);
void pass(info_t *, client_t *, char **);

/*
** handle_gui_list.c
*/

void	add_client_gui(info_t *, client_t *);
void	remove_client_gui(info_t *, client_t *);

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
