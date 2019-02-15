#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
/*
int Max(const int *a, const int *b)
{
    if((unsigned)*a < (unsigned)*b)
		return (*b - *a);
	else
		return (*a - *b);
}
*/
int main()
{
	
	int TestCase,loop,loop2,N;
  	int *arr = NULL,point = 0,count =0;
	for(loop=0;loop<10;loop++)
	{
		scanf("%d",&N);
		/*동적 할당*/
		arr = (int*)malloc(sizeof(int)*N);
		for(loop2=0;loop2<N;loop2++)
			scanf("%d",&arr[loop2]);

		for(loop2=2;loop2<N-1;loop2++)
		{
		  //판단 기준 건물
          point = arr[loop2];
		  
		  // 건물 기준에서 
		  // 한단계씩 줄여 나가면서 조망권이 왼쪽으로 2
		  // 오른쪽으로 2 보장 되어있는 지 확인
		  while(point--)
		  {
		    if(point >=arr[loop2-1] && point>= arr[loop2-2]
		       && point >=arr[loop+1]&& point >=arr[loop+2])
		    {
				// 보장 되어있다면 1씩증가.
			  count++;
		    }else
			    break;
		    }
	
		 }

		printf("#%d %d",loop+1,count);
		count = 0;
		free(arr);
	}

	return 0;
}