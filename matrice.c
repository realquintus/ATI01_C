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
int main(void)
{
   int in_l;
   int in_c;
   printf("Nombre de lignes: ");
   scanf("%d",&in_l);
   printf("Nombre de colonne: ")
   scanf("%d",&in_c);
   int** A;
   A=create_tab(10,50);
   int i;
   for (i=0;
   A[1][1] = 1;
   delete_tab(A,10,50);
}
