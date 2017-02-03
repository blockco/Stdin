/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 13:13:39 by rpassafa          #+#    #+#             */
/*   Updated: 2017/02/02 23:47:09 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/libft.h"
#include <stdio.h>

char	*read_tmp(const int fd, char **buf)
{
	char	*str1;
	int		bytes_read;
	int		total;

	str1 = ft_strnew(BUFF_SIZE);
	bytes_read = 0;
	total = 0;
	while (ft_strchr(*buf, '\n') == NULL)
	{
		bzero(str1, 2);
		//str1 = NULL;
		str1 = ft_strnew(BUFF_SIZE);
		bytes_read = read(fd, str1, BUFF_SIZE);
		total += bytes_read;
		if (bytes_read == 1)
			*buf = ft_strjoin(*buf,(const char*)str1);
	}
	free (str1);
	return (*buf);
}

int main()
{
	char *str;
	while(1)
	{
		str = read_tmp(0, &str);
		printf("%s", str);
		ft_bzero(str, ft_strlen(str));
	}
	return 0;
}
