#include<stdio.h>
#define MAX 255

//좌,우,위,아래
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

char map[MAX][MAX];
int wolf, shape;
int n, m;

//범위를 벗어났는지 확인 하는 함수
int is_over(int x, int y)
{
	if (x >= 0 && y >= 0 && x < n && y < m)
		return 1;
	else
		return 0;
}

void dfs(int x, int y)
{
	//양인 경우
	if (map[x][y] == 'o')
		shape++;
	//늑대인 경우
	if (map[x][y] == 'v')
		wolf++;

	//방문 했을 경우 x 표시
	map[x][y] = 'x';

	//4방향으로 움직이기 위한 반복문
	for (int i = 0; i < 4; i++)
	{
		//좌,우,위,아래 차례로 움직인다.
		int x_x = x + dx[i];
		int y_y = y + dy[i];

		//범위를 벗어나지 않으면서, 벽이 아니면서 방문하지 않은 곳이면
		if (is_over(x_x, y_y) == 1 && map[x_x][y_y] != '#' && map[x_x][y_y] != 'x')
		{
			//재귀 호출 좌우위아래로 차례로 방문
			dfs(x_x, y_y);
		}


	}
}


int main()
{
	int shape2 = 0, wolf2 = 0;
	scanf("%d%d", &n, &m);

	//양,늑대,벽 입력
	for (int i = 0; i < n; i++)
		scanf("%s", map[i]);


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			shape = wolf = 0;
			//방문 안한 곳이면서 벽이 아닌 경우
			if (map[i][j] != '#' && map[i][j] != 'x')
				dfs(i, j);

			if (shape > wolf)
				shape2 += shape;
			else if (shape <= wolf)
				wolf2 += wolf;
		}

	}

	printf("%d %d\n", shape2, wolf2);

	return 0;
}