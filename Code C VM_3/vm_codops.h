#define OP_HALT 1000 	   //marquage de fin du fichier .bin
#define OP_PUSHI        100//insertion d'une valeur d'un élément extérieur dans la pile 
#define OP_PUSH         200//insertion d'une valeur dans la pile
#define OP_POP          300//envoie d'une valeur de la pile vers l'extérieur
#define OP_PLUS         400//addition de deux valeurs de la pile
#define OP_MOINS        401//soustraction de deux valeurs de la pile
#define OP_MULT         402//multiplication de deux valeurs de la pile
#define OP_DIV          403//division de deux valeurs de la pile
#define OP_AND          404//opération d'un ET logique entre deux valeurs de la pile
#define OP_OR           405//opération d'un OU logique entre deux valeurs de la pile
#define OP_NOT          406//opération d'un NOT logique sur une valeur de la pile
#define OP_EQ           407//vérification de l'égalité entre deux valeurs de la pile
#define OP_GT           408//vérifie qu'une valeur de la pile est plus grande qu'une autre valeur
#define OP_LT           409//vérifie qu'une valeur de la pile est plus petite qu'une autre valeur
#define OP_JZ           500//fait un saut dans la pile si la valeur de la pile actuelle vaut 0
#define OP_JP           501//fait un saut dans la pile si la valeur de la pile actuelle vaut 1


