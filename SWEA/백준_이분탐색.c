#include<stdio.h>
#include<stdlib.h>

void sort(int *list, int left,int right)
{
   int l = left;
   int r = right;
   int tmp =-1;
   int pivot = (left+right)/2;
  
   if(l>=r)return;

   while(l <=r)
   {
       while(list[l]< list[pivot])
	       l++;
       while(list[r]>list[pivot])
	       r--;
    
       if(l <=r)
       { 
	   if(l != r)
           {
		tmp    = list[l];
		list[l] = list[r];
	        list[r] = tmp;	
	   }
 
             l++;r--;
       }

   }

    if(left <r)
	 sort(list,left,r);
    if(l<right)
	    sort(list,l,right);

}

int serch(int *list, int left,int right,int target)
{
  
   int mid = (left+right)/2;
 
   if(left>right)
	   return 0;

   if(target == list[mid])
	   return 1;
   
   else if(target < list[mid])
       serch(list,left,mid-1,target);
   else if(target > list[mid])
        serch(list,mid+1,right,target);
    

}


int main()
{
   int N,M,Ms,loop;
   int * N_list = NULL;

   scanf("%d",&N);
   N_list = (int*)malloc(sizeof(int)*N);
   for(loop=0;loop<N;loop++)
	   scanf("%d",&N_list[loop]);

   sort(N_list,0,N-1);
   //printf("%d",N_list[0]);
   
   scanf("%d",&M);
   for(loop=0;loop<M;loop++)
   {
       scanf("%d",&Ms);
       printf("%d\n",serch(N_list,0,N,Ms));
   }
   	   

   return 0;
}
