*******************************************************************************************************
			      Projet réalisé dans le cadre de mes études
*******************************************************************************************************
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

/!\Le dossier "Code C Grafcet_0" est seulement le code C du grafcet qui est attendu en sortie de notre machine virtuelle./!\
/!\C'est en quelque sorte une référence pour voir si nous avons réussi à obtenir la même chose que le code en C avec la machine virtuelle./!\
*******************************************************************************************************
*******************************************************************************************************
