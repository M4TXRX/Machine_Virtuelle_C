//By Esteban and Padrao EI2I3
#include <stdio.h>
#include <stdlib.h>
#include "vm_codops.h" 

void run_VM(FILE *fichier, int pile[], int code[]); 
void affiche_etat(int MTR[][3], int *L_R, int *L_V, int i);

int main(int argc, char **argv)
{
	
	int NombreLigne, ligne;
	
	FILE* fin=fopen("safe.bin","r");//ouvre "safe.bin" en mode lecture dans la variable fin de type FILE*
	
	if (fin==NULL)//si le fichier "safe.bin" n'existe pas, alors on affiche une erreur
	{
		printf("Erreur ouverture fichier %s\n",argv[1]);
		exit(1);
	}
	
	fscanf(fin,"%d", &NombreLigne);//on lit la première ligne du fichier qui correspond aux nombres de lignes
	
	/*tableau pile qui stockera les valeurs dans la pile et tableau code qui stockera la valeur des instructions*/
	int pile[NombreLigne], code[NombreLigne];
	
	for (int i = 0; i < NombreLigne; ++i)//on remplit avec cette boucle le tableau code qui contient les instructions
	{
		fscanf(fin,"%d:%d", &ligne, &code[i]);
	}
	
	FILE* fichier=fopen("stimuli.txt","r");//on ouvre le fichier stimuli.txt
	
	run_VM(fichier, pile, code);
	
	/*on ferme les fichiers ouverts*/
	fclose(fichier);
	fclose(fin);
	return 0;
}
	
	
void run_VM(FILE *fichier, int pile[], int code[])//fonction qui va lire chaque ligne du stimuli.txt et lire toutes les instructions du safe.bin avec 
																   //les valeurs du BP et du potentiomètre
{	
	int MTR[8][3]; //tableau contenant les valeur des états, du bouton poussoir
				   //du potentiomètre et des LEDs
			   
	MTR[0][0]=1;   //on démarre avec l'état 0 (E0) à la valeur 1
	MTR[1][0]=0;   //état 1 (E1) à la valeur 0
	MTR[2][0]=0;   //état 2 (E2) à la valeur 0
	MTR[3][0]=0;   //état 3 (E3) à la valeur 0
	MTR[6][0]=1;   //LED rouge à la valeur 1 (allumée)
	MTR[7][0]=0;   //LED verte à la valeur 0 (éteinte)
	int *L_R= &(MTR[6][0]);//on déclare L_R (LED rouge) qui pointe à l'adresse de "MTR[6][0]"
	int *L_V= &(MTR[7][0]);//on déclare L_V(LED verte) qui pointe à l'adresse de "MTR[7][0]"
	
	
	int val[2];//tableau qui va contenir les valeur de BP et du potentiomètre
	int old_button=0;//on initialise la valeur de l'appui précédent à 0
	
	int a,b,pc,sp;	

for(int i=0; i<60; i++)
 {
	  fscanf(fichier,"%d  %d", &val[0], &val[1]);//on lit les valeur du BP et potentiomètre 

	  MTR[4][0]=val[0];//on stocke la valeur du BP dans le tableau MTR
	  MTR[5][0]=val[1];//on stocke la valeur du potentiomètre dans MTR
	  
	  pc=0;//on met la valeur de pc à 0 à chaque saut de ligne du "stimuli.txt" 
	
		
     if ((old_button==1) && (MTR[4][0] == 0))//si front descendant détecté (soit un appui sur BP) on le passe à 1 dans MTR
		  {
            MTR[4][2]=1;
            MTR[4][1]=0;
          }
          else if ((old_button==0) && (MTR[4][0] == 1))//si front montant détecté on le passe à 1 dans MTR
		  {
			MTR[4][2]=0;
            MTR[4][1]=1;
          }
		if (old_button==1 && MTR[4][0]==1)//si même état du BP avant et après alors les valeurs de front ne changent pas
			{
			  MTR[4][2]=0;
			  MTR[4][1]=0;
			}
		 if (old_button==0 && MTR[4][0]==0)//si même état du BP avant et après alors les valeurs de front ne changent pas
			{
			  MTR[4][2]=0;
			  MTR[4][1]=0;
			}
	  old_button =  MTR[4][0];//on stocke la veleur du BP après comparaison dans la variable "old_button"
		   
      sp=0;//on remet la valeur de la pile à 0 à chaque saut de ligne du "stimuli.txt" 
	 
	while(code[pc]!=OP_HALT) // tant que l'on n'arrive pas à l'instruction de stop
	{

		switch(code[pc])
		{	
			
			// mettre une valeur immédiate dans la pile
			case OP_PUSHI :
			    sp++; 
				pile[sp]=code[pc+1];
				pc+=2;
			break;
			
			// va prendre une valeur dans le MTR et la met dans la pile
			case OP_PUSH :
			    sp++;
				pile[sp]= MTR[ code [pc+1] ][ code[ pc+2] ]; 
				pc+=3;
			break;
			
			// Enlève une valeur de la pile
			case OP_POP :
				MTR[code[pc+1]][0]=pile[sp];
				pc=pc+2;
			break;
			
			// fait une addition
			case OP_PLUS :
				a=pile[sp];
				b=pile[sp-1];
				pile[sp]=a+b;
				pc++;
			break;

			// fait une soustraction
			case OP_MOINS :
				a=pile[sp];
				b=pile[sp-1];
				pile[sp]=a-b;
				pc++;
			break;

			// fait une multiplication
			case OP_MULT :
				a=pile[sp];
				b=pile[sp-1];
				pile[sp]=a*b;
				pc++;
			break;

			// fait une division
			case OP_DIV :
				a=pile[sp];
				b=pile[sp-1];
				pile[sp]=a/b; 
				pc++;
			break;

			// compare bit à bit les valeurs avec un ET
			case OP_AND :
				a=pile[sp];
				b=pile[sp-1];
          		pile[sp] = a&b; 
            	pc++;
			break;

			// compare bit à bit les valeurs avec un OU
			case OP_OR :
				a=pile[sp];
				b=pile[sp-1];
          		pile[sp] = a|b; 
            	pc++;
			break;
			
			//NOT logique sur une valeur de la pile
			case OP_NOT:
				pile[sp]= ~ pile[sp]; 
				pc++ ; 
		    break;

			// test l'égalité entre deux termes
			case OP_EQ :
				a=pile[sp];
               	b=pile[sp-1];
                sp++;
                if(b == a)
                pile[sp]=1;
                else
                pile[sp]=0;
                pc++;
			break;

			// compare deux valeurs entre elles avec >
			case OP_GT :
		    	a=pile[sp];//valeur potentiomètre
            	b=pile[sp-1];//valeur 128 de référence
			
            	if(a > b)//si val de pot sup à val ref
				{
					pile[sp]=1;                         
					pile[sp-1]=pile[sp-2];
				}
            	
				else//sinon
				{
					pile[sp]=0;
					pile[sp-1]=pile[sp-2];
				}
           		pc++;
			break;

			// compare deux valeurs entre elles avec <
			case OP_LT :
				a=pile[sp];//valeur potentiomètre
				b=pile[sp-1];//valeur 128 de référence
				
				if(a < b)//si val de pot inf à val ref
				{
					pile[sp]=1;                      
					pile[sp-1]=pile[sp-2];
				}
				else//sinon
				{
					pile[sp]=0;
					pile[sp-1]=pile[sp-2];
				}
				pc++;
			break;

			// saut JZ
			case OP_JZ :
			
				if(pile[sp]==1 )//si toutes les conditions pour changer d'état sont réspéctés pile[sp]=1
				{
					pc=pc+2;//on va vers l'intruction après JZ (ces instructions entrainent le changement d'état)
				}
				else
				{
					pc++;
					pc = code[pc];// on saute directement à l'autre bloc d'instruction qui va tester si on est dans un l'état En
								  //on saute ici 8 instructions d'un coup
				}		
			break;

			// saut Jump
			case OP_JP :
				if(pile[sp]==0 )//si toutes les conditions pour changer d'état sont réspéctés pile[sp]=0
				{
					pc=pc+2;//on va vers l'intruction après JZ (ces instructions entrainent le changement d'état)
				}
				else
				{
					pc++;
					pc = code[pc];// on saute directement à l'autre bloc d'instruction qui va tester si on est dans un l'état En
								  //on saute ici 8 instructions d'un coup
				}		
			break;

			// si aucun des cas on affiche un message d'erreur
			default:
			printf("erreur\n");
			break;
		}
		
	  }
	  affiche_etat(MTR, L_R, L_V,i);
 }
}
	   

	   
void affiche_etat(int MTR[][3], int *L_R, int *L_V, int i)//fonction qui affiche les changements d'étapes
{
		if (MTR[1][0]==1 && MTR[4][2]==1)//si l'état 1 dans le tableau passe à la valeur 1 et que front descendant détecté
		{
			printf("Etat 1 passe à la valeur %d\n", MTR[1][0]);
			printf("Ligne du front descendant = %d, \n",i+1);
            printf("Led rouge = %d, Led verte = %d \n\n",*L_R,*L_V);	
		}
		
		if (MTR[2][0]==1 && MTR[4][2]==1)//si l'état 2 dans le tableau passe à la valeur 1 et que front descendant détecté
		{
			printf("Etat 2 passe à la valeur %d \n", MTR[2][0]);
			printf("Ligne du front descendant = %d, \n",i+1);
            printf("Led rouge = %d, Led verte = %d \n\n",*L_R,*L_V);
		}

		if (MTR[3][0]==1 && MTR[4][2]==1)//si l'état 3 dans le tableau passe à la valeur 1 et que front descendant détecté
		{
			printf("Etat 3 passe à la valeur %d \n", MTR[3][0]);
			printf("Ligne du front descendant = %d,\n",i+1);
			MTR[6][0]=0;//Led rouge passe à la valeur 0
			MTR[7][0]=1;//Led verte passe à la valeur 1
            printf("Led rouge = %d, Led verte = %d \n\n",*L_R,*L_V);
			printf("Félicitation vous avez trouvé le bon mot de passe ! \n\n");
		}
		
		if (MTR[0][0]==1 && MTR[4][2]==1)//si l'état 0 dans le tableau passe à la valeur 1 et que front descendant détecté
		{
			printf("Etat 0 passe à la valeur %d \n", MTR[0][0]);
			printf("Ligne du front descendant = %d,\n",i+1);
			MTR[6][0]=1;//Led rouge passe à la valeur 1
			MTR[7][0]=0;//Led verte passe à la valeur 0
            printf("Led rouge = %d, Led verte = %d \n\n",*L_R,*L_V);			
		}
}


	

