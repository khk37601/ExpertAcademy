#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int main()
{
	int TestCase,N;
	int * Block = NULL;
	int loop,loop2;
	int hight = 0, low = 0;

	scanf("%d",&TestCase);
	for(loop=0;loop<TestCase;loop++)
	{
         scanf("%d",&N);
		 /*입력 받는 수 많큼 동적 할당*/
		 Block = (int*)malloc(sizeof(int)*N);

		 /*블럭 크기 입력*/
		 for(loop2 = 0;loop2<N;loop2++)
			 scanf("%d",&Block[loop2]);

		 for(loop2=0;loop2<N-1;loop2++)
		 {
			 if (0 < (Block[loop2+1]- Block[loop2]))
			 {
				 if(hight < Block[loop2+1]- Block[loop2] )
					 hight =  Block[loop2+1]- Block[loop2];	
			 }
			 else
			 {
				 if(low < Block[loop2]- Block[loop2+1])
					 low = Block[loop2]- Block[loop2+1];
			 }

		 }
		     
		  
		 printf("#%d %d %d \n",loop+1,hight,low);
         hight =0,low =0;
		  /*메모리 해제*/
	      free(Block);	 
	}

	return 0;
}