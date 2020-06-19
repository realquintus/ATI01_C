#include <stdio.h>
#include "polynomes.h"
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
