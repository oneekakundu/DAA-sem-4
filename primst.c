#include<stdio.h>
#define max 20
#define inf 999
int visited[max],g[max][max],n,mincost=0;
void prims(){
	int min,i,k,j,v1,v2;
	for(i=1;i<=n;i++){
		visited[i]=0; //mark all the vertices unvisited;
	}
	visited[1]=1;
	for(k=1;k<=n-1;k++){//iterate through n-1 edges to get the MST;
		min=inf;
		v1=v2=-1;
		for(i=1;i<=n;i++){
			if(visited[i]){
				for(j=1;j<=n;j++){
						if(!visited[j] && g[i][j]<min){
							min=g[i][j];
							v1=i;
							v2=j;
						}
				}
			}
		}
		mincost += min;
		visited[v2]=1;
		printf("Edge %d(%d -> %d)= %d\n",k,v1,v2,min);
	}
}
int main(){
	int i,j;
	printf("Enter the no. of vertices:");
	scanf("%d",&n);
	printf("Enter the adjacency matrix:\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&g[i][j]);
			if(g[i][j]==0)
				g[i][j]=inf;
		}
	}
	prims();
	printf("The MST cost: %d\n",mincost);
	
}
//0 8 1 5 0 0
//8 0 5 0 3 0
//1 5 0 5 6 4
//5 0 5 0 0 2
//0 3 6 0 0 6
//0 0 4 2 6 0
