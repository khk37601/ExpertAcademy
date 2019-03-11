#include<stdio.h>

int main( )
{
      int TestCase;
      int loop,loop2,N; 
      long double p = 0.0, sum =0.0;
      int money = 0;
      
     scanf("%d",&TestCase);
    for(loop=0;loop<TestCase;loop++)
    {
         scanf("%d",&N);
        for(loop2=0;loop2<N;loop2++)
        { 
           scanf("%llf %d",&p,&money);
           sum += p*money;
         }
         printf("#%d %llf\n",loop+1,sum);
        sum = 0.0;
    }
    
    
      return 0;
}