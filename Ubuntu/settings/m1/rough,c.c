#include<stdio.h>
int partition(int a[],int start,int end)
{
	int pivot,i,j,temp;
	pivot=a[start];
	i=start;
	j=end+1;
	do
	{
		do
			i++;
		while(a[i]<pivot&&i<=end);
			do
			{
				j--;
			}while(pivot<a[j]);
			if(i<j)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
				
	}while(i<j);
	a[start]=a[j];
	a[j]=pivot;
	return j;
}
void  quicksort(int a[],int s,int e)
{
	int j,i;
	if(s<e)
	{
		j=partition(a,s,e);
		quicksort(a,s,j-1);
		quicksort(a,j+1,e);
	}
}
int main()
{
	int a[100],n,i;
	printf("How many elements?");
	scanf("%d",&n);
	printf("\nEnter array elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	quicksort(a,0,n-1);
	printf("\nArray after sorting:");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}

