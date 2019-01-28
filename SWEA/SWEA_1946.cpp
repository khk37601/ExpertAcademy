#include<iostream>
using namespace std;

/*출력 1라인당 10개씩 출력 되도록 하는 변수*/
static int line = 0;

/*재귀함수 압축해제*/
void decompression(char input, int number1,int line2)
{
	
	if (number1 == 0)
		return;
	
	//10개가 채워지면 줄바꿈
	if (line == 10)
		cout << endl;
	

	cout<<input;

	return decompression(input, number1 - 1,line++);
}

/*10개씩  누적 해서 출력 */
int main()
{
	int Testcase, Testcase2;
	int loop, loop2, number = 0;
	char alphabet = ' ';



       cin>>Testcase;

	for (loop = 0; loop<Testcase; loop++)
	{
		cin>>Testcase2;
		cout <<"#"<<loop + 1 << endl;
		for (loop2 = 0; loop2<Testcase2; loop2++)
		{
			cin >> alphabet >> number;
			decompression(alphabet, number,line);
		}

	}



	return 0;
}









//#include<stdio.h>
//#include<stdlib.h>
//#define TRUE  1
//#define FALSE 0
//#define MAX 100
//
//typedef struct _Stacknode
//{
//	int data;
//	struct _Stacknode * next;
//}Node;
//
//typedef struct _queue
//{
//	Node * front;
//	Node * Gear;
//
//}Queue;
//
//typedef struct Graphnode
//{
//	int vertex;
//	struct Graphnode *next;
//
//}GraphNode;
//
//typedef struct graph
//{
//	int  n; //정점 개수
//	int Vistit[MAX];
//	GraphNode *adjList[MAX];
//}Graph;
//
//Queue * CreatLinkedQueue()
//{
//	Queue * queue = (Queue*)malloc(sizeof(Queue));
//	queue->front = NULL;
//	queue->Gear = NULL;
//	return queue;
//}
//
//int Empty(Queue *s)
//{
//	return s->front == NULL;
//}
//
//void enQueue(Queue * s, int v)
//{
//	Node *newNode = (Node*)malloc(sizeof(Node));
//	newNode->data = v;
//	newNode->next = NULL;
//
//	if (s->front == NULL && s->Gear == NULL)
//	{
//		s->front = newNode;
//		s->Gear = newNode;
//	}
//	else
//	{
//		s->Gear->next = newNode;
//		s->Gear = newNode;
//	}
//
//}
//
//int deQueue(Queue *s)
//{
//	int data;
//
//	if (Empty(s))
//		return 0;
//	else
//	{
//		data = s->front->data;
//		s->front = s->front->next;
//		if (s->front == NULL)
//			s->Gear = NULL;
//
//		return data;
//	}
//}
//
//void CreateGraph(Graph *g)
//{
//	int i;
//	g->n = 0;
//	for (i = 0; i<MAX; i++)
//	{
//		g->adjList[i] = NULL;
//		g->Vistit[i] = FALSE;
//	}
//}
//
//void insertVertex(Graph *g, int v)
//{
//	if ((g->n) + 1 >= MAX)
//		return;
//
//	g->n++;
//}
//
//void insertEdge(Graph * g, int u, int v)
//{
//	if (u >= g->n || v >= g->n)
//	{
//		printf("없는 정점입니다.\n");
//		return;
//	}
//
//	GraphNode * node = (GraphNode*)malloc(sizeof(GraphNode));
//	node->vertex = v;
//	node->next = g->adjList[u];
//	g->adjList[u] = node;
//}
//
//
//void print(Graph *g)
//{
//	int i;
//	GraphNode * p;
//	for (i = 0; i<g->n; i++)
//	{
//		printf("\n\n\t정점 %c의 인접리스트", i + 65);
//		p = g->adjList[i];
//		while (p)
//		{
//			printf("-> %c", p->vertex + 65);
//			p = p->next;
//		}
//	}
//}
//void BFS_adjList(Graph *g, int v)
//{
//	GraphNode * node;
//	Queue * queue = CreatLinkedQueue();
//	g->Vistit[v] = TRUE;
//	printf("%c ", v + 65);
//	enQueue(queue, v);
//
//	while (!Empty(queue))
//	{
//		v = deQueue(queue);
//		for (node = g->adjList[v]; node; node = node->next)
//			if (!g->Vistit[node->vertex])
//			{
//				enQueue(queue, node->vertex);
//				g->Vistit[node->vertex] = TRUE;
//				printf("%c ", node->vertex + 65);
//			}
//			   
//		
//	}
//
//}
//
//
//int main()
//{
//	int i;
//	Graph *g = (Graph*)malloc(sizeof(Graph));
//	CreateGraph(g);
//	for (i = 0; i<7; i++)
//		insertVertex(g, i);
//
//	insertEdge(g, 0, 2);
//	insertEdge(g, 0, 1);
//	insertEdge(g, 1, 4);
//	insertEdge(g, 1, 3);
//	insertEdge(g, 1, 0);
//	insertEdge(g, 2, 4);
//	insertEdge(g, 2, 0);
//	insertEdge(g, 3, 6);
//	insertEdge(g, 3, 1);
//	insertEdge(g, 4, 6);
//	insertEdge(g, 4, 2);
//	insertEdge(g, 4, 1);
//	insertEdge(g, 5, 6);
//	insertEdge(g, 6, 5);
//	insertEdge(g, 6, 4);
//	insertEdge(g, 6, 3);
//	printf("\nG의 인접 리스트");
//	print(g);
//
//	printf("\n\n\n//////////////////\n\n넓이우선 : ");
//	BFS_adjList(g, 0);
//
//
//
//	return 0;
//}
