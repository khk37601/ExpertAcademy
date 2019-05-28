#include<stdio.h>
#include<stdlib.h>
#define MAX 16
//or 연산자를 이용 한다.
int ar_a[MAX];
int ar_b[MAX];
int n;

//2진수 저장/
void To_bin(int number,int *arr)
{
	for(int i = n-1; i>=0; i--)
	{
		arr[i] = number % 2;
		number /= 2;
	}

}



int main()
{
	int * arr = NULL;
	int * arr2 = NULL;
	scanf_s("%d", &n);
	arr  = (int*)malloc(sizeof(int)*n);
	arr2 = (int*)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++)
		scanf_s("%d", &arr[i],sizeof(arr));

	for (int i = 0; i < n; i++)
		scanf_s("%d", &arr2[i], sizeof(arr2));

	printf("[");
	for (int i = 0; i <n; i++)
	{
		To_bin(arr[i], ar_a);
		To_bin(arr2[i], ar_b);
	    printf("\"");
		//or 연산자 사용 하면  간단 한데...
		for (int j = 0; j <n; j++)
		{	
			//하나라도 1이면 1
			if (ar_a[j] || ar_b[j])
			{
				printf("#");
			}
			else 
			  printf(" ");
		}
		if(i!=n-1)
		printf("\",");
	}
	printf("\"]");


	return 0;
}