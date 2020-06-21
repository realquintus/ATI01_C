#include <stdio.h>
#include <stdlib.h>
#include "polynomes.h"
float integral_rectangle(Poly X, float pas, float borne_inf, float borne_sup){
	float integral=0,i;
	for (i=borne_inf;i<borne_sup;i+=pas){
		integral+=pas*eval_poly(X,i);
	}
	return integral;
}
float integral_trapeze(Poly X, float pas, float borne_inf, float borne_sup){
	float i,triangle=0,integral=0;
	for (i=borne_inf;i<borne_sup;i+=pas){
		triangle=pas*(eval_poly(X,i+pas)-eval_poly(X,i))/2;
		integral+=pas*eval_poly(X,i)-triangle;;
	}
	return integral;
}
