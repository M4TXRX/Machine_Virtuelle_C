#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define NBvaleur 122


int main(int argc, char const *argv[])
{

   FILE* fichier=fopen("stimuli.txt","r");		 //ouverture du fichier stimuli.txt

   int ETAT=0, val[2];						 //on démarre de base à l'état 0 
   int cpt=0;						 //on démarre le compteur cpt à 0 qui compte chaque ligne du stimuli.txt parcourues
   while(val[0] != (-1))			 //tant qu'on arrive pas à la valeur du bouton = '-1'
   {
    fscanf(fichier,"%d  %d", &val[0], &val[1]);  //lecture des valeurs du fichier stimuli.txt et stockage	
    cpt++;										 //on incrémente cpt qui représente le numéro de la ligne lue
	
    if ((ETAT==0) && (val[0]==0) && (val[1]>128))//on passe à  l'état 1 si on est dans l'état 0, la valeur du bouton vaut 0
												 //et la valeur du potentiomètre lue > 128
    {
      ETAT=1;
	  printf("\nEtat 1 passe à la valeur 1,");
      printf("Ligne du front descendant = %d,",cpt);
      printf("Led rouge = 1, Led verte = 0 \n");

    }

    if ((ETAT==1) && (val[0]==0) && (val[1]<128))//on passe à  l'état 2 si on est dans l'état 1, la valeur du bouton vaut 0
												 //et la valeur du potentiomètre lue < 128
    {
      ETAT=2;
	  printf("\nEtat 2 passe à la valeur 1,");
      printf("Ligne du front descendant = %d,",cpt);
      printf("Led rouge = 1, Led verte = 0 \n");
    }
    if ((ETAT==2) && (val[0]==0) && (val[1]>128))//on passe à  l'état 3 si on est dans l'état 2, la valeur du bouton vaut 0
												 //et la valeur du potentiomètre lue > 128
    {
      ETAT=3;
	  printf("\nEtat 3 passe à la valeur 1,");
      printf("Ligne du front descendant = %d,",cpt);
      printf("Led rouge = 0, Led verte = 1 \n");
	  printf("\nBravo vous avez trouvé le bon mot de passe !\n\n");
    }

    if ((ETAT==3) && (val[0]==0) && (val[1]<128))//on passe à  l'état 3 si on est dans l'état 2, la valeur du bouton vaut 0
												 //et la valeur du potentiomètre lue > 128
    {
      ETAT=0;
	  printf("\nEtat 0 passe à la valeur 1,");
      printf("Ligne du front descendant = %d,",cpt);
      printf("Led rouge = 1, Led verte = 0 \n\n");
    }
   }


  return 0;
}
