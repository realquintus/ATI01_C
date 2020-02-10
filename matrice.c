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

void add_tab(int** T1,int l1,int c1,int** T2,int l2,int c2,int** C,int max_l, int max_c){
	int i,j;
	//printf("test");
	for (i=0;i<l1;i++){	
		for (j=0;j<c1;j++){
			//printf("test");
			C[i][j]=T1[i][j]+T2[i][j];
		}
	}}
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
///////////////////////////////////////////////////
   	printf("\n** Matrice B **\n");
   	prompt_tab(B,in_l2,in_c2);
	int max_c,max_l;
	if (option == 'b'){
		if (in_c1<in_c2){
			max_c=in_c2;
		}
		else{
			max_c=in_c1;
		}
		if (in_l1<in_l2){
			max_l=in_l2;
		}
		else{
			max_l=in_l1;
		}
		int** C=create_tab(max_l,max_c);
		add_tab(A,in_l1,in_c1,B,in_l2,in_c2,C,max_l,max_c);
		printf("\n** Somme **\n");
		prompt_tab(C,in_l1,in_c1);
		delete_tab(C,in_c1,in_l1);
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
   delete_tab(A,in_l1,in_c1);
}
