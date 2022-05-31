/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:25:00 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/05/31 16:51:33 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	main(int argc, char **argv, char **env)
{
	printf("salut\n");
	(void)argc;
	(void)argv;
	ft_cd(env);
	printf("%d\n", ft_strlen("bite"));
	return (0);
}
