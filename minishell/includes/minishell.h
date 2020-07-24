#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <signal.h>
# include <stdlib.h>

typedef struct		s_enviro
{
	char			*key;
	char			*value;
	struct s_enviro	*next;
}					t_enviro;

char		*read_line(void);
void		minishell(t_enviro *env);

t_enviro	*dynamic_node(char *stuff, t_enviro *head);
t_enviro	*new_node(const char *stuff);
void		add_node(const char *stuff, t_enviro *head);
char		**split_kv(const char *array);
void		print_list(t_enviro *list);

t_enviro	*run_unsetenv(char *buffer, t_enviro *env);
void		ft_unsetenv(t_enviro *env, char *remove);
t_enviro	*run_setenv(char *buffer, t_enviro *env);
void		ft_setenv(t_enviro *head, char *add);

void		free_list(t_enviro *list);

void		ft_system(t_enviro *env, char *buffer);
void		scan_path(t_enviro *env, char **segments);
void		scan_dir(char *pathway, char **segments, t_enviro *env);
void		execute(char **segment, char *cur_dir, t_enviro *env);

t_enviro	*ft_cd(t_enviro *env, char *buffer);
t_enviro	*cd(t_enviro *env, char **arg);
t_enviro	*to_root(t_enviro *env);
t_enviro	*to_oldpwd(t_enviro *env);
t_enviro	*to_root_path(t_enviro *env, char *path);
t_enviro	*go_back(t_enviro *env, char *path);
char		*back_steps(size_t slash_len, char **path_slashes);
t_enviro	*cd_and_go(t_enviro *env, char *path);

int			check_for_env(t_enviro *env, char *to_find);
char		*get_env_value(t_enviro *env, char *to_get);
int		change_directory(char *path, char *message);
void		move_to_oldpwd(t_enviro *env);
char		*create_env(char *key, char *value);
void        ft_echo(t_enviro *env, char *buffer);

#endif