#include<stdio.h>
#include<stdlib.h>
#define MAX 300

char arr2[MAX];
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

void push(char number)
{
	
	if(!is_full())
	{	
	  arr2[++top]= number;
 	}
	else
	{
		 printf("°¡µæ Ã¡½À´Ï´Ù.");
	     return;   
	}


}
int pop()
{
	return arr2[top--];
}


int main() 
{
	int n,i,check = 1,loop;
	int arr[10];
	char *ch= NULL,ch2;

	for(loop=0;loop<10;loop++)
	{


	scanf("%d",&n);
	init();
	ch = (char*)malloc(sizeof(char)*n+1);
	scanf("%s",ch);

	for(i=0;i<n;i++)
	{
		switch(ch[i])
		{
		case '{':case '(':case'[': case '<':
			push(ch[i]);
			break;
		case '}':case ')':case']': case '>':
				   ch2 = pop();
				 if(   (ch2 =='{' && ch[i]!='}')
					|| (ch2 =='(' && ch[i] !=')')
					|| (ch2 =='[' && ch[i] !=']')
					|| (ch2 =='<' && ch[i] !='>')
					 )
				 {
					 check = 0;
				 }
			
			
			break;
		}

		
	
	}

	  arr[loop] = check;
	  check =1;

	}






	for(loop=0;loop<10;loop++)
		printf("#%d %d\n",loop+1,arr[loop]);



	return 0;

	
}