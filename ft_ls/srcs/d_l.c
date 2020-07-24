#include "../includes/ft_ls.h"

void	printPermissions(struct stat permissions)
{
	S_ISDIR(permissions.st_mode) ? ft_putchar('d') : ft_putchar('-');
	permissions.st_mode &S_IRUSR ? ft_putchar('r') : ft_putchar('-');
	permissions.st_mode &S_IWUSR ? ft_putchar('w') : ft_putchar('-');
	permissions.st_mode &S_IXUSR ? ft_putchar('x') : ft_putchar('-');
	permissions.st_mode &S_IRGRP ? ft_putchar('r') : ft_putchar('-');
	permissions.st_mode &S_IWGRP ? ft_putchar('w') : ft_putchar('-');
	permissions.st_mode &S_IXGRP ? ft_putchar('x') : ft_putchar('-');
	permissions.st_mode &S_IROTH ? ft_putchar('r') : ft_putchar('-');
	permissions.st_mode &S_IWOTH ? ft_putchar('w') : ft_putchar('-');
	permissions.st_mode &S_IXOTH ? ft_putchar('x') : ft_putchar('-');
	ft_putchar(' ');
}

void	printIDData(struct stat idData)
{
	register struct group	*group;
	register struct passwd	*pwd;

	pwd = getpwuid(idData.st_uid);
	group = getgrgid(idData.st_gid);
	ft_putstr(pwd->pw_name);
	ft_putchar(' ');
	ft_putstr(group->gr_name);
	ft_putchar(' ');
}

void	printTime(struct stat timeData)
{
	char *time;

	time = ctime(&timeData.st_mtime) + 4;
	time[12] = '\0';
	printNString(time, 12);
}

void	userData(char *path)
{
	struct stat buff;
	int nlink;
	int size;

	lstat(path, &buff);
	nlink = buff.st_nlink;
	size = buff.st_size;
	printPermissions(buff);
	ft_putnbr(nlink);
	ft_putchar('\t');
	printIDData(buff);
	if (ft_numlen(buff.st_size) < 2)
	{
		ft_putnbr(size);
		ft_putchar(' ');
		ft_putchar('\t');
	}
	else
	{
		ft_putnbr(size);
		ft_putchar('\t');
	}
	printTime(buff);
}

void	printEverything(t_ls *store, set *flags)
{
	printBlocks(store);
	while (store->next)
	{
		if (!flags->dash_a)
		{
			if (store->fileName[0] == '.')
			{
				store = store->next;
				continue;
			}
		}
		userData(store->fileName);
		ft_putchar(' ');
		ft_putstr(store->fileName);
		ft_putchar('\n');
		store = store->next;
	}
	store->next = NULL;
}

void	printBlocks(t_ls *store)
{
	t_ls		*data = store;
	int			total;
	struct stat	blocks;

	total = 0;
	while (data->next != NULL)
	{
		lstat(data->fileName, &blocks);
		total = total + blocks.st_blocks;
		data = data->next;
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putchar('\n');
}