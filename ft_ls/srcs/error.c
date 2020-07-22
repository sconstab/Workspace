/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconstab <sconstab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:33:32 by sconstab          #+#    #+#             */
/*   Updated: 2019/09/07 20:36:34 by sconstab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	invalidFileOrDir(char *flagString)
{
	ft_putstr("ft_ls: ");
	ft_putstr(flagString);
	ft_putendl(": No such file or directory");
	exit(1);
}

void	illegalOption(char flag)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(flag);
	ft_putchar('\n');
	ft_putendl("usage: ft_ls [-Ralrt] [file ...]");
	exit(1);
}