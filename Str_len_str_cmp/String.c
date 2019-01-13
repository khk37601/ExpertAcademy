#include "S_string.h"

int str_len(const char * arr)
{
	int  len = 0;
	while(*(unsigned char*)arr != NULL)
	{
		++arr;
		++len;
	}

	return len;
}

/*문자열 비교*/
int str_cmp(const char*a1,const char *a2)
{
   int i = 0;
    /* */
    while(!(i=*(unsigned char*)a1 - *(unsigned char*)a2) && *a2)
	{
		++a1;++a2;
	}
	/*오른쪽 더큰 경우*/
	if(i < 0)
		i = -1;
	/*왼쪽 더큰 경우*/
	else if(i > 0)
		i = 1;

	return i;
}