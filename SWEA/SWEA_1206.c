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
		/*���� �Ҵ�*/
		arr = (int*)malloc(sizeof(int)*N);
		for(loop2=0;loop2<N;loop2++)
			scanf("%d",&arr[loop2]);

		for(loop2=2;loop2<N-1;loop2++)
		{
		  //�Ǵ� ���� �ǹ�
          point = arr[loop2];
		  
		  // �ǹ� ���ؿ��� 
		  // �Ѵܰ辿 �ٿ� �����鼭 �������� �������� 2
		  // ���������� 2 ���� �Ǿ��ִ� �� Ȯ��
		  while(point--)
		  {
		    if(point >=arr[loop2-1] && point>= arr[loop2-2]
		       && point >=arr[loop+1]&& point >=arr[loop+2])
		    {
				// ���� �Ǿ��ִٸ� 1������.
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