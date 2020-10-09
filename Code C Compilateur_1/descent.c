#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Descentes recursives //

char *ps;

int parseExpr();
int parseSum();
int parseProduct();
int parseFactor();

int parseFactor()
{
	if (*ps>='0' && *ps<='9')
	{
		return *ps++ - '0';
	}
	else if (*ps=='(')
	{
		ps++;
		int res=parseExpr();
		ps++;
		return res;		
	}
	else
	{
		printf("Syntax error\n");
		return -1;
	}
}

int parseProduct()
{
	int fac1=parseFactor();
	while (*ps=='*' || *ps=='/')
	{
		int op=*ps++;
		int fac2=parseFactor();
		if (op=='*')
			fac1=fac1*fac2;
		else if (op=='/')
			fac1=fac1/fac2;
	}
	return fac1;
}

int parseSum()
{
	int pro1=parseProduct();
	while (*ps=='+' || *ps=='-')
	{
		int op=*ps++;
		int pro2=parseProduct();
		if (op=='+')
			pro1=pro1+pro2;
		else if (op=='-')
			pro1=pro1-pro2;
	}
	return pro1;
}

int parseExpr()
{
	if (*ps=='-')
	{
		ps++;
		int res=parseSum();
		return -res;
	}
	else
	{
		int res=parseSum();
		return res;
	}
}

int main(int argc, char **argv)
{
	ps="2*4*(1+3)";

	int res=parseExpr();
	printf("res=%d\n",res);
	return 0;
}

// fichier source -> ABSTRACT SYNTAX TREE -> genere du code	INFIXE (parcours fils gauche, operateur, fils droit)
//								PREFIXE (operateur, fils gauche, fils droit)
//								POSTFIXE (fils gauche, fils droit, operateur)
//						INTEL Pentium EAX, BX, CX, DX, EX
//						ARM	R0-R15 R0'-R15'
//						SPARC 128 registres
