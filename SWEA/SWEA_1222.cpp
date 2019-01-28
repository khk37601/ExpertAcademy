#include<stdio.h>
#include<stdlib.h>
#define MAX 300
 
int arr2[MAX];
int top;
 
void init()
{
    top = -1;
}
 
int is_full()
{
    return top == MAX; 
}
 
int Empty()
{
    return top == -1;
}
 
void add(int number)
{
     
    if(!is_full())
    {   
      arr2[++top]= number;
    }
    else
    {
         printf("가득 찼습니다.");
         return;   
    }
 
 
}
int pop()
{
    return arr2[top--];
}
 
 
int main()
{
    char * arr = NULL; 
    int sum =0,len;
    init();
 
    for(int i=0;i<10;i++)
    {
        scanf("%d",&len);
        arr = (char*)malloc(sizeof(char)*len+1);
        scanf("%s",arr);
 
         for(int j=0;j<len;j++)  
         {
             /*연산 기호 + 아닐 경우  '0'를 빼주어 문자를 int로 변경*/
            if(arr[j] !='+') add((arr[j]-'0'));
 
            if(!Empty())
               sum += pop();
 
         }
         printf("#%d %d\n",i+1,sum);
         /*합 초기화 */
         sum =0;
    }
     
     
 
 
    return 0;
 
}
