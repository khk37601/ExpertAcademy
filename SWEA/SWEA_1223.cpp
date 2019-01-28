#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 300

int Stack[MAX];
int top;

void init()
{
	top = -1;
}

int is_full()
{
	return top == MAX; 
}

int Empty()
{
	return top == -1;
}

void push(int number)
{
	
	if(!is_full())
	{	
	  Stack[++top]= number;
 	}
	else
	{
		 printf("���� á���ϴ�.");
	     return;   
	}


}
int pop()
{
	return Stack[top--];
}


int main()
{
	/* + *�� �ִ� ���� */
	char * arr = NULL;
	int sum =0,len;
	init();
    
	for(int i=0;i<1;i++)
	{
		scanf("%d",&len);
		arr =(char*)malloc(sizeof(char)*len+1);
		scanf("%s",arr);
        for(int j=0;j<len;j++)
		{
		  /*���� �ϰ�� stack�� push*/
          if(arr[j]-48 >=0 && arr[j]-48<=9)
		  {
			  push(arr[j]-48);
		  }
		  /*���ϱ� ���� �� ���*/
		  else if(arr[j] == '*')
 		  {
			  /* 
			   1+3*3*7*6 
			    *�� ������ �ǿ����ڸ� stack �ְ� 
				�ι� pop �Ͽ��� ������ stack�� �ٽ� �ִ´�.
				���� ������ ��Ŵ
			  */
			  push(arr[j+1]-48);
			  push(pop()*pop());
			  j+=1;
		 }

		}

		while(!Empty())
		{
			sum +=pop();
			 printf("sum : %d\n",sum);
		}

		printf("#%d %d\n",i+1,sum);

		sum = 0;
	}

	free(arr);
	return 0;
}




