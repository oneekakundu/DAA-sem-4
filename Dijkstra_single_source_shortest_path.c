#include <stdio.h>
#define INF 9999
#define MAX 10

int cost[MAX][MAX], visited[MAX], dist[MAX],pred[20],v;

void dijkstra(int n, int s) {
    int i, count, u, min;
    
    for (i = 1; i <= n; i++) {
        visited[i] = 0;
	    dist[i] = INF;
       	pred[i]=s;
    }
    dist[s] = 0;
    visited[s] = 1;
    pred[s]=-1;
    
    for(count=2;count<=n;count++){
        min = INF;
        for (v = 1; v <= n; v++) {
            if (dist[v] < min && !visited[v]) {
                min = dist[v];
                u = v;
            }
        }
        visited[u] = 1;
        
        for (v = 1; v <= n; v++) {
            if (!visited[v] && dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
                pred[v]=u;
            }
        }
    }
}

int main() {
    int n, i, j, s;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the cost adjacency matrix (use %d for infinity):\n", INF);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    
    printf("Enter the source vertex: ");
    scanf("%d", &s);
    
    dijkstra(n,s);
    
    for (i = 1; i <= n; i++) {
        printf("%d->%d->%d = %d",s,pred[i],i, dist[i]);
    }
    
    return 0;
}

