#include<stdio.h>
#define MAX 20

char list[MAX];
int stack[MAX];
int top = -1;
/*
 1 ~ 10
 1제곱 S  2제곱 D  3 제곱T

 * 두배 
 # 마이너스

*/

//문자열 길이 구하는 함수
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
		//*스타상은 바로 이전값 까지만 영향을 미친다.
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
			//10인 경우 범위가 1 ~10 까지 이기 때문.
			if (list[i - 1]-'0' >= 0 && list[i - 1]-'0' <= 9)
				//10 으로 설정
				stack[top ] = 10;
			else
				//단일 정수 일 경우
				stack[top += 1] = list[i]-'0';
		}
		else
		{
			//S D T * # 일경우
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


