#include<stdio.h>
#include<stdlib.h>
#define MAX 100
static int number = 1;

/*���*/
void print(const int * up, const int *down,int up_index,int down_index)
{
	int loop;
	int up_max=up[0],down_max=down[0];
	
	/*�ִ� ������*/
	for(loop=1;loop<up_index;loop++)
		if(up_max < up[loop])
			up_max = up[loop];
	
	/*�ִ� ������*/
	for(loop=1;loop<down_index;loop++)
		if(down_max < down[loop])
			down_max = down[loop];
	

	printf("#%d %d %d\n",number++,up_max,down_max);

}

/*ũ�� ��*/
void hight(const int* arr,const int size)
{
	int loop,index=0,index2=0;
	int up_max[MAX]={0,};
	int down_max[MAX]={0,};

	for(loop=0;loop<size-1;loop++)
	{
		/*���� ũ�Ⱑ Ŭ ���*/
		if(arr[loop] <= arr[loop+1])
			up_max[index++] = arr[loop+1]-arr[loop];
		/*������ ũ�Ⱑ Ŭ ���*/
		else if(arr[loop] >= arr[loop+1])
			down_max[index2++] = arr[loop]-arr[loop+1];
		
	}

	print(up_max,down_max,index,index2);
}



int main()
{
	int TestCase,N;
	int * Block = NULL;
	int loop,loop2;

	scanf("%d",&TestCase);
	for(loop=0;loop<TestCase;loop++)
	{
         scanf("%d",&N);
		 /*�Է� �޴� �� ��ŭ ���� �Ҵ�*/
		 Block = (int*)malloc(sizeof(int)*N);

		 /*�� ũ�� �Է�*/
		 for(loop2 = 0;loop2<N;loop2++)
			 scanf("%d",&Block[loop2]);
		 

		  hight(Block,N);
		  /*�޸� ����*/
	      free(Block);	 
	}

	return 0;
}