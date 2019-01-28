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
		 printf("가득 찼습니다.");
	     return;   
	}


}
int pop()
{
	return Stack[top--];
}


int main()
{
	/* + *만 있는 계산기 */
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
		  /*숫자 일경우 stack에 push*/
          if(arr[j]-48 >=0 && arr[j]-48<=9)
		  {
			  push(arr[j]-48);
		  }
		  /*곱하기 연산 일 경우*/
		  else if(arr[j] == '*')
 		  {
			  /* 
			   1+3*3*7*6 
			    *의 오른쪽 피연산자를 stack 넣고 
				두번 pop 하여서 곱한후 stack에 다시 넣는다.
				곱한 값누적 시킴
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




