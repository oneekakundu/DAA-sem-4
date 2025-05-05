#include<stdio.h>
int max, min,a[100];
void maxmin(int i,int j){
	int max1,min1,m;
	if(i==j)//only one element is there
		max=min=a[i];
	else if(i==j-1){//only 2 element is there
		if(a[i]<a[j]){
			min=a[i];
			max=a[j];
		}
		else{
			max=a[i];
			min=a[j];
			
		}
	}
	else{//more than 2 elements     
		m=(i+j)/2;
		maxmin(i,m);
		max1=max;
		min1=min;
		maxmin(m+1,j);
		if(max1>max)
			max=max1;
		if(min1<min)
			min=min1;
		}
	
}
int main(){
	int i,n;
	printf("Enter the no. of elements in the array:");
	scanf("%d",&n);
	printf("\nEnter the array elements:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	maxmin(0,n-1);
	printf("\nThe max element is %d",max);
	printf("\nThe min element is %d",min);
}
