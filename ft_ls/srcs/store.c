#include "../includes/ft_ls.h"

t_ls *dataTypeName(char *path)
{
	t_ls *data;
	t_ls *head;
	struct stat block;
	DIR *data_stream;
	struct dirent *sd;

	data = (t_ls *)malloc(sizeof(t_ls));
	head = data;
	data_stream = opendir(path);
	while ((sd = readdir(data_stream)))
	{
		data->fileName = sd->d_name;
		data->block = block.st_blocks;
		lstat(data->fileName, &block);
		data->next = (t_ls *)malloc(sizeof(t_ls));
		data = data->next;
	}
	data->next = NULL;
	data = head;
	closedir(data_stream);
	return (data);
}