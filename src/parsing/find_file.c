/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyammoun <paolo.yammouni@42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:50:59 by pyammoun          #+#    #+#             */
/*   Updated: 2022/10/28 10:51:22 by pyammoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

char	*getfile1(char *line, int c)
{	
	int		i;
	int		j;

	i = c;
	j = 0;
	while (line[i] == '<' || line[i] == ' ')
		i++;
	while (line[i] && line[i] != ' ' && line[i] != '<')
	{
		i++;
		j++;
	}
	return (ft_substr(line, i - j, j));
}

char	*getfile2(char *line, int c)
{	
	int		i;
	int		j;

	i = c;
	j = 0;
	while (line[i] == '>' || line[i] == ' ')
		i++;
	while (line[i] && line[i] != ' ' && line[i] != '>')
	{
		i++;
		j++;
	}
	return (ft_substr(line, i - j, j));
}

int	find_space(char *line, int c)
{
	int	i;

	i = c;
	while (line[i] && (line[i] == '>' || line[i] == '<' || line[i] == ' '))
		i++;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '<' || line[i] == '>')
			return (i - c);
		i++;
	}	
	return (i - c);
}

int	find_spacu(char *line, int c)
{
	int	i;

	i = c;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '<' || line[i] == '>')
			return (i - c);
		i++;
	}
	return (i - c);
}
