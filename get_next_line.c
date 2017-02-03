/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 13:13:39 by rpassafa          #+#    #+#             */
/*   Updated: 2017/02/03 15:32:20 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/libft.h"
#include "vector.h"
#include <stdio.h>

char	*read_tmp()
{
	char	*str1;
	int		bytes_read;
	char	*ret;
	t_vector *vect;
	vect = vect_new(10, sizeof(char*));

	str1 = ft_strnew(BUFF_SIZE);
	bytes_read = 0;
	ft_putstr("$> ");
	while (ft_strchr(ret, '\n') == NULL)
	{
		vect_insert(vect, vect->size, &str1);
		bzero(str1, 2);
		str1 = ft_strnew(BUFF_SIZE);
		if (bytes_read > 0)
			vect_insert(vect, vect->size, &ret);
		bytes_read += read(0, str1, BUFF_SIZE);
		if (bytes_read > 1)
			ret = ft_strjoin(ret,(const char*)str1);
		else
			ret = ft_strdup(str1);
	}
	col_vect(vect);
	return (ret);
}

int main(int argc, char **argv, char** envp)
{
	char *str;
	char** env;

	if (argc < 0)
		;
	if (argv)
		;
	env = envp;
	// while (*env != 0)
	// {
	// 	char* thisEnv = *env;
	// 	printf("%s\n", thisEnv);
	// 	env++;
	// }

	while(1)
	{
		str = read_tmp();
		printf("%s", str);
		ft_bzero(str, ft_strlen(str));
	}
	return 0;

	// t_vector *vect;
	// vect = vect_new(10, sizeof(char *));
	// char *str1 = "THIS IS A STRING";
	// char *str2 = "ABCDEFGHIJ";
	// char *str3 = "012345678";
	//
	// vect_insert(vect, vect->size, &str1);
	// vect_insert(vect, vect->size, &str2);
	// vect_insert(vect, vect->size, &str3);
	// printf("%s\n", *(char **)vectspot(0, vect));
	// printf("%s\n", *(char **)vectspot(1, vect));
	// printf("%s\n", *(char **)vectspot(2, vect));
}
