/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** client header
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# define MISS_FLAG	"Missing some flags, please use -help\n"
# define FLAG_SIZE	3

typedef struct	client_info_s
{
	int	port;
	char	*name;
	char	*machine;
}		client_info_t;

typedef struct	flag_s
{
	char	*flag;
	void	(*func)(char *, client_info_t *);
}		flag_t;

int		fill_info(int, char **, client_info_t *);
int		my_perror(std::string, int);
void	flag_p(char *, client_info_t *);
void	flag_n(char *, client_info_t *);
void	flag_h(char *, client_info_t *);

#endif /* !CLIENT_H_ */
