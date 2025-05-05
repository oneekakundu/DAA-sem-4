#include<stdio.h>
int partition(int a[100],int p,int q){
	int temp;
	int i=p;
	int j=q;
	int x = a[p];//pivot
	while(i<j){
		while(a[i]<=x){
			i++;
		}
		while(a[j]>x){
			j--;
		}
		if(i<j){
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		}
	}
	temp = a[p];
	a[p] = a[j];
	a[j] = temp;

	return j;
}
void quick_sort(int a[100],int p,int q){
	if(p<q){
	int r=partition(a,p,q);
	quick_sort(a,p,r-1);
	quick_sort(a,r+1,q);
	}
}
int main(){
	int a[100],i,n;
	printf("\nEnter the no of elements in the array:");
	scanf("%d",&n);
	printf("\nEnter the array elements");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	quick_sort(a,0,n-1);
	printf("The sorted array is:\n");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}
