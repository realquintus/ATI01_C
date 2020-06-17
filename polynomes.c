#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int nb_coef;
	int* P;
} Poly;
// Fonctions d'interaction avec l'utilisateur
Poly ask_poly(){
	Poly X;
	int i,temp;
	printf("Nombre de coefficients:");
	scanf("%d",&temp);
	X.nb_coef = temp;
	X.P = (int*) malloc(X.nb_coef * sizeof(int *));
	printf("\nEntrez les coefficents en commencant par le degré le plus haut.\n");
	for (i=X.nb_coef;i>0;i--){
		printf("x^%d:",i-1);
		scanf("%d",&temp);
		X.P[i] = temp;
	}
	return X;
}
void print_poly(Poly X){
	int i,counter;
	counter=0;
	for (i=X.nb_coef;i>0;i--){
		if (X.P[i] == 0){
		}
		else{	
			if (counter == 0 && X.P[i] > 0){
			}
			else if (X.P[i] > 0){
				printf("+");
			}
			else if (X.P[i] < 0){
			}
			if (X.P[i] == 1){
				if (i == 2){
					printf("x");
				}
				else if (i == 1){
					printf("1");
				}
				else{
					printf("x^%d",i-1);
				}
			}
			else if (X.P[i] == -1){
				if (i == 2){
					printf("-x");
				}
				else if (i == 1){
					printf("-1");
				}
				else{
					printf("-x^%d",i-1);
				}
			}
			else{
				if (i == 2){
					printf("%dx",X.P[i]);
				}
				else if (i == 1){
					printf("%d",X.P[i]);
				}
				else{
					printf("%dx^%d",X.P[i],i-1);
				}
			}
			counter++;
		}
	}
}
//////////////////////////
// Fonctions math //
int eval_poly(Poly X,int x){
	int i,eval,monome,j;
	for (i=X.nb_coef;i>0;i--){
		monome=X.P[i];
		// Calcul de l'exposant
		for (j=0;j<(i-1);j++){
			monome*=x;
		}
		eval += monome;
	}
	return eval;
}
Poly deriv_poly(Poly X){
	Poly dX;
	int i;
	dX.nb_coef = X.nb_coef - 1;
	dX.P = (int*) malloc(dX.nb_coef * sizeof(int *));
	for (i=dX.nb_coef;i>0;i--){
		dX.P[i] = X.P[i+1]*i;
	}
	return dX; 
}
Poly sum_poly(Poly X,Poly X2){
	Poly sX,Xmax,Xmin;
	int i,diff_coef;
	diff_coef = X.nb_coef - X2.nb_coef;
	if (diff_coef > 0){
		Xmax=X;
		Xmin=X2;
	}
	else{
		diff_coef = abs(diff_coef);
		Xmax=X2;
		Xmin=X;
	}
	sX.nb_coef=Xmax.nb_coef;
	sX.P = (int*) malloc(sX.nb_coef * sizeof(int *));
	
	for (i=Xmax.nb_coef;i>0;i--){
		if (i > Xmin.nb_coef){
			sX.P[i] = Xmax.P[i];
		}
		else{
			sX.P[i] = Xmax.P[i] + Xmin.P[i];
		}
	}	
	return sX;
}
Poly prod_poly(Poly X, Poly X2){
	Poly pX;
	int i,j,k;
	pX.nb_coef = X.nb_coef + X2.nb_coef - 1;
	pX.P = (int*) malloc(pX.nb_coef * sizeof(int *));
	for (k=pX.nb_coef;k<0;i++){
		pX.P[i] = 0;
	}
	for (i=X.nb_coef;i>0;i--){
		for (j=X2.nb_coef;j>0;j--){
			pX.P[i+j-1] += X.P[i]*X2.P[j];
		}
	}
	return pX;
}
Poly div_poly(Poly* divX,Poly X,Poly X2){
	Poly reste;
	if (X.nb_coef > X2.nb_coef){
		int i=0,j,g;
		//divX->nb_coef = X.nb_coef - X2.nb_coef + 1;
		//divX->P = (int*) malloc(divX->nb_coef * sizeof(int *));
		reste.nb_coef = X.nb_coef;
		reste.P = (int*) malloc(reste.nb_coef * sizeof(int *));
		for (g=X.nb_coef;g>0;g--){
			reste.P[g]=X.P[g];
		}
		while(reste.nb_coef-i>=X2.nb_coef){
			divX->P[X.nb_coef-X2.nb_coef-i + 1]=reste.P[X.nb_coef-i]/X2.P[X2.nb_coef];//division x^3+2x²-x-2 | x²+0x+1	1) 
			for(j=0;j<X2.nb_coef+i;j++){// i=1 j=1 4
				reste.P[X.nb_coef-j-i]=reste.P[X.nb_coef-j-i]-X2.P[X2.nb_coef-j]*divX->P[X.nb_coef-X2.nb_coef-i+1];//reste
           		}
			i++;
    		}
	}	
	return reste;
}
////////////////////////////////
//
int main(void){
	char option;
	printf("Que voulez-vous faire?\nAffichage polynôme: a\nEvaluer un polynôme: b\nCalculer un polynôme dérivé: c\nSomme de 2 polynômes: d\nProduit de 2 polynômes: e\nDivision euclidienne de 2 polynômes: f\n#");
	scanf("%c",&option);
	getchar(); 
	Poly X;
	// Options ne nécéssitant qu'un seul polynôme
	if ((option == 'a') || (option == 'b') || (option == 'c')){	
		X=ask_poly();
		printf("f(x)=");
		print_poly(X);
		printf("\n");
		if (option == 'b'){
			int x;
			printf(" --> x=");
			scanf("%d",&x);
			int eval = eval_poly(X,x);
			printf("f(%d)=%d\n",x,eval);
		}
		if (option == 'c'){
			Poly dX;	
			dX=deriv_poly(X);
			printf("f'(x)=");
			print_poly(dX);

		}	
	}
	// Options nécéssitant deux polynôme
	else if((option == 'd') || (option == 'e') || (option == 'f')){
		printf("\n** Polynome f(x) **\n");
		X=ask_poly();
		Poly X2;
		printf("\n** Polynome g(x) **\n");
		X2=ask_poly();
		printf("f(x)=");
		print_poly(X);
		printf("\n");
		printf("g(x)=");
		print_poly(X2);
		printf("\n");
		if (option == 'd'){
			Poly sX;
			sX=sum_poly(X,X2);
			printf("f(x)+g(x)=");
			print_poly(sX);
		}
		if (option == 'e'){
			Poly pX;
			pX=prod_poly(X,X2);
			printf("f(x)*g(x)=");
			print_poly(pX);
		}
		if (option == 'f'){
			Poly divX;
			Poly reste;
			//reste.nb_coef = X.nb_coef;
			//reste.P = (int*) malloc(reste.nb_coef * sizeof(int *));
			divX.nb_coef = X.nb_coef - X2.nb_coef + 1;
			divX.P = (int*) malloc(divX.nb_coef * sizeof(int *));
			reste=div_poly(&divX,X,X2);
			printf("\nf(x)/g(x)=");
			print_poly(divX);
			printf("\nReste:");
			print_poly(reste);
		}
	}
	else{
		printf("La valeur entrée ne correspond à aucune action.");
	}
} 
