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

/*���ڿ� ��*/
int str_cmp(const char*a1,const char *a2)
{
   int i = 0;
    /* */
    while(!(i=*(unsigned char*)a1 - *(unsigned char*)a2) && *a2)
	{
		++a1;++a2;
	}
	/*������ ��ū ���*/
	if(i < 0)
		i = -1;
	/*���� ��ū ���*/
	else if(i > 0)
		i = 1;

	return i;
}