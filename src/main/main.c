/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:25:00 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/06/02 14:26:41 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	main(int argc, char **argv, char **env)
{
	//	1 -> lancer readline
	//	2 -> récupérer le  inpput de readline (attention il faut le free après)
	//	3 -> gérer les expansion de variables d'environement "$""
	//	4 -> Séparer l'input par espace et guillemet (simple et double) et en faire un tableau
	//	5 -> lancer la fonction expander sur chaque élément pour gérer les "$"
	//	6 -> séparer les "<" ">" et "|" mais seulement si ils sont en dehors de quote (simple ou double)
	//	7 -> refaire un tableau avec tout bien séparé
	//	8 -> créer une liste chaîné ou chaque noeud contiendra : fd_infile, fd_outfile, full_path (chemin absolu de la commande), full_cmd (une string contenant la commande avec toutes ces optioons/parametre)
	//	9 -> envoyer la liste pour l'execution
	//	10 -> voir si la commande est un builtin ou non
	//	11 -> if builtin : trouver lequel et lancer la fonction apparenté
	//	12 -> if not builtin : lancer pipex_amélioré

	// changement à apporter à pipex : 
	//	Ne pas devoir avoir obligatoirement d'infile
	//	Gérer les redirections de stdin et stdout à n'importe quel moment
	//	Pouvoir ne recevoir qu'une seule commande
	//	changer le main pour qu'ils recoivent les valeurs de la liste chaîné
	

	printf("salut\n");
	(void)argc;
	(void)argv;
	(void)env;
	ft_cd("src");
	printf("%d\n", ft_strlen("bite"));
	return (0);
}
