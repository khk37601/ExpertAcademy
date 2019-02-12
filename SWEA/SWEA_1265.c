#include<stdio.h>

long long Max_s(int n, const int p)
{
	int loop;
	long long sum =1,quotient = 0;
	for(loop=p;loop>1;loop--)
	{
		/*
		 20,5
		 5/20 ...4 ... 4/16 ...4 ... 3/12 ...
		*/
	     quotient = n/loop;
		 n -= quotient;
		 sum *=quotient;
	}
	
	sum *= n;
	return sum;
}
int main()
{
	int TestCase,loop;
	int N,P;

	scanf("%d",&TestCase);

	for(loop=0;loop<TestCase;loop++)
	{
        scanf("%d%d",&N,&P);
		printf("#%d %lld",loop+1,Max_s(N,P));
	}


	return 0;
}