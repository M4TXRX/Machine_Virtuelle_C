## Table of contents
* [General info](#general-info)
* [Setup](#setup)

## General info 
Ce projet d’informatique a consisté à créer les éléments nécessaire à la compilation et l'interprétation
de notre propre langage de programmation (très basique).
Cette méthode d'interpretation de code est utilisé par Java par le biais de sa machine virtuelle.
Vous pouvez avoir davantage de détails sur le fonctionnement de la machine virtuelle de java ici :

* https://www.isnbreizh.fr/nsi/activity/interpreter/index.html

* https://soat.developpez.com/tutoriels/java/jvm/decouverte-machine-virtuelle-java/?page=intro-jvm

En l’occurrence ici nous nous intéressons au grafcet d’un coffre-fort qui en fonction des différentes 
combinaisons qui lui sont mises en entrée, passe ou non d’une étape à l’autre dans le grafcet.
Nous aurons donc dans notre fichier "safe.grafcet", notre propre langage de programmation (avec comme extension du fichier à compiler ".grafcet")
très basique. Celui-ci sera ensuite interprété par notre machine virtuelle.
Notre code grafcet peut être comparé au code java qui est interprété ensuite par la machine virtuelle java une fois compilé.
C'est pourquoi java fonctionne sur toutes les plateformes. Il suffit seulement que la machine virtuelle soit programmée dans 
un langage compris par l'OS sur laquelle elle tourne.

Ainsi, nous avons dans un premier temps programmé le grafcet de notre coffre-fort en C. Celui-ci reçoit en entrée par l’intermédiaire 
d’un fichier "stimuli.txt" les différentes combinaisons à tester pour déverrouiller celui-ci. Le but est donc d'obtenir le même résultat 
que le code C avec notre machine virtuelle.

Ainsi, notre projet a ensuite consisté à réaliser la chaine de compilation d’un fichier grafcet que nous avons créé et qui sera mis en 
entrée du compilateur. Dans un premier temps nous avons donc eu à programmer une machine virtuelle, puis un assembleur 
et enfin un compilateur. Nous avons donc fait les étapes de traitement du fichier "safe.grafcet" à l’envers.

Référez-vous au "Rapport_projet.pdf" pour comprendre plus en détail le fonctionnement de ce projet.

	
## Setup



##### Allez dans le répertoire "Code C Grafcet_0" :

_Le dossier "Code C Grafcet_0" est seulement le code C du grafcet. C'est ce qui sera attendu en sortie de notre machine virtuelle._
_C'est en quelque sorte une référence pour voir si nous avons réussi à obtenir la même chose que le code en C avec la machine virtuelle._

* Pour compiler le fichier grafcet_safe.c :
		```
		$ gcc -o grafcet_safe grafcet_safe.c
		```
* Le compilateur créera un fichier executable grafcet.
	- Pour lancer le programme et tester les instruction du fichier stimuli.txt, tapez :
		```
		$ ./grafcet_safe stimuli.txt
		```


##### Allez dans le répertoire "Code C Compilateur_1" :
_Le code du compilateur "arbre.c" n'est pas totalement abouti, mais les bases pour comprendre le fonctionnement de cette partie sont bien expliquées. Je vous invite à lire attentivemen la partie "IV) Le programme du compilateur" du rapport "Rapport_projet.pdf" si vous souhaitez le terminer._

* Pour compiler le fichier arbre.c :
		```
		$ gcc -o arbre arbre.c
		```
* Le compilateur créera un fichier executable arbre.
	- Pour lancer le programme tapez :
		```
		$ ./arbre 
		```
_Pour l'instant j'ai écrit directement dans le main la lecture de la première ligne "E0=1 & bp=0 & pot > 128" du fichier "safe.grafcet". Il reste donc à lire chaque ligne de ce fichier et de créer les test condionnels nécessaires afin de créer les noeuds attendus. Il est attendu un fichier "safe.asm" en sortie qui sera ensuite lu par le partie code assembleur présentée ci-dessous._



##### Allez dans le répertoire "Code C Assembleur_2" :

* Pour compiler le fichier ASM.c :
		```
		$ gcc -o main_ASM ASM.c vm_codops.h
		```
* Le compilateur créera un fichier executable ASM, auquel il faut spécifier le fichier qu'il prend en entré "safe.asm".
	- Pour lancer le programme tapez :
		```
		$ ./main_ASM safe.asm
		```	
_Il est attendu un fichier "safe.bin" en sortie qui sera ensuite lu par le partie code machie virtuelle présentée ci-dessous._	

##### Allez dans le répertoire "Code C VM_3" :

* Pour compiler le fichier VM.c :
		```
		$ gcc -o VM VM.c 
		```
* Le compilateur créera un fichier executable VM qui ira lire le fichier "safe.bin".
	- Pour lancer le programme tapez :
		```
		$ ./VM
		```
		

_Les instructions du fichier bytecode sont ensuite interprétées et affichées sur le terminal._
