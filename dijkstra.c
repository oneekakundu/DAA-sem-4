#include<stdio.h>
#define max 20
#define inf 999
int cost[max][max],visited[max],pred[max],dist[max],n,s,v;
void dijkstra(){
	int i,min,count,u;
	for(i=1;i<=n;i++){
		visited[i]=0;//mark all the vertices unvisited
		dist[i]=inf;//all distances set to infinity 
	}
	visited[s]=1;//source is visited 
	dist[s]=0;//dist of sourcr to itself
	u=s;
	for(count =2;count<=n;count++){//from 2 as already one vertix is visited
		min=inf;
		for(v=1;v<=n;v++){
			if(!visited[v] && dist[v]<min){
				min=dist[v];
				u=v;
			}
		}
		visited[u]=1;
		for(v=1;v<=n;v++){//relaxation part
			if(!visited[v] && dist[u]+cost[u][v]<dist[v]){
			dist[v]=dist[u]+cost[u][v];
		}
		}
	}
}
int main(){
	int i,j;
	printf("Enter the no. of vertices:");
	scanf("%d",&n);
	printf("\nEnter the source vertex:");
	scanf("%d",&s);
	printf("\nEnter the cost matrix:\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0 && i!=j)
			cost[i][j]=inf;
		}
	}
	dijkstra();
	
	for(i=1;i<=n;i++){
		printf("\n%d->%d=%d",s,i,dist[i]);
	}
	return 0;
}
//0 2 7 0 0
//2 0 3 8 5
//0 2 0 1 5
//0 0 0 0 5
//0 0 0 4 0
