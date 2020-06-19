#include <stdio.h>
#include "polynomes.h"
double tangentes(Poly X, Poly dX){
	int nb_tang;
	double abs=0;
	Poly tang_poly;
	tang_poly.nb_coef=X.nb_coef;
	tang_poly.P = (int*) malloc(tang_poly.nb_coef * sizeof(int *));
	Poly temp_poly;
	temp_poly.nb_coef=2;
	temp_poly.P = (int*) malloc(2 * sizeof(int *));
	Poly dX_temp_poly;
	dX_temp_poly.nb_coef=1;
	dX_temp_poly.P = (int*) malloc(1 * sizeof(int *));
	Poly X_temp_poly;
	X_temp_poly.nb_coef=1;
	X_temp_poly.P = (int*) malloc(1 * sizeof(int *));
	for (nb_tang=0;nb_tang<50;nb_tang++){
		temp_poly.P[2] = 1;
		temp_poly.P[1] = abs;
		dX_temp_poly.P[1] = eval_poly(dX,abs);
		X_temp_poly.P[1] = eval_poly(X,abs);
		tang_poly = sum_poly(X_temp_poly,prod_poly(dX_temp_poly,temp_poly));
		abs = (0-tang_poly.P[1])/tang_poly.P[2];
		printf("\n%e",abs);
	}
	return abs;	
}

int main(void){
	Poly X;
	Poly dX;
	double test;
	X=ask_poly();
	dX=ask_poly();
	printf("\nF(x)=");
	print_poly(X);
	printf("\nf(x)=");
	print_poly(dX);
	printf("\n");
	test=tangentes(X,dX);
	printf("\n%e",test);
}
