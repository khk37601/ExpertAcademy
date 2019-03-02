#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cach[100][100];
int Board[100][100];
int n;

int jump(int x, int y)
{
	//���� ����� ���
	if(x>=n || y>=n)
		return 0;
	//���� ���� ���� ���
	else if(x == n-1 && y == n-1)
		return 1;
	//���� ���� �ϸ� 1 ���� �ƴϸ� 0 ����.
	if(cach[x][y] !=-1)
		return cach[x][y];
	
   return cach[x][y] = (jump(x+Board[x][y],y) || jump(x,y+Board[x][y]));  
}


int main()
{
	int C;
	int loop,loop2,loop3;
	scanf("%d",&C);

	for(loop=0;loop<C;loop++)
	{
		scanf("%d",&n);
		memset(cach,-1,sizeof(cach));
		
		for(loop2=0;loop2<n;loop2++)
		{
			for(loop3=0;loop3<n;loop3++)
			  scanf("%d",&Board[loop2][loop3]);
		}

		if(jump(0,0))
			printf("Yes\n");
		else
		    printf("No\n");
	}
}