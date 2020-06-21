//#include <stdio.h>
//#include "polynomes.h"
#include "integrale.h"
#include <math.h>
int main(void){
	float borne_inf,borne_sup,nb_pas,exact_integrale,integrale_rect,integrale_trap,erreur_rect,erreur_trap;
	float* pas;
	int i;
	Poly X;
	X=ask_poly();
	printf("Entrez la borne inférieur:");
	scanf("%e",&borne_inf);
	printf("Entrez la borne supérieur:");
	scanf("%e",&borne_sup);
	printf("Combien de pas d'intération voulez-vous comparer:");
	scanf("%e",&nb_pas);
	pas = (float *) malloc(nb_pas * sizeof(float *));
	printf("Entrez la valeur exacte de l'intégrale (Calculé à la main) :");
	scanf("%e",&exact_integrale);
	for (i=0;i<=nb_pas;i++){
		printf("\nPas %d:",i);
		scanf("%e",&pas[i]);
	}
	for (i=0;i<=nb_pas;i++){
		printf("\n### Pas = %e:",pas[i]);
		integrale_rect=integral_rectangle(X,pas[i],borne_inf,borne_sup);
		integrale_trap=integral_trapeze(X,pas[i],borne_inf,borne_sup);
		printf("\nIntegrale valeur exact=%e",exact_integrale);
		printf("\nIntegrale méthode des rectangles=%e",integrale_rect);
		erreur_rect=fabsf(integrale_rect/exact_integrale-1);
		printf("\nPourcentage d'erreur : %e\n",erreur_rect);
		printf("\nIntegrale méthode des trapèzes=%e",integrale_trap);
		erreur_trap=fabsf(integrale_trap/exact_integrale-1);
		printf("\nPourcentage d'erreur :%e\n###",erreur_trap);
	}
}
