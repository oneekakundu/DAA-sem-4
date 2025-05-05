#include<stdio.h>
#define max 20
#define inf 999
int m[max][max],r[max][max],n;
int floyd(){
	int i,j,k;
	for(i=1;i<=n;i++){
		r[i][i]=-1;
		for(j=1;j<=n;j++){
			if(m[i][j]!=inf){
				r[i][j]=i;
			}
			else
				r[i][j]=-1;
		}
	}
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(m[i][j]<=m[i][k]+m[k][j]){
					m[i][j]=m[i][j];//no change
				}
				else{
					m[i][j]=m[i][k]+m[k][j];
					r[i][j]=k;
				}
			}
		}
	}
	//print m matrix
	printf("\nThe M matrix:\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j){
				printf("0\t");
			}
			else{
			if(m[i][j]==inf){
				printf("inf\t");
			}
			else{
				printf("%d\t",m[i][j]);
			}
		}
		}
		printf("\n");
	}
	//print r matrix
	printf("\nThe R matrix:\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j){
				printf("N\t");
			}
			else{
			if(r[i][j]==-1){
				printf("--\t");
			}
			else{
				printf("%d\t",r[i][j]);
			}
		}
		}
		printf("\n");
	}
	
}
int main(){
	int i,j;
	printf("Enter the no of vertices:");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix:\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
		scanf("%d",&m[i][j]);
		if(m[i][j]==0){
			m[i][j]=inf;
		}
		}
	}
	floyd();
}
//0 3 0 7
//8 0 2 0
//5 0 0 1
//2 0 0 0









