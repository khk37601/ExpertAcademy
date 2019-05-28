#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define MAX 100000
int time = 0;
int cacheSize;
/*
   LRU 알고리즘
   큐를 이용한다.
*/
typedef struct _node
{
	char str[20];
	struct _node * next;
}Node;

typedef struct _list
{
	Node* Font;
	Node* Gear;
	int size;
}List;

List* init()
{
	List* list = (List*)malloc(sizeof(List));
	list->Font = NULL;
	list->Gear = NULL;
	list->size = 0;
}
int push(char *c, List* p,int count)
{
	//새로운 노드 생성
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	strcpy_s(newNode->str,20,c);
	
	if (p->Font == NULL)
	{
		p->Gear = p->Font = newNode;
		p->size++;
		
		return 1;
	}
	else if(p->size < count)
	{
		p->Gear->next = newNode;
		p->Gear = newNode;
		p->size++;
		return 1;
	}
	return 0;//실패
}

Node * pop(List *q)
{
	if (q->Font == NULL || q->Gear == NULL)
		return NULL;
	else
	{
		Node tmp = *q->Font;
		Node *del = q->Font;
		q->size--;
		//이동
		q->Font = q->Font->next;
		free(del);
		return &tmp;
	}
}

int contain(List * head, char * str)
{
	List tmp_head = *head;
	int is = 0;
	while (tmp_head.Font != tmp_head.Gear)
	{
		//같을 경우
		if (strcmp(str, tmp_head.Font->str) == 0)
		{
			time += 1;
			//빼고 제일 뒤에 넣는다.
			pop(head);
			//제일 뒤에 넣는다.
			push(str, head,cacheSize);
			return 1; // 캐쉬 히트
		}
		//이동
		tmp_head.Font = tmp_head.Font->next;
	}

	//가장 오랫동안 안쓴거 빼기
	pop(head);
	return 0;// 캐쉬 미스.
}


int main()
{
	List * head = init();
	//3: char cities[][10] = { "Jeju", "Pangyo","Seoul","NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };	 
	//0: char cities[][10] = {"Jeju","Pangyo","Seoul","NewYork","LA"};
	//3: char cities[][10] = { "Jeju","Pangyo","Seoul","Jeju","Pangyo","Seoul","Jeju","Pangyo","Seoul" };
	
	char cities[][20] = { "Jeju", "Pangyo","Seoul","NewYork", "LA","SanFranisco","Seoul", "Rome", "Paris","jeju","NewYork", "Rome" };
	
	int len = sizeof(cities) / sizeof(cities[0]);

	scanf_s("%d", &cacheSize);
	for (int i = 0; i <len; i++)
	{
		//cache miss
		if (push(&cities[i], head,cacheSize))
		{
			time += 5;
		}
		else
		{  
			//캐쉬 메모리에 있는 판별.
			//contain함수 내부에서 캐쉬 성공 하면 1증가.
			if (!contain(head, &cities[i]))
			{
				//캐쉬 미스.
				time += 5;
			}				
				//현재 문자열 케쉬에 넣기
				push(&cities[i], head, cacheSize);
		}		

	}
	printf("%d\n", time);
	return 0;
}