#include <stdio.h>
#include <stdlib.h>

// Demander à druon si l'espace mémoire de mes tableaux de la fonction reduce_tab sont supprimé

// Permet d'allouer de l'espace mémoire à une matrice
int** create_tab(int nb_l, int nb_c){
	int** T;
	int i;
	T=(int**) malloc(nb_l * sizeof(int *));
	for (i=0;i<nb_l;i++){
		T[i]=(int*) malloc(nb_c * sizeof(int));
	}
	return T;
}
// Supprime une matrice
void delete_tab(int** T, int nb_l, int nb_c){
	int i;
	for (i=0;i<nb_l;i++){
		free(T[i]);
	}
}
// Remplis une matrice en demandant à l'utilisateur
void fill_tab(int** T,int nb_l,int nb_c){
	int i,j;
	for (i=0;i<nb_l;i++){
		for (j=0;j<nb_c;j++){
			printf("[%d,%d]=",i,j);
			scanf("%d",&T[i][j]);
		}
	}
}
// Affiche une matrice
void prompt_tab(int** T,int nb_l,int nb_c){
	int i,j;
	for (i=0;i<nb_l;i++){
		for (j=0;j<nb_c;j++){
			printf("%d ",T[i][j]);			
		}
		printf("\n");
	}
}
// AJoute 2 matrices
void add_tab(int** T1,int l1,int c1,int** T2,int l2,int c2,int** C){
	int i,j;
	for (i=0;i<l1;i++){	
		for (j=0;j<c1;j++){
			C[i][j]=T1[i][j]+T2[i][j];
		}
	}
}
// Multiplie 2 matrices
void mult_tab(int** T1,int l1,int c1,int** T2,int l2,int c2,int** C){
		int i,j,k;
		for (i=0;i<l1;i++){	
			for (j=0;j<c1;j++){
				for (k=0;k<c1;k++){
					C[i][j] += T1[i][k]*T2[k][j];
				}
			}
		}
}
// Calcul la trace d'une matrice
int trace_tab(int** T,int l,int c){
	int i,j,trace=0;
	for (i=0;i<l;i++){
		for (j=0;j<c;j++){
			if (i == j){
				trace += T[i][j];
			}
		}
	}
	return trace;
}
// Reduis une matrice en supprimant la ligne 0 et la colonne del_l donné en argument
int** reduce_tab(int** T,int size,int del_l){
	int i,j,k=0,new_size=size-1;
	int** new_T;
	new_size=size-1;
	new_T=create_tab(new_size,new_size);
	for (i=1;i<size;i++){
			k=0;
			for (j=0;j<size;j++){
				if (j == del_l){
				}
				else{
					new_T[i-1][k]=T[i][j];
					k+=1;
				}
			}
	}
	return new_T;
}
// Calcul le déterminant d'une matrice
int det_tab(int** T,int l){
	int i,det=0;
	if (l == 2){
		det=T[0][0]*T[1][1]-(T[0][1]*T[1][0]);
	}
	else if (l == 1){
		det=0;
	}
	else{
		for (i=0;i<l;i++){
			if ( i%2 == 0){
				det=det - T[0][i]*det_tab(reduce_tab(T,l,i),l-1);
			}
			else{
				det=det + T[0][i]*det_tab(reduce_tab(T,l,i),l-1);
			}
		}
	}
	return det;
}
int main(void)
{
   char option;
   printf("Que voulez vous faire?\nAffichage matrice: a\nAddition matrices: b\nMultiplication matrices: c\ntrace matrice: d\nDeterminant matrice: e\n#");
   scanf("%c",&option);
   getchar();
   if ((option == 'c') || (option == 'b')){
   	printf("** Matrice A **\n");
   }
////////////////////////////////////////////////////
   int in_l1;
   int in_c1;
   int in_l2;
   int in_c2;
   printf("Nombre de lignes: ");
   scanf("%d",&in_l1);
   printf("Nombre de colonne: ");
   scanf("%d",&in_c1);
   int** A;
   int** B;
   A=create_tab(in_l1,in_c1);
   fill_tab(A,in_l1,in_c1);
///////////////////////////////////////////////////
   if (option == 'a'){
	printf("\n** Matrice **\n");
	prompt_tab(A,in_l1,in_c1);
   }
   if ((option == 'c') || (option == 'b')){
   	printf("\n** Matrice B **\n");
   	printf("Nombre de lignes: ");
  	scanf("%d",&in_l2);
   	printf("Nombre de colonne: ");
  	scanf("%d",&in_c2);
   	B=create_tab(in_l2,in_c2);
   	fill_tab(B,in_l2,in_c2);
   	printf("\n ** Matrice A **\n");
   	prompt_tab(A,in_l1,in_c1);

   	printf("\n** Matrice B **\n");
   	prompt_tab(B,in_l2,in_c2);
	if (option == 'b'){
		if ((in_l1 == in_l2) && (in_c1 == in_c2)){
			int** C=create_tab(in_c1,in_l1);
			add_tab(A,in_l1,in_c1,B,in_l2,in_c2,C);
			printf("\n** Somme **\n");
			prompt_tab(C,in_l1,in_c1);
			delete_tab(C,in_c1,in_l1);
		}
		else{
			printf("\nLes deux matrices de sont pas de même dimensions.");
		}
	}
	if (option == 'c'){
		if (in_c1 == in_l2 ){
			int** C=create_tab(in_c1,in_l2);
			mult_tab(A,in_l1,in_c1,B,in_l2,in_c2,C);
			printf("\n** Multiplication **\n");
			prompt_tab(C,in_l1,in_c1);
			delete_tab(C,in_c1,in_l2);
		}
		else{
			printf("Le nombre de colonnes de A doit être égal au nombre de lignes de B");
		}
	}
	delete_tab(B,in_l2,in_c2);
  }
/////////////////////////////////////////////////////////////////////////////
	if (option == 'd'){
		int trace;
		trace=trace_tab(A,in_l1,in_c1);
		printf("Trace = %d",trace);
	}
	if (option == 'e'){
		if (in_l1 == in_c1){
			int det;
			det=det_tab(A,in_l1);
			printf("Determinant = %d",det);
		}
		else{
			printf("Le déterminant est uniquement calculable sur une matrice carrée.");
		}
	}
   delete_tab(A,in_l1,in_c1);
}
