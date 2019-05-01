#include<stdio.h>
#include<string.h>
/*
   * 메모제이션으로 피보나치 수열 구하기

   * 재귀함수의 기하급수의 중복의 호출을 줄이기 위함
*/
#define MAX 100
//메모제이션 메모리
int cach[MAX] = {1,1,};

int fibonacci(int n)
{
	// 1과 같거나 작은경우 
	if (n <= 1)
		return 1;
	else
	{
		//메모제이션 에 값이 있는 경우 
		// 값이 있는 경우 또 fibonaaci함수를 중복 호출 할 필요없이
		// 메모리에 있는 값일 참조 한다.
		if (cach[n] != 0)
			return cach[n];

		// 현재 값을 메모리에 삽입.
		return cach[n] = fibonacci(n - 1) + fibonacci(n - 2);
	}

}
/*
              f(3)
        f(2)         f(1)
     f(1)  f(0)   

	 -> 0 호출 수 :  1
	    1 호출 수 :  2

	 규칙성 발견
	 f(0) = f(0)
	 f(1) = f(1)
	 f(2) = f(1)+f(0)
	 f(3) = f(2)+f(1)
	 ......
	 값이 도출 되는 것을 볼 수 있다.
	       zero    one
	 f(0)   1       0
	 f(1)   0       1
     f(2)   1       1
     f(3)   1       2
	 f(4)   2       3
	 
	 N 개의 
	 zero 호출 횟수는 N-2 값
	 one  호출 횟수는 N-1 값

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