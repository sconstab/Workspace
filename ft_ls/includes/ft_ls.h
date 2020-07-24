#ifndef FT_LS_H
# define FT_LS_H

# include "libc.h"
# include <sys/dir.h>
# include "../libft/includes/libft.h"
# include <sys/stat.h>
# include <uuid/uuid.h>
# include <pwd.h>
# include <grp.h>

# define LIST DIR

typedef struct	s_ls
{
    char		*fileName;
	int			block;
	struct s_ls	*next;
}				t_ls;

typedef struct	flag
{
	int			a;
	int			r;
	int			t;
	int			l;
	int			R;
	int			Flag;
	int			Other;
	int			dir_num;
}				set;

void			printPermissions(struct stat permissions);
void			printIDData(struct stat idData);
void			printTime(struct stat timeData);
void			userData(char *path);
void			printEverything(t_ls *store, set *flags);
void			printBlocks(t_ls *store);
void			invalidFileOrDir(char *flagString);
void			illegalOption(char flag);
void			exists(char *flag, t_ls *data, set *flags);
void			exists_1(char *flag, t_ls *data);
void			exists_2(char *flag, t_ls *data);
void			exists_3(char *flag, t_ls *data, set *flags);
int				doubleDash(int ac, char *flag);
void			flagCheck(int ac, char **av, set *flags, t_ls *data);
void			flagCheck1(char **av, int avi, set *flags, t_ls *data);
void			printAll(t_ls *lst);
void			printBase(t_ls *a);
void			printNString(char *str, int len);
void			dash_R(char *str, int indent);
void			printBasic(t_ls *data);
void			multipleFlags(t_ls *data, set *flags, char *flagString);
void			sortAscii(t_ls *tmp);
void			sortRevList(t_ls *tmp);
int				timeCompare(char *s1, char *s2);
void			sortTime(t_ls *tmp, set *flags);
t_ls			*dataTypeName(char *path);
set				*setFlags(void);
void			freeFlags(set *flags);
void			initMain(int ac, char **av, int avi, t_ls *data, set *flags);
void			listDel(t_ls *data);
int				findDash(char *flag, set *flags);

#endif