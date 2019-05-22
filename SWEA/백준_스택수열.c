#include<stdio.h>
#include<stdlib.h>
typedef struct _node
{
	unsigned int data;
	struct _noede* next;
}Node;

typedef struct _stack
{
	int cpaity;
	int size;
	int top;
	Node* list;

}Stack;

Stack* init(int N)
{
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->cpaity = N;
	stack->size = 0;
	stack->top = -1;
	stack->list = (Node*)malloc(sizeof(Node) * stack->cpaity);
	return stack;
}

void push(Stack* s, int number)
{
	s->top++;
	s->list[s->top].data = number;
	s->size++;
}

int empty(Stack* s)
{

	if (s->size == 0)
	{
		s->top = 0;
		return 1;
	}
	else
		return 0;

}

int top(Stack* s)
{
	if (empty(s))
		return -1;
	else
	{
		return s->list[s->top].data;
	}
}

int pop(Stack* s)
{
	int n = 0;

	if (empty(s))
		return -1;

	else
	{
		s->size--;
		n = s->list[s->top].data;
		s->top--;

		return n;
	}
}
int main()
{

	int n;
	int* numberList = NULL;
	Stack* stack = NULL;
	char operater[1000000] = {0,};

	scanf_s("%d", &n);
	//스택 초기화
	stack = init(n);

	//원하는 수열 리스트
	numberList = (int*)malloc(sizeof(int) * n);

	for (int loop = 0; loop < n; loop++)
		scanf_s("%d", &numberList[loop]);

	//수열 인덱스
	int index = 0;
	int index2 = 0;

	//1~ n 까지 수
	for (int number = 1; number <= n; number++)
	{
		push(stack, number);
		operater[index2++] = '+';
		//index2++;
		 

		//stack이 비워져있지 않으면서 원하는 수열의 top과 stack의 top이 같은 경우
		while (!empty(stack) && numberList[index] == top(stack))
		{
			pop(stack);
			//원하는 수를 만나서 인덱스 증가.
			index++;
			operater[index2++] = '-';
		}
	
	}
	//스택이 비워져 있지 않다면
	// 수열 완성 실패
	if (!empty(stack))
	{
		puts("NO");
	}
	else
	{
		for (int i = 0; i <index2; i++)
		{
			printf("%c\n",operater[i]);
		}
	}

	return 0;
}