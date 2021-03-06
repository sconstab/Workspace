/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayla <ayla@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 06:50:55 by sconstab          #+#    #+#             */
/*   Updated: 2019/09/17 12:27:04 by ayla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# define MAX_FD 1024

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"

int get_next_line(const int fd, char **line);

#endif
