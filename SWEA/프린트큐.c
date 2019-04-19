#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node
{
	int order;
	int priovit;
	struct _node* next;
}QueueNode;

typedef struct _Queue
{
	QueueNode* Front;
	QueueNode* Gear;
	int count;
}Queue;

Queue* init()
{
	Queue* qu = (Queue*)malloc(sizeof(Queue));
	qu->Front = NULL;
	qu->Gear  = NULL;
	qu->count = 0;

	return qu;
}
QueueNode* Create(int pi, int order)
{
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	newNode->priovit = pi;
	newNode->order = order;
	newNode->next = NULL;
	return newNode;

}

void Enqueue(Queue* qu, QueueNode* node)
{
	if (qu->Front == NULL && qu->Gear == NULL)
	{
		qu->Gear = qu->Front = node;
		qu->count++;
	}
	else
	{ 
	//printf("%x\n",qu->Gear);
	//printf("%x", qu->Front);
	qu->Gear->next = node;
	qu->Gear = node;
	qu->count++;
	}


}
int empty(Queue* qu)
{
	if (qu->Front == NULL)
	{
		qu->Gear = qu->Front = NULL;
		return 1;
	}
	else
		return 0;
}

QueueNode* dequeue(Queue* qu)
{
	QueueNode* cur = qu->Front;
	//QueueNode  del = *qu->Front;

	if (qu->Front->next == NULL)
	{
		qu->Front = NULL;
		qu->Gear  = NULL;
	}
	else
	{
		qu->Front = qu->Front->next;
		//free(&del);
	}

	qu->count--;
	return cur;

}

QueueNode* pop(Queue* qu)
{
	if (!empty(qu))
		return qu->Front;
	else
		return NULL;
}


int find_max(Queue* qu)
{
	int size = qu->count;
	Queue  tmp = *qu;
	int max = -1;

	for (int loop = 0; loop < size; loop++)
	{

		if (max < (&tmp)->Front->priovit)
			max = (&tmp)->Front->priovit;

		(&tmp)->Front = (&tmp)->Front->next;
	}


	return max;
}


/*
QueueNode * move(Queue *q, int n)
{
	QueueNode * addr = NULL;

	for (int loop = 0; loop <n; loop++)
	{
		q->Sort = q->Sort->next;
	}
	addr = q->Sort;
	q->Sort = q->Front;
	return addr;
}
*/


int main()
{
	Queue* q = NULL;


	int TestCase;
	int  N, M;
	int  count = 0, pri;
	int  max = -1;
	int list[100] = { 0, };


	scanf_s("%d", &TestCase);

	for (int loop = 0; loop < TestCase; loop++)
	{
		q = init();
		scanf_s("%d %d", &N, &M);

		for (int loop2 = 0; loop2<N; loop2++)
		{
			scanf_s("%d", &pri);
			Enqueue(q, Create(pri, loop2));
			
		}
		/*
		
		4 2
        1 2 3 4
		
		2
		
		*/
		while (!empty(q))
		{           
			
			 //�ִ� �켱���� ã��
			 max = find_max(q);

			 //����ū �켱���� �϶�
			 if (pop(q)->priovit == max)
			 {
				 //����ū �켱�����̸鼭 ������ ������ ���
				 if (pop(q)->order == M)
				 {
					 dequeue(q);
					 count += 1;
					 break;
				 }
				 // �ڽ��� ������ ������ �ƴϸ鼭 ����ū �켱���� �� ���
				 count += 1;
				 // ����Ʈ ������ 1�����ְ��ش�.
				 dequeue(q);
			 }
			 //ó�� ��尡 �ֿ켱������ �ƴҰ��
			 else
			 {
				 //������ �ٽ� �ڷ� �ִ´�.
				 QueueNode* Node = dequeue(q);
				 Enqueue(q, Create(Node->priovit, Node->order));
			 }
			
			 //printf("%x %d\n", pop(q), pop(q)->priovit);
		}
	
		printf("%d\n", count);
		count = 0;
	  
	}
	return 0;
}