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
void add_tab(int** T1,int l1,int c1,int** T2,int l2,int c2,int** C){
	int i,j;
	//printf("test");
	for (i=0;i<l1;i++){	
		for (j=0;j<c1;j++){
			//printf("test");
			C[i][j]=T1[i][j]+T2[i][j];
		}
	}
}
void mult_tab(int** T1,int l1,int c1,int** T2,int l2,int c2,int** C){
		int i,j,k;
		//printf("test");
		for (i=0;i<l1;i++){	
			for (j=0;j<c1;j++){
				for (k=0;k<c1;k++){
					C[i][j] += T1[i][k]*T2[k][j];
					//printf("%d * %d = %d \n",T1[i][k],T2[k][j],C[i][j]);
				}
			}
		}
}
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
int** reduce_tab(int** T,int size,int del_l){
	int i,j,k=0,new_size=size-1;
	int** new_T;
	new_size=size-1;
	new_T=create_tab(new_size,new_size);
	//printf("size=%d,new_size=%d,del_l=%d\n",size,new_size,del_l);
	for (i=1;i<size;i++){
			k=0;
			for (j=0;j<size;j++){
				if (j == del_l){
				//	printf("i=%d,j=%d,k=%d\n\n\n",i,j,k);
				}
				else{
				//	printf("k=%d \n",k);
					//printf("i=%d,j=%d,k=%d\n",i,j,k);
					//printf("%d ",T[i][j]);
					new_T[i-1][k]=T[i][j];
					k+=1;
				}
			}
		//printf("\n");
	}
	//prompt_tab(new_T,new_size,new_size);
	return new_T;
}
int det_tab(int** T,int l){
	int i,det=0;
	//printf("\n%d\n");
	if (l == 2){
		//printf("det=%d*%d-(%d*%d)",T[0][0],T[1][1],T[0][1],T[1][0]);
		det=T[0][0]*T[1][1]-(T[0][1]*T[1][0]);
		//printf("=%d\n",det);
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
