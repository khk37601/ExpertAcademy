#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

/*
�ƽ�Ű �ڵ�
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
		//���� �պκи� �ƽ�Ű�ڵ�� ����
		if (name[0] >= 97 && name[0] <= 122)
			//-97�� ���� ��Ģ������ Ƚ�� ����
			//(97-97)a -> 0 , b(98-97) ->1 .........
			list[name[0] - 97]+=1;
		
	}

	for (int loop = 0; loop < 27; loop++)
	{
		if (list[loop] >= 5)
		{
			printf("%c", 97 + loop);
			//�ϳ��� 5�� �Ѵ´� �� trueüũ
			is_true = 1;
		}
	}
	//5�� �Ѵ� ���� ������ false
	if (is_true == 0)
		puts("PREDAJA");




	return 0;
}