#include<stdio.h>
#include<stdlib.h>

/*���� ����*/
void sort_s(int *arr,int size)
{
	int loop,loop2,tmp =0 ;
	for(loop=size-1;loop>0;loop--)
	{
		for(loop2=0;loop2<loop;loop2++)
		{
			 if(arr[loop2]<arr[loop2+1])
			 {
				 tmp=arr[loop2];
				 arr[loop2]=arr[loop2+1];
				 arr[loop2+1]= tmp;
			 }
		}
	}
}

/*������������ ���ĵ� �迭�� k��ŭ �� ����.*/
int total_sum(int * arr,int k)
{
	int loop,sum=0;
	for(loop=0;loop<k;loop++)
	   sum +=arr[loop];

	return sum;
}


/*

   ���� k���� ���� �ִ����� ���ϱ�
   �迭�� ���� ������������ ���� �� 
   k���� ���� �����ָ� �ִ� ���� �� �� �� �ִ�.

*/

int main()
{
	int TestCase,N,K;
    int *arr = NULL;
	int loop,loop2,loop3;
	int sum = 0;
	scanf("%d",&TestCase);
	
	for(loop=0;loop<TestCase;loop++)
	{
		scanf("%d%d",&N,&K);
		arr = (int*)malloc(sizeof(int)*N);
		
		for(loop2=0;loop2<N;loop2++)
		{
			scanf("%d",&arr[loop2]);
		}
		
		 sort_s(arr,N);
		 printf("#%d %d",loop+1,total_sum(arr,K));

	}



	return 0;
}