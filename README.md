# 42_minishell

Marche à suivre pour faire minishell

  // 0 -> installer la librairie de readline avec homebrew

  //	1 -> lancer readline
	//	2 -> récupérer le  inpput de readline (attention il faut le free après)
	//	3 -> gérer les expansion de variables d'environement "$""
	//	4 -> Séparer l'input par espace et guillemet (simple et double) et en faire un tableau
	//	5 -> lancer la fonction expander sur chaque élément pour gérer les "$"
	//	6 -> séparer les "<" ">" et "|" mais seulement s'ils sont en dehors de quote (simple ou double)
	//	7 -> refaire un tableau avec tout bien séparé
	//	8 -> créer une liste chaînée ou chaque noeud contiendra : fd_infile, fd_outfile, full_path (chemin absolu de la commande), full_cmd (une string contenant la commande avec toutes ces options/parametre)
	//	9 -> envoyer la liste pour l'execution
	//	10 -> lancer pipex améliorer
	//	11 -> créer le nombre de pipe désiré
	//	12 -> fork pour la première commande
	//	13 -> lancer le child_process et checker si la commande est un builtin ou non
	//	14 -> if builtin : checker lequel s'est et lancer la fonction apparenté (attention de fermer et gérer les fd des autres pipes)
	//	15 -> if not builtin : fermer les fd non utilisés,
								//if infile : l'ouvrir et vérifier son ouverture, dupliquer son fd
								// if pipe : rediriger STDOUT dans le pipe
								// fermer tous les fd
								//executer la commande avec execve
	//	16 -> récuper le status du child_process
	//	17 -> si problème quitter proprement le programme avec message d'erreur dans stderr
	//	18 -> si pas de problème : continuer jusqu'a la fin des commandes
	// 
								

	// changement à apporter à pipex de base: 
	//	Ne pas devoir avoir obligatoirement d'infile
	//	Gérer les redirections de stdin et stdout à n'importe quel moment
	//	Pouvoir ne recevoir qu'une seule commande
	//	changer le main pour qu'ils recoivent les valeurs de la liste chaîné

	// information supplémentaire nécessaire à mon pipex :
	// le nombre de pipe à créer
	// le nombre de commmande total (enfin je suis pas sur que ca soit la solution mais il faut que j'ai accès à l'index de la dernière commande)
