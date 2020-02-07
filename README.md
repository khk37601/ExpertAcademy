## 알고리즘 공부


#### 알고리즘 이란 ? 
 >  문제를 해결하기 위한 절차나 방법.



### 좋은 알고리즘은 무엇인가 ?
 1. ```정확성``` : 얼만큼 정확하게 동작하는가?  
 2. ```작업량 ```: 적은 연산으로 원하는 결과를 얻는가?
 3. ```메모리 사용량 ```:  적은 메모리를 사용하는가?
 4. ```단순성``` : 알고리즘이 단순한가?
 5. ```최적성``` : 더 이상 개선할 여지 없이 최적한가?
 
 다섯가지를 만족한는 것이 좋은 알고리즘이라고 할 수 있습니다.
 
### 알고리즘필요성.
 
 * 1 ~ 100의 합 구하는 프로그램이 있다고 가정 합니다.
 
 첫 번째 방법은 단순 반복문을 쓰는 방법.
 두 번째 방법은 가우스 합을 이용한 방법.
 
 
 첫 번째는  ```O(n)```의 시간 복잡도를 가자게 되고, 두 번째 방법은 ```O(1)```의 시간 복잡도를 가지게 되므로 
 ```두 번째 알고리즘```이 좋다고 볼 수 있습니다. (숫자 커질수록)
 
 
 
 ### 알고리즘 성능 분석
 
 * 실제 걸리는 시간 측정 (컴퓨터 환경마다 다르게 측정됨)
 
 * ```실행되는 명령문의 개수를 계산```
 
* 빅오 표기법 사용.
  가장 큰 영향력을 주는 n에 대한 항만을 표시
  계수는 생략 표시
```
Ex) O(2n+1) = O(2n) = O(n)
    O(2n^2+10n+100) = (n^2) 
	  O(4)  =O(1)
````


#### 완전검색 방법
> 문제의 해법으로 생각할 수 있는 모든 경우의 수를 나열해보고 확인하는 기법.

	부르트포커스 기법

	모믄 경우의 수를 테스트한 후 최종 해법을 도출함.

	일반적으로 경우의 수가 상대적으로 작을 때 유용함.

	모든 경우의 수를 생성하고 테스트하기 때문에 수행 속도는 느리지만 해답을 찾아내지 못할 확률이 작음.

	주어진 문제를 풀 때 우산 완전 검색으로 접근하여 해답을 도출한 후, 성능 개선을 위해 다른 알고리즘을 사용하고 해답을 확인하는 것이 바람직함.

ex) baby- gin
```
0 ~ 9 까지의 숫자에서
6장을 뽑았을 때 3장의 카드가 연속적인 번호를 갖는 경우를 Run 3장의 카드가 동읿나번호를 갖는 경우를 트리플이라고 함.
런과 트리플로만 이루어진 것을 베이비 진이라고 한다

```
#### 그리디 알고리즘

최적의 해를 구하는 가장 간단한 방법.
여러 경우 중 하나를 결정해야 할 때마다 그 순간에 최적이라고 생각하고 나가는 방식.

그리디 알고리즘은 반드시 해를 찾는다는 보장은 없다.

-> 배낭 문제, 동전 거스름돈 

#### 이분 탐색(이진 탐색)


순차적인 검색 방법이 아닌 탐색범위를 절반으로 줄이면서 탐색하는 방법으로
```O(logn)```의 시간 복잡도를 가지게 된다.

(단. 정렬된 배열에서만 가능하다.)


#### 정렬 알고리즘

* 버블정렬

원소를 하나씩 비교하면서 정렬하는 방법으로 직관적이고 구현이 간단한 방법입니다.

배열의 크기가 클수록 비효율적인 알고즘입니다.

시간 복잡도는 ```O(n^2)```를 가집니다.

```
def bublesort(arr):
   length = len(arr)

   for i in range(length):
   	# 벙위를 줄여 나가는 방법.
   	for j in range(length-i-1):
		if arr[j] > arr[j+1]:
			arr[j], arr[j+1] = arr[j+1], arr[j]

   return arr

````


* 퀵정렬

이름부터 빠른정렬입니다. pivot기준으로 분할 하여 정렬 하는 방법입니다.

최선의 경우 ```O(nlogn)```의 시간 복잡도를 가지게 되지만, 

내림차순아나 오름차순으로 정렬되어있는 경우 ```O(n^2)```시간 복잡도를 가지게 됩니다.

```
def quitsort(arr):

	if len(arr) <= 1:
	    return arrr
	
	pivot = arr[0]
	
	# 정렬.
	loss = [i for i in arr if i < pivot]
	hight = [i for i in arr if i > pivot]
	
	return quitsort(loss) + [pivot] + quitsort(hight)
```


* 병합정렬

분할정복으로 정렬하는 알고리즘입니다. 
퀵정렬과 달리 항상 시간복잡도 O(nlogn)를 보장합니다.

```

def mergesort(arr):
   	
	if len(arr) > 1:
	   
	   left = arr[:mid]
	   right = arr[mid:]
	   
	   l = mergesort(left) 
	   r = mergsort(right)
	   
	   return sort(l, r)
	 else:
	   return arr
	 
	 
     def sort(left, right):
     	
	left_index = 0
	right_index = 0
	arr = []
	
	while letf_index < len(left) and right_index < len(right):
		
		if left[left_index] < right[right_index]:
			arr.apppend(left[left_index])
			left_index +=1
		else:
			arr.apppend(right[right_index])
			right_index +=1
		
	# 남아 있는 원소를  처리하기 위함.
	while letf_index < len(left):
		arr.append(left[left_index])
		left_index += 1
	
	while right_index < len(right):
		
		arr.append(right[rigth_index])
		right_index += 1
	   
	return arr
	
```
##### *파이썬 내장함수 정렬 sort()는 항상 O(nlogn)의 시간 복잡도를 보장합니다. 따라서, 직접 구현하는거 보다 좋은 성능을 보장합니다.


##### 너비 우선 탐색 (BFS) VS 깊이 우선 탐색 (DFS)

````
graph ={

         'A': ['B', 'C'],
         'B': ['A'],
         'C': ['A', 'B']
}

"""

    A---|
    |   |
    B   |
    |   |
    C --|

"""

````

자료구조 그래프를 순회하는 두 가지 방법입니다.

```너비 우선 탐색 일명, BFS```는  같은 레벨에 있는 노드를 모드 방문 후 에 다음 레벨로 넘어가면서 더 이상 탐색 할 노드가 없을 때 까지 탐색 하는 
알고리즘 방법입니다. 

자료구조 큐를 사용해서 방문을 합니다.

```
def bfs(x):
   
   queue = []
   viusit = []
   queue.append(x)
   
   while queue:
   	n = queue.pop(0)
	# 방문 한 적이 없는 경우
	if not n in visit:
		visit.append(x)
		queue += graph[x]
  
  return visit
	
=> 결과 A->B->C

```


```깊이 우선 탐색 일명, DFS```는 다음 레벨의 노드가 없을 때까지 깊게 들어가면서 탐색하는 알고리즘 입니다.

자료구조 스택을 사용해서 방문 합니다.


```
def dfs(x):
   
   stack = []
   visit = [] 
   stack.append(x)
   
   while stack:
   	n = stack.pop()
   	if not x in visit:
	   visit.append(x)
	   stack += graph[x]
   
   return vistit	   
   
=> 결과  A -> c -> B	

```

#### 동적계획법 

큰 문제를 작은 문제로 나눠서 푸는 알고리즘입니다. 우선 분할 정복과 비슷해 보일 수 있습니다.

하지만 동적계획법은 ```이전에 계산된 부분을 다시 사용```한다는 점에서 차이점이 존재 합니다.

이러한 방법을 메모이제이션을 이용하여 문제를 해결 한다고 볼 수 있습니다.

가장 대표적인 피보나치 수열.

```
# 일반적인 피보나치 수열 구하는 함수.

def fibonacci(n):
   if n <=2:
   	return 1
   
   return fibonacci(n-1) + fibonacci(n-2)

# 이렇게 구하면 한번 호출된 재귀를 다시 호출 하여 시간복잡도를 많이 높이이는 요소가 됩니다.

# 이런 문제를 해결 해주기 위해서 메모이제이션 방법을 이용합니다. 
# 재귀방법으로 구한 피보나치 수열.
memory =[-1] * n
memory[0] = 1
memory[1] = 1
memory[2] = 3

def fibonacci(n):
    if n <= 2:
    	return 1
    # 이전에 값이 있는 확인 하여 이미 호출한 재귀를 재호출 하는것을 방지.
    if memory[n] != -1:
       return momery[n]
       
    memory.append(memory[n-1]+memory[n-2])
   
    return fibonacci(n-1) + fibonacci(n-2)
    

# 반복문으로 구한 피보나치 수열 

def fibonacci(n):
   
   memory = [1, 1, 3]
   
   for i in range(3, n+1):
   	memory.append(memory[n-1] + memory[n-2])

   return memory[n-1]

# 반복으로 사용해서 Stackoverflow를 방지 할 수 있습니다.

```

##### 스택

스택의 자료구조 형태는 FILO(first-in Last-out)이다. 
```
 예제) A ,B, C 가 순서대로 들어 왔다고 가정 한다.
  ------------------
   A |  B   |  C  |
  -------------------
  나오는 순서는 c->b->a로 나오게 된다.
   
   -> 브라우저 뒤로가기에 쓰이는 자료구조 이다.
  ``` 
   
   
#### 큐

큐의 자료구조 형태는 FIFO(first-in first-out)이다. 
```
 예제) A ,B, C 가 순서대로 들어 왔다고 가정 한다.
  ------------------
   A |  B   |  C  |
  -------------------
  나오는 순서는 a->b->c 로 나오게 된다.
   
```
 
