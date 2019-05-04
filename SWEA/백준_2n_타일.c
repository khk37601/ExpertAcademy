#include<stdio.h>

int cach[1001] = {0,1,2};

/*
 2*n 의 타일 채우기 
 
 2x1, 1x2 
 
 2x0 -> 0
 
 2x1
  _
 |_|   ->   1 가지
 |_| 
  
 2x2
  _  _
 |_||_|  -> 2 가지   
 |_||_|
 
 2x3 
        ->  3가지 

   도출 피보나치 수열과 똑같다. 
... N = (N-2) + (N-1)


 */


int DP(int n)
{
	//0일경우 
	if (n == 0)
		return 0;
	else
	{
		//해당 호출된 재귀가 이미 호출된 재귀 일 경우
		if (cach[n] != 0)
			return cach[n];
		// n-2+n-1 값을  cach[n] 삽입
		return cach[n] = (DP(n-2)+DP(n-1))%10007;
	}
}
int main()
{

	int N;
	scanf_s("%d", &N);
	printf("%d\n", DP(N));

}