#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void memset_s(unsigned int * arr,int init, const int size)
{
	//초기화
	for (int loop = 0; loop < size; loop++)
		arr[loop] = init;
}
void input(int * arr, int k)
{
	int in;
	for (int loop = 0; loop < k; loop++)
	{
		scanf("%d",&in);
		//제출 한 사람은 1로 체크;
		arr[in]++;
	}

}
void check(const int * arr,const int n)
{
	for (int loop2 = 1; loop2<n + 1; loop2++)
		if (arr[loop2] == 0)
			printf(" %d", loop2);
	
}
int main()
{
	int TestCase, N, K;
	int loop;
	int *arr = NULL;
	scanf("%d", &TestCase);
	for (loop = 0; loop<TestCase; loop++)
	{
		scanf("%d%d", &N, &K);
		arr = (int*)malloc(sizeof(int)*N + 1);
		//메모리 초기화
		memset_s(arr, 0, sizeof(arr)*(N + 1));
		input(arr,K);
	
		printf("#%d", loop + 1);
		check(arr,N);
        printf("\n");
	}
	return 0;
}