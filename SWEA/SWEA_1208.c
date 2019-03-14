#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int list[100];

void bubble_sort(int* arr)
{
	int loop,loop2;
	int tmp = 0;
	for(loop =99;loop>=0;loop--)
	{
		for(loop2 = 0;loop2<loop;loop2++)
		{
			if(arr[loop2]>arr[loop2+1])
			{
				tmp = arr[loop2];
				arr[loop2] =  arr[loop2+1];
				arr[loop2+1] = tmp;
			}

		}
	}
}


int main()
{
	int dump,test = 1;
	int loop = 10,loop2;

	while(loop--> 0)
	{
		scanf("%d",&dump);
		for(loop2=0;loop2<100;loop2++)
		  scanf("%d",&list[loop2]);
		bubble_sort(list);

		for(loop2=0;loop2<dump;loop++)
		{
			list[99]--;
			list[0]++;
			bubble_sort(list);
		}
		
		printf("#%d %d\n",test++,list[99]-list[0]);
		memset( list ,0 ,sizeof(list) );
	}

	return 0;
}