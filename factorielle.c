#include <stdio.h>
#include <stdlib.h>
int fact_ite(int n){
	int i,fact=1;
	for (i=1;i<=n;i++){
		fact*=i;
	}
	return fact;
}
int fact_rec(int n){
	if (n == 0){
		return 1;
	}
	return n * fact_rec(n-1);
}
int main(void){
	int n,fact;
	printf("!n --> Entrez n:");
	scanf("%d",&n);
	fact=fact_rec(n);
	printf("\n!%d=%d",n,fact);
}
