#include<stdio.h>

int cach[1001] = {0,1,2};

/*
 2*n �� Ÿ�� ä��� 
 
 2x1, 1x2 
 
 2x0 -> 0
 
 2x1
  _
 |_|   ->   1 ����
 |_| 
  
 2x2
  _  _
 |_||_|  -> 2 ����   
 |_||_|
 
 2x3 
        ->  3���� 

   ���� �Ǻ���ġ ������ �Ȱ���. 
... N = (N-2) + (N-1)


 */


int DP(int n)
{
	//0�ϰ�� 
	if (n == 0)
		return 0;
	else
	{
		//�ش� ȣ��� ��Ͱ� �̹� ȣ��� ��� �� ���
		if (cach[n] != 0)
			return cach[n];
		// n-2+n-1 ����  cach[n] ����
		return cach[n] = (DP(n-2)+DP(n-1))%10007;
	}
}
int main()
{

	int N;
	scanf_s("%d", &N);
	printf("%d\n", DP(N));

}