#include<stdio.h>
#define max 20
int n,cap;
float r[max],tp=0.0,f[max],v[max],w[max];
void sort_knap(){
	int i,j,p,temp;
	float max1;
	for(i=1;i<=n;i++){
			max1=r[i];
			p=i;
			for(j=i+1;j<=n;j++){
				if(max1<r[j]){
				max1=r[j];
				p=j;
			}
			}
			if(p!=i){
				temp=r[i];
				r[i]=r[p];
				r[p]=temp;
				
				temp=v[i];
				v[i]=v[p];
				v[p]=temp;
				
				temp=w[i];
				w[i]=w[p];
				w[p]=temp;
			}
	}
	for(i=1;i<=n;i++){
		printf("%f ",r[i]);	
	}
}
void knapsack(){
	int i,j;
	for(i=1;i<=n;i++){
		if(cap>0 && w[i]<=cap){
			f[i]=1.0;
			cap -= w[i];
			tp += v[i];
		}
		else if(cap>0){
			f[i]=(cap/w[i]);
			tp += (v[i]*f[i]); 
			cap=0;
		}
		else
			break;
	}
}
int main(){
	int i;
	printf("Enter the no of items:");
	scanf("%d",&n);
	printf("\nEnter the profit and weight of the items respectively:");
	for(i=1;i<=n;i++){
		scanf("%f%f",&v[i],&w[i]);
	}
	printf("\nEnter the capacity of the knapsack:");
	scanf("%d",&cap);
	for(i=1;i<=n;i++){//calculate the ratio
		r[i]=(v[i]/w[i]);
		f[i]=0;
		//printf("%d ",v[i]);
		//printf("%d ",w[i]);
		//printf("%f ",r[i]);
	}
	sort_knap();
	knapsack();
	printf("\nThe elements:");
	for(i=1;i<=n;i++){
		printf(" %.3f",f[i]);
	}
	printf("\nThe total profit ia %.3f",tp);
	return 0;
}
//30 5
//20 10
//100 20
//90 30
//160 40
