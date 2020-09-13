# include <stdio.h>
int main(){
	int vetor[3];
	int matrix[3][3];
	int x=0,i=0,t=0;
	int mult;
	int resultado;
	for (i=0;i<=2;i++){
		printf("digite o numero: ");
		scanf("%d",&vetor[i]);
		printf("%d\n",vetor[i]);
	}
	for(t=0;t<=2;t++){
		for(x=0;x<=2;x++){
			printf("escreva um numero: ");
			scanf("%d",&matrix[t][x]);
		}
	}
	while(t<=2){
		while(x<=2){	
	mult=vetor[i]*matrix[t][x];
	i++;
	t++;
	x++;
    	printf("%d ",mult);
	}
}
printf("vetor=%d\n",vetor[0]);
scanf("%d", i);
return 0;
}