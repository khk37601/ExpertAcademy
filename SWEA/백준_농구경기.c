#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

/*
아스키 코드
97 ~ 122
*/

int main()
{
	int TestCase,is_true=0;
	int list[27] = {0,};
	char name[31];


	scanf("%d", &TestCase);
	for (int loop = 0; loop <TestCase; loop++)
	{
		scanf("%s", name);
		//제일 앞부분만 아스키코드로 구별
		if (name[0] >= 97 && name[0] <= 122)
			//-97를 빼서 규칙적으로 횟수 증가
			//(97-97)a -> 0 , b(98-97) ->1 .........
			list[name[0] - 97]+=1;
		
	}

	for (int loop = 0; loop < 27; loop++)
	{
		if (list[loop] >= 5)
		{
			printf("%c", 97 + loop);
			//하나라도 5가 넘는다 면 true체크
			is_true = 1;
		}
	}
	//5가 넘는 숫자 없으면 false
	if (is_true == 0)
		puts("PREDAJA");




	return 0;
}