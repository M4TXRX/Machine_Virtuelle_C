#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define VARIABLE 1
#define ETAT 2
#define BP 3
#define POT 4
#define OPERATEUR_ADD 100
#define OPERATEUR_MULT 101
#define OPERATEUR_SUB 102
#define OPERATEUR_DIV 103
#define OPERATEUR_AND 104
#define OPERATEUR_GT 105
#define OPERATEUR_EQ 106


// ARBRE BINAIRE : Un noeud de l'arbre a deux fils, le fils gauche, le fils droit
// Un noeud de l'arbre a un type : VARIABLE soit un OPERATEUR
// Un noeud a une valeur : la valeur du noeud

//type=VARIABLE
//VALEUR=3

typedef struct _noeud
{
	int montype;
	int valeur;
	struct _noeud *fg, *fd;
} noeud;

noeud* creerNoeud(int _montype, int _valeur, noeud* _fg, noeud* _fd)
{
	// To cast = lancer un sort
	noeud* pt=(noeud*)malloc(sizeof(noeud));

	pt->montype=_montype;
	pt->valeur=_valeur;
	pt->fg=_fg;
	pt->fd=_fd;

	return pt;
}

// pt=10000 : montype 4 octets
// 10004 : valeur 4 octets
// 10008 : fg, 4 octets sur machine 32bits (8 octets sur les machines 64bits)
// 10012 : fd, 4 octets sur machine 32bits (8 octets sur les machines 64bits)

/*
		ptAdd
		montype=Add
		valeur=-1
	fg=pt3		fd=pt4

		pt3
		montype=VARIABLE
		valeur=3
	fg=NULL		fs=NULL

		pt4
		montype=VARIABLE
		valeur=4
	fg=NULL		fs=NULL
*/

void parcours(noeud *pt)
{
	if (pt->montype==VARIABLE)
	{
		printf("\tPUSHI %d\n",pt->valeur);//on affichera l'intruction PUSHI suivie de la valeur
	}
	
	else if (pt->montype==OPERATEUR_ADD)
	{
		parcours(pt->fg);
		parcours(pt->fd);
		printf("\tADD\n");
	}
	else if (pt->montype==OPERATEUR_MULT)
	{
		parcours(pt->fg);
		parcours(pt->fd);
		printf("\tMULT\n");
	}
	
	else if (pt->montype==ETAT)
	{
		printf("\tPUSH %d 0\n",pt->valeur);//on affichera l'intruction PUSH n 0
										   //n étant l'état actuel (En)
	}

	else if (pt->montype==OPERATEUR_EQ)
	{
		parcours(pt->fg);//on regarde son fils gauche
		parcours(pt->fd);//on regarde son fils droit
		printf("\tEQ\n");//on affichera l'intruction EQ
	}
	
	else if (pt->montype==POT)
	{
		printf("\tPUSH %d 0\n",pt->valeur); //on affichera l'intruction PUSH 5 0
	}
	
	else if (pt->montype==BP)//si le type est le bouton poussoir
	{
		printf("\tPUSH %d 2\n",pt->valeur);//on affichera l'intruction PUSH 4 2
	}
	
	else if (pt->montype==OPERATEUR_GT)
	{
	
		parcours(pt->fg);
		parcours(pt->fd);
		printf("\tGT\n");//on affichera l'intruction GT
	}
	
	else if (pt->montype==OPERATEUR_AND)
	{
		parcours(pt->fg);//on regarde fils gauche
		parcours(pt->fd);//on regarde fils droit
		printf("\tAND\n");//on affichera l'intruction AND
	}
}
	



int main(int argc, char **argv)
{
	// Code déjà présent, non utile
	noeud *pt3=creerNoeud(VARIABLE, 3, NULL, NULL);
	noeud *pt4=creerNoeud(VARIABLE, 4, NULL, NULL);
	noeud *ptAdd=creerNoeud(OPERATEUR_ADD, -1, pt3, pt4);
	noeud *pt5=creerNoeud(VARIABLE, 5, NULL, NULL);
	noeud *ptMult=creerNoeud(OPERATEUR_MULT, -1, ptAdd, pt5);
	//parcours(ptMult);
	
	/// Ajout de code création de noeud et appel de parcours()
	
	//E0 = 1
	noeud *val_1 = creerNoeud(VARIABLE, 1, NULL, NULL);
	noeud *E0 = creerNoeud(ETAT, 0, NULL, NULL);
	noeud *egalite1 = creerNoeud(OPERATEUR_EQ, 1, val_1, E0);
	
	//& bp = 0 
	noeud *bp = creerNoeud(BP, 4, NULL, NULL);
	noeud *et_1 = creerNoeud(OPERATEUR_AND, -1, egalite1, bp );
	
	//& pot > 128
	noeud *val_128 = creerNoeud(VARIABLE, 128, NULL, NULL);
	noeud *pot = creerNoeud(POT, 5, NULL, NULL);
	noeud *egalite2 = creerNoeud(OPERATEUR_GT, 1, val_128, pot);
	
	noeud *et_2 = creerNoeud(OPERATEUR_AND, -1, et_1, egalite2);
	
	parcours(et_2);
	
	return 0;
}


