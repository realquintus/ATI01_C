#include <stdio.h>
#include "polynomes.h"
float tangentes(Poly X, Poly dX){
	int nb_tang;
	float abs=0;
	Poly tang_poly;
	tang_poly.nb_coef=X.nb_coef;
	tang_poly.P = (float*) malloc(tang_poly.nb_coef * sizeof(float *));
	Poly temp_poly;
	temp_poly.nb_coef=2;
	temp_poly.P = (float*) malloc(2 * sizeof(float *));
	Poly dX_temp_poly;
	dX_temp_poly.nb_coef=1;
	dX_temp_poly.P = (float*) malloc(1 * sizeof(float *));
	Poly X_temp_poly;
	X_temp_poly.nb_coef=1;
	X_temp_poly.P = (float*) malloc(1 * sizeof(float *));
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
	float test;
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
