#include<stdio.h>
#define MAX 20

char list[MAX];
int stack[MAX];
int top = -1;
/*
 1 ~ 10
 1���� S  2���� D  3 ����T

 * �ι� 
 # ���̳ʽ�

*/

//���ڿ� ���� ���ϴ� �Լ�
int len(const char * str)
{
	int lens = 0;
	while (*(unsigned char*)str != NULL)
	{
		str++;
		lens++;
	}

	return lens;
}

void poow(char c)
{
	int s = stack[top];
	if (c == 'T')
		stack[top] = s*s*s;
	else if (c == 'D')
	  stack[top] = s*s;
	else if (c == '*')
	{
		int tmp = top;
		//*��Ÿ���� �ٷ� ������ ������ ������ ��ģ��.
		for (int i=0;i<2;i++)
		{
			int s1 = stack[tmp];
			stack[tmp] = s1 * 2;
			tmp--;
		}
	}
	else if (c == '#')
	{
		int num = stack[top];
		stack[top] = num*(-1);
	}
}

int main()
{
	int answer = 0;
	int is_ten = 0;
	scanf_s("%s", &list,sizeof(list));
	int lens = len(list);

	for (int i = 0; i < lens; i++)
	{
		if (list[i] != 'S' && list[i] != '*' && list[i] != '#' && list[i] != 'D' && list[i] != 'T')
		{
			//10�� ��� ������ 1 ~10 ���� �̱� ����.
			if (list[i - 1]-'0' >= 0 && list[i - 1]-'0' <= 9)
				//10 ���� ����
				stack[top ] = 10;
			else
				//���� ���� �� ���
				stack[top += 1] = list[i]-'0';
		}
		else
		{
			//S D T * # �ϰ��
			poow(list[i]);
		}
	}
	
	for (int i = 0; i <=top; i++)
	{
		//printf("%d ", stack[i]-'0');
		answer += stack[i];
	}

	printf("%d\n", answer);

	return 0;
}


