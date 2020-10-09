#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "vm_codops.h"

short choix(char A[50]);

short Buffer;
short counter2 = -1;
char BufferIns[10]={""};
long positionOld=0;
long positionOne=0;
short ValeurPositionOld=0;

int main (int argc, char *argv[])
{
		short counter = 0;
		char line[50];
		char* filename;

		char A[10];
		int B = 66666;
		int C = 66666;

		FILE* fp = fopen(argv[1], "r");			//ouverture du fichier donne en argument dans le terminal + test si le pointeur n'est pas null
		if(fp == NULL)
        {
          printf("\n Impossible d'ouvrir le fichier \n");
					exit(1);
      	}

		filename = argv[1];	//chaine qui prend le nom du fichier entre en entre
		for (size_t i = strlen(argv[1]) - 4; i < strlen(argv[1]); i++)		//test si le fichier entre dans le terminal ce termine bien en .asm
		{																																	//On prend la taille totale de la chaine auquelle on fait - 4 pour test les 4 derniers caraectere de la chaine
				//printf("%d\n", filename[i]);
				if (filename[i] == '.')	{}															//puis a chaque boucle on test chaque caractere
				else if (filename[i] == 'a'){}															//on en profite pour les supprimer apres comparaison de maniere a reecrire la place du .asn .bin pour le fichier de sortie
				else if (filename[i] == 's'){}
				else if (filename[i] == 'm'){}
				else
				{
					printf("erreur fichier input check le type de fichier .asm ? \n");	//message erreur et fon du programnme si mauvais fichier
					exit(1);
				}

		}
		filename[strlen(argv[1]) - 4]=0;		//efface caractere a partir de - 4 derniers caractere pour reecrire la suite pour le fichier de fin

		while(fgets(line, sizeof(line), fp) != NULL)		//compte le nombre totale d'instruction dans le fichier
				{
        counter++;
   			}

   	counter -=1;

		strcat(filename,".bin");							//Modifie le nom du fichier pour lui ajouter l'extension .bin
		FILE* fp2 = fopen(filename, "w+");				//Creer et ouvre fichier avec le nom juste creer au dessus

		rewind (fp);															//Reposition le curseur au debut du fichier du pointeur fp
		//positionOne = ftell(fp2);									//recupere la posisition actuelle du curseur dans fichier pointeur fp2

		while(counter != 0)												//Debut de la boucle d'ecriture ce termnine a la fin de la lecture du mombre d'inscrution
    {
				fscanf(fp,"%s %d %d",A, &B, &C);			//recupere les 3 argument de la ligne du fichier, si B et C n'existe pas la fonction de reecrit pas dans les variabler elles sont juste oublie

				if ((strcmp(A, "jp") == 0) || (strcmp(A, "jz") == 0))		//Test si la ligne de commande est un jup pour reecrire le caractere de maniere a le comparer plus tard
				{
					fscanf(fp,"%s",BufferIns);				//recupere la chaine de caractere de la meme ligne aue jp ou jz
					strcat(BufferIns,":");						// modifie la chaine pour avoir ':' a la fin. Comme ecrit dans le fichier .asm pour la positionnement
				}

				if((B == 66666) && (C == 66666))	// comparaison si B et C on etaient modifier de leur valeur de depart ici condition on elles n'on pas etaient changer
				{
					if (strcmp(A, BufferIns) == 0)	//test si A est egale au caractere reecrit precedemment
					{
						positionOne = ftell(fp2);			//recupere la position dans le fichier final
						fseek(fp2, positionOld, SEEK_SET);	//modifie la position a la position ou la commande jp ou jz est
						fprintf(fp2, "\n%d:%d", ValeurPositionOld, counter2 + 1); //ecrit juste en dessous de la fonction si la bonne position et ca valeur de jump
						fseek(fp2, positionOne, SEEK_SET);	//reposition le curseur de la precedente position pour repartir sur l'ecriture
					}
					else												//si la comparaison pour ljp et jz est fausse
					{
						Buffer = choix(A);				//choix de la fonction a ecrite en decimal
						counter2++;
						fprintf(fp2, "            \n%d:%d", counter2, Buffer);		//ecriture dans le ficher valeur de la commande
					}

				if ((strcmp(A, "jp") == 0) || (strcmp(A, "jz") == 0))		//test de jp et jz pour retenir leur position dans lke texte pour y revenir plus tard
				{
					counter2++;
					positionOld = ftell(fp2);	//position dans le fichier pour y revenir plus tard
					ValeurPositionOld = counter2;	//valeur de nombre de position prise a cet instant
				}
			}
			else if((B != 66666) && (C == 66666))		//comparaison si seulement B a etait modifier
			{
				Buffer = choix(A);						//choix de la fonction ecrire
				counter2++;
				fprintf(fp2, "            \n%d:%d", counter2, Buffer);	//ecriture de la fonction commande
				counter2++;
				fprintf(fp2, "\n%d:%d", counter2, B);			//ecriture de la ca valeur
			}
			else if((B != 66666) && (C != 66666))
			{
				Buffer = choix(A);
				counter2++;
				fprintf(fp2, "            \n%d:%d", counter2, Buffer);
				counter2++;
				fprintf(fp2, "\n%d:%d", counter2, B);
				counter2++;
				fprintf(fp2, "\n%d:%d", counter2, C);
			}


			B = 66666;			//remise a 666666 des valeurs de B et de C
			C = 66666;
      counter--;				//counter-- pour tester la commande suivante
    }
		//fin de boucle
		rewind(fp2);			//reposition au debut du fichier fp2
		fprintf(fp2, "%d", counter2 +1);			//ecriture du nombre totale de commande

		fclose(fp);		//fermeture des fichier
		fclose(fp2);
}

short choix(char A[50])		//fonction de selection de la valeur en decimal de chaque commande
{													//on utilise le fichier vm_codops.h comme reference de commande
	short Retour;
	if(strcmp(A, "pushi") == 0)
		{
			Retour = OP_PUSHI;
		}
	else if (strcmp(A, "push") == 0)
		{
			Retour = OP_PUSH;
		}
	else if (strcmp(A, "pop") == 0)
		{
			Retour = OP_POP;
		}
	else if (strcmp(A, "plus") == 0)
		{
			Retour = OP_PLUS;
		}
	else if (strcmp(A, "moins") == 0)
		{
			Retour = OP_MOINS;
		}
	else if (strcmp(A, "mult") == 0)
		{
			Retour = OP_MULT;
		}
	else if (strcmp(A, "div") == 0)
		{
			Retour = OP_DIV;
		}
	else if (strcmp(A, "and") == 0)
		{
			Retour = OP_AND;
		}
	else if (strcmp(A, "or") == 0)
		{
			Retour = OP_OR;
		}
	else if (strcmp(A, "not") == 0)
		{
			Retour = OP_NOT;
		}
	else if (strcmp(A, "eq") == 0)
		{
			Retour = OP_EQ;
		}
	else if (strcmp(A, "gt") == 0)
		{
			Retour = OP_GT;
		}
	else if (strcmp(A, "lt") == 0)
		{
			Retour = OP_LT;
		}
	else if (strcmp(A, "jz") == 0)
		{
			Retour = OP_JZ;
		}
	else if (strcmp(A, "jp") == 0)
		{
			Retour = OP_JP;
		}
	else if (strcmp(A, "halt") == 0)
		{
			Retour = OP_HALT;
		}

	else	printf("Erreur instruction non reconnue :'( \n");

	return Retour;
}
