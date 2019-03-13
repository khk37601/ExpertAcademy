#include<stdio.h>
#include<string.h>
char chater[]={'A','B'};

int str_len(const char *c)
{
	int len = 0;
	while(*(unsigned char*)c !=NULL)
	{
		c++;
		len++;
	}

	return len;
}


int Test(char * str)
{
    int loop;
	int sum = 0,count =0;
	for(loop=0;loop<str_len(str);loop++)
	{
	    sum += str[loop]-'0';
		count++;
        if(sum>=10)
		{
			sum = (sum/10) + (sum%10);
			count++;
		}
	}

	return count;
}
int main()
{
	int TestCase;
	int loop;
	char ch[1001];

	scanf("%d",&TestCase);
	for(loop=0;loop<TestCase;loop++)
	{
	    scanf("%s",ch);
		if(Test(ch)%2==0)
			printf("#%d %c\n",loop+1,chater[0]);
		else
			printf("#%d %c\n",loop+1,chater[1]);
	}


	return 0;
}