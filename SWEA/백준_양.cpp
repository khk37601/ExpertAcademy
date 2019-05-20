#include<stdio.h>
#define MAX 255

//��,��,��,�Ʒ�
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

char map[MAX][MAX];
int wolf, shape;
int n, m;

//������ ������� Ȯ�� �ϴ� �Լ�
int is_over(int x, int y)
{
	if (x >= 0 && y >= 0 && x < n && y < m)
		return 1;
	else
		return 0;
}

void dfs(int x, int y)
{
	//���� ���
	if (map[x][y] == 'o')
		shape++;
	//������ ���
	if (map[x][y] == 'v')
		wolf++;

	//�湮 ���� ��� x ǥ��
	map[x][y] = 'x';

	//4�������� �����̱� ���� �ݺ���
	for (int i = 0; i < 4; i++)
	{
		//��,��,��,�Ʒ� ���ʷ� �����δ�.
		int x_x = x + dx[i];
		int y_y = y + dy[i];

		//������ ����� �����鼭, ���� �ƴϸ鼭 �湮���� ���� ���̸�
		if (is_over(x_x, y_y) == 1 && map[x_x][y_y] != '#' && map[x_x][y_y] != 'x')
		{
			//��� ȣ�� �¿����Ʒ��� ���ʷ� �湮
			dfs(x_x, y_y);
		}


	}
}


int main()
{
	int shape2 = 0, wolf2 = 0;
	scanf("%d%d", &n, &m);

	//��,����,�� �Է�
	for (int i = 0; i < n; i++)
		scanf("%s", map[i]);


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			shape = wolf = 0;
			//�湮 ���� ���̸鼭 ���� �ƴ� ���
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