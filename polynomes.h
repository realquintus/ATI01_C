#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int nb_coef;
	float* P;
} Poly;
// Fonctions d'interaction avec l'utilisateur
Poly ask_poly(){
	Poly X;
	int i;
	float temp;
	printf("Nombre de coefficients:");
	scanf("%d",&X.nb_coef);
	X.P = (float*) malloc(X.nb_coef * sizeof(float *));
	printf("\nEntrez les coefficents en commencant par le degré le plus haut.\n");
	for (i=X.nb_coef;i>0;i--){
		printf("x^%d:",i-1);
		scanf("%e",&temp);
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
					printf("%ex",X.P[i]);
				}
				else if (i == 1){
					printf("%e",X.P[i]);
				}
				else{
					printf("%ex^%d",X.P[i],i-1);
				}
			}
			counter++;
		}
	}
}
//////////////////////////
//// Fonctions math ////

float eval_poly(Poly X,float x){
	int i,j;
	float monome,eval=0;
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
	dX.P = (float*) malloc(dX.nb_coef * sizeof(float *));
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
	sX.P = (float*) malloc(sX.nb_coef * sizeof(float *));

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
	pX.P = (float*) malloc(pX.nb_coef * sizeof(float *));
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
		reste.P = (float*) malloc(reste.nb_coef * sizeof(float *));
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

