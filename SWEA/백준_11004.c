#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int size,k;

void swap(int* arr, int left, int right)
{
	int tmp = arr[left];
	arr[left] = arr[right];
	arr[right] = tmp;

}


int partiotion(int* arr, int left, int right)
{
	int pivot = arr[left];
	int start = left + 1;
	int end = right;

	while (start <= end)
	{
		while (pivot >= arr[start] && start <= right)
			start++;

		while (pivot <= arr[end] && end>=(left+1))
			 end--;


		if (start <= end)
		{
			swap(arr,start, end);
		}
    }
	
	swap(arr,left, end);
	
	return end;


}

void QuitSort(int* arr, int left, int right)
{

	if (left <= right)
	{
		int parti = partiotion(arr, left, right);
        if(parti >= k)
		   QuitSort(arr, left, parti-1);
        else if(parti < k)
           QuitSort(arr, parti+1, right);

	}


}


int main()
{
	int *list = NULL;

	scanf("%d%d",&size,&k);
	list = (int*)malloc(sizeof(int) * size);

	for (int loop = 0; loop < size; loop++)
		scanf("%d",&list[loop]);
	QuitSort(list, 0, size-1);
	printf("%d\n", list[k-1]);


	return 0;

}
