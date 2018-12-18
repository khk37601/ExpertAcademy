## 달팽이 
```
#include<iostream>
using namespace std;
/*
   00 01 02 03 04
   10 11 12 13 14
   20 21 22 23 24
   30 31 32 33 34

   초기화 순서
   1)행 초기화
   2)열 초기화
   3)(1,2 -> 한번) 반복 '초기화 개수는 하나씩 줄어든다.'
   4)규칙
     0 행을 초기화  -> 0행4열 -> 4열의 마지막 열값 기준으로 행값만1씩 증가 시켜 4열 초기화
	 1 행,5 열을 초기화완료 -> 4 열기준으로 마지막 행값 기준으로 열값마 1씩 감소 
	  반복 ....

*/

int main()
{
   int size;
   int keypoint2 = 1;
   int row   = 0;
   int column = -1;
   int number = 1;
   int T;//Testcase
   int **arr=NULL; 

    cin>>T;

	for(int loop=0;loop<T;loop++)
	{  
		cin >> size;
		/* 2차원 배열 */
		arr = new int*[size];
   
		for(int k=0;k<size;k++)
			arr[k] =new int[size];
  
		int tmp_size = size;
        
		while(tmp_size >= 0)
		{
			/*행*/
			for(int i=0;i<tmp_size;i++)
			{
				 column +=keypoint2; 
				 arr[row][column] = number++;
			}
			/* 초기화 해야할  개수가 줄어든다. */
			 tmp_size--;

			/*열 */
			for(int j=0;j<tmp_size;j++)
			{
				 row +=keypoint2; 
				 arr[row][column] = number++;
			}

			/*방향 전환*/
			keypoint2 *=-1;
   
		 }//while_end

		 /*다시 초기화 행렬*/
		 row    =  0;
		 column = -1;
	     number =  1;

		 cout<<"#"<<loop+1<<endl;
		   /* 출력 */
		   for(int i=0;i<size;i++)
		   {
			   for(int j=0;j<size;j++)
			   {
				   cout<<arr[i][j]<<" ";
			   }
			   cout<<endl;
		   }
		
	}

		   


}
```
