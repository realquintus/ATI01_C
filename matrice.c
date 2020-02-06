#include <stdio.h>
#include <stdlib.h>
int** create_tab(int nb_l, int nb_c){
	int** T;
	int i;
	T=(int**) malloc(nb_l * sizeof(int *));
	for (i=0;i<nb_l;i++){
		T[i]=(int*) malloc(nb_c * sizeof(int));
	}
	return T;
}
void delete_tab(int** T, int nb_l, int nb_c){
	int i;
	for (i=0;i<nb_l;i++){
		free(T[i]);
	}
}
void fill_tab(int** T,int nb_l,int nb_c){
	int i,j;
	for (i=0;i<nb_l;i++){
		for (j=0;j<nb_c;j++){
			printf("[%d,%d]=",i,j);
			scanf("%d",&T[i][j]);
		}
	}
}
void prompt_tab(int** T,int nb_l,int nb_c){
	int i,j;
	for (i=0;i<nb_l;i++){
		for (j=0;j<nb_c;j++){
			printf("%d ",T[i][j]);			
		}
		printf("\n");
	}
}
int main(void)
{
   printf("Que voulez vous faire?\nAffichage matrice: A\nAddition matrices: +\nMultiplication matrices: *\ntrace matrice: T\nDeterminant matrice: D\n");
   scanf()
   printf("** Matrice A **");
   int in_l;
   int in_c;
   printf("Nombre de lignes: ");
   scanf("%d",&in_l);
   printf("Nombre de colonne: ");
   scanf("%d",&in_c);
   int** A;
   A=create_tab(in_l,in_c);
   fill_tab(A,in_l,in_c);
   prompt_tab(A,in_l,in_c);
   delete_tab(A,in_l,in_c);
}
