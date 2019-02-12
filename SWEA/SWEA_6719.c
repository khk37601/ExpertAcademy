#include<stdio.h>
#include<stdlib.h>

void sort_ascending (int * arr,const int size)
{
	/*버블 정렬*/
	int loop,loop2;
	int tmp = 0;
	for(loop =size-1;loop>0;loop--)
	{
		for(loop2=0;loop2<loop;loop2++)
		{
			if(arr[loop2]>arr[loop2+1])
			{
				tmp =arr[loop2];
                arr[loop2] = arr[loop2+1];
                arr[loop2+1] = tmp;
			}
		}
	}

}

double avg_s( int * arr2, int k,int n)
{
	int loop;
	double avg = 0.0;
	for(loop=n-k;loop<n;loop++)
        avg = (arr2[loop]+avg)/2.0;
  
	return avg;
}


int main()
{
	int TestCase;
	int N,K,loop,loop2;
	int * arr = NULL;
    
	scanf("%d",&TestCase);
	for(loop=0;loop<TestCase;loop++)
	{
		scanf("%d%d",&N,&K);
		arr = (int*)malloc(sizeof(int)*N);
		for(loop2=0;loop2<N;loop2++)
			scanf("%d",&arr[loop2]);
        
		sort_ascending (arr,N);
		printf("#%d %lf\n",loop+1,avg_s(arr,K,N));
	}
	return 0;
}