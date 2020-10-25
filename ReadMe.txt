## Table of contents
* [General info](#general-info)
* [Setup](#setup)
* [Tree structure](#tree-structure)

## General info 
Ce projet d’informatique a consisté à programmer en C les différentes parties qui composent 
la compilation d’un code en grafcet.
Cette méthode d'interpretation de code est utilisé par Java par le biais de sa machine virtuelle.
Vous pouvez avoir davantage de détails sur le fonctionnement de la machine virtuelle de java ici :
https://www.isnbreizh.fr/nsi/activity/interpreter/index.html
			ou
https://soat.developpez.com/tutoriels/java/jvm/decouverte-machine-virtuelle-java/?page=intro-jvm

En l’occurrence ici nous nous intéressons au grafcet d’un coffre-fort qui en fonction des différentes 
combinaisons qui lui sont mises en entrée, passe ou non d’une étape à l’autre dans le grafcet. Ce grafcet 
peut être comparé au code java qui est interprété ensuite par la machine virtuelle java une fois compilé.
Nous aurons donc dans ce fichier grafcet notre propre langage de programmation (avec comme extension du fichier à compiler ".grafcet")
très basique qui sera ensuite interprété par notre machine virtuelle.
C'est pourquoi java fonctionne sur toutes les plateformes. Il suffit seulement que la machine virtuelle soit programmée dans 
un langage compris par l'OS sur laquelle elle tourne.
Ainsi, nous avons dans un premier temps programmé le grafcet de notre coffre-fort en C qui reçoit en entrée par l’intermédiaire 
d’un fichier .h les différentes combinaisons à tester pour déverrouiller celui-ci. 

Le projet a ensuite consisté à réaliser la chaine de compilation d’un fichier grafcet que nous avons créé et qui sera mis en 
entrée du compilateur. Dans un premier temps nous avons donc eu à programmer une machine virtuelle, puis un assembleur 
et enfin un compilateur. Nous avons donc fait les étapes de traitement du fichier grafcet à l’envers.

Référez-vous au "Rapport_projet.pdf" pour comprendre plus en détail le fonctionnement de ce projet.
	
## Setup

Allez dans le répertoire "code_c" :

* Pour compiler le fichier UdpClient.c :
		```
		$ gcc -o client UdpClient.c
		```
* Le compilateur creera un fichier executable client
	- Pour lancer le programme tapez :
		```
		$ ./client 127.0.0.1 8881 events.txt
		```
		!! Avec le fichier events.txt (contenant les pointages du gardien qui fait sa ronde) dans le dossier ou se trouve le programme
		
		!! Pour lancer toutes les requêtes du client rapidement restez appuyer sur la touche ENTER

* Pour compiler le fichier UdpServer.c :
		```
		$ gcc -o server UdpServer.c `mysql_config --cflags --libs`
		```
* Le compilateur creera un fichier executable server
	- Pour lancer le programme tapez :
		```
		$ ./server 8881
		```
