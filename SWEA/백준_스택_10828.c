#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node
{
	unsigned int data;
	struct _noede * next;
}Node;

typedef struct _stack
{
	int cpaity;
	int size;
	int top;
	Node * list;

}Stack;

Stack * init(int N)
{
	Stack * stack = (Stack*)malloc(sizeof(Stack));
	stack->cpaity = N;
	stack->size   = 0;
	stack->top    = -1;
	stack->list = (Node*)malloc(sizeof(Node)*stack->cpaity);
	return stack;
}

void push(Stack* s,int number)
{
	s->top++;
	s->list[s->top].data = number;
	s->size++;
}

int empty(Stack* s)
{

	if(s->size == 0)
	{
		s->top =0;
		return 1;
	}
	else
		return 0;

}

int top(Stack* s)
{
	if(empty(s) )
	  return -1;
	else
	{
		return s->list[s->top].data;
	}
}

int pop(Stack* s)
{
	int n = 0;
	
	if(empty(s) )
	  return -1;

	else
	{
		s->size--;
		n = s->list[s->top].data;
		s->top--;
		
		return n;
	}
}

int str_cmp(const char * s1,const char *s2)
{
	int cmp = 0;
	while(*(unsigned char*)s1 != NULL)
	{
         if (*s1++ == *(unsigned char*)s2++)
		 {
			   cmp = 0;
		 }else
		 {
			 return -1;
		 }

	}

	return cmp;
}



int main()
{
	int N,number,loop;
	char str[6];
	Stack * stack = NULL;
	printf("%d\n",str_cmp("str","strs"));

	scanf("%d",&N);
	stack = init(N);

	for(loop=0;loop<N;loop++)
	{
	     scanf("%s",str);
		 
		 if(strcmp(str,"push")==0)
		 {
			 scanf("%d",&number);
			 push(stack,number);
		 }
		 else  if(strcmp(str,"pop")==0)
		 {
			 printf("%d\n",pop(stack));
		 }
		 else  if(strcmp(str,"size")==0)
		 {
			 printf("%d\n",stack->size);
		 }
		 else  if(strcmp(str,"empty")==0)
		 {
			 printf("%d\n",empty(stack));
		 }
		 else  if(strcmp(str,"top")==0)
		 {
			 printf("%d\n",top(stack));
		 }
	}


	
	return 0;
}


