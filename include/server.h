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

typedef struct	info_s
{
	int	port;
	int	width;
	int	height;
	int	nb_cli;
	int	freq;
	char	**name;
}		info_t;

typedef struct	flag_s
{
	char	*flag;
	int	(*func)(char **, int, info_t *);
}		flag_t;

int	flag_cmd(char **, int, int *);
int	fill_info(int, char **, info_t *);
int	my_perror(char *, int);
int	flag_p(char **, int, info_t *);
int	flag_x(char **, int, info_t *);
int	flag_y(char **, int, info_t *);
int	flag_n(char **, int, info_t *);
int	flag_c(char **, int, info_t *);
int	flag_f(char **, int, info_t *);

#endif /* !SERVER_H_ */
