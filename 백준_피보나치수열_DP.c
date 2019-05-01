#include<stdio.h>
#include<string.h>
/*
   * �޸����̼����� �Ǻ���ġ ���� ���ϱ�

   * ����Լ��� ���ϱ޼��� �ߺ��� ȣ���� ���̱� ����
*/
#define MAX 100
//�޸����̼� �޸�
int cach[MAX] = {1,1,};

int fibonacci(int n)
{
	// 1�� ���ų� ������� 
	if (n <= 1)
		return 1;
	else
	{
		//�޸����̼� �� ���� �ִ� ��� 
		// ���� �ִ� ��� �� fibonaaci�Լ��� �ߺ� ȣ�� �� �ʿ����
		// �޸𸮿� �ִ� ���� ���� �Ѵ�.
		if (cach[n] != 0)
			return cach[n];

		// ���� ���� �޸𸮿� ����.
		return cach[n] = fibonacci(n - 1) + fibonacci(n - 2);
	}

}
/*
              f(3)
        f(2)         f(1)
     f(1)  f(0)   

	 -> 0 ȣ�� �� :  1
	    1 ȣ�� �� :  2

	 ��Ģ�� �߰�
	 f(0) = f(0)
	 f(1) = f(1)
	 f(2) = f(1)+f(0)
	 f(3) = f(2)+f(1)
	 ......
	 ���� ���� �Ǵ� ���� �� �� �ִ�.
	       zero    one
	 f(0)   1       0
	 f(1)   0       1
     f(2)   1       1
     f(3)   1       2
	 f(4)   2       3
	 
	 N ���� 
	 zero ȣ�� Ƚ���� N-2 ��
	 one  ȣ�� Ƚ���� N-1 ��

*/



int main()
{
	int Testcase, N;
	scanf_s("%d", &Testcase);
	for (int i = 0; i < Testcase; i++)
	{
		scanf_s("%d", &N);
		if (N == 0)
			printf("1 0\n");
		else if (N == 1)
			printf("0 1\n");
		else
		{
			fibonacci(N);
			printf("%d %d \n", cach[N - 2],cach[N - 1]);
		}

		

	}

	return 0;
}