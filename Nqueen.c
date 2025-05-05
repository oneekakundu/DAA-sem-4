#include<stdio.h> 
//#include<math.h>
int x[100];
int place(int k,int i){
	int j;
	for(j=1;j<=k-1;j++){
		if((x[j]==i) || (abs(x[j]-i) == abs((j-k))))
			return 0;
	}
	return 1;
}
void Nqueen(int k,int n){
	int c,i,l;
	for(i=1;i<=n;i++){
		if(place(k,i)){
			x[k]=i;
			if(k==n){
				for(c=1;c<=n;c++){
					printf("%d ",x[c]);
				}
				// Print the nqueen Matrix
				printf("\n");
				printf("\nSolution:\n");
				for(c=1;c<=n;c++){
					for(l=1;l<=n;l++){
						if(x[c]==l){
							printf("Q%d\t",c);
						}
						else
							printf("--\t");
					}
					printf("\n");
				}
			}
			else
				Nqueen(k+1,n);
		}
	}
}
int main(){
	int n;
	printf("Enter the no. of queens:");
	scanf("%d",&n);
	Nqueen(1,n);
}
