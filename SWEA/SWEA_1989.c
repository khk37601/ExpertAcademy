#include<stdio.h>
#define Max 1000


int main()
{
	int n,i,j,len=0;
    char arr[Max];
	int check[Max]={0,};

	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		scanf("%s",arr);

		//입력 문자 길이
		for(j=0;arr[j]!=NULL;j++)
			++len;

		for(j=0;j<len/2;j++)
		{
		  
		   if(arr[j] == arr[len-j-1])
			   check[i] = 1;
		   else
			   check[i] = 0;
		    

		}

		len =0;
	
	}


	for(i=0;i<n;i++)
		printf("#%d %d\n",i+1,check[i]);




	return  0;  
}