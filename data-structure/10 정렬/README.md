# 정렬

정렬은 물건을 크기 순으로 오름차순이나 내림차순으로 나열하는 것 

정렬은 컴퓨터공학을 포함한 모든 과학기술 분야에서 가장 기본적이고 중요한 알고리즘 중 하나 

정렬은 자료 탐색에 있어서 필수적 (예) : 만약 영어사전에서 단어들이 알파벳 순으로 정렬되어 있지 않다면?

### 정렬의 대상

- 일반적으로 정렬하는 대상은 **레코드**(record)의 모임 
- 레코드는 **필드**(field)라는 작은 단위로 구성 
- **키(key) 필드**로 레코드와 레코드를 구별한다.
  - Primary key
  - Secondary key

![image](https://user-images.githubusercontent.com/68107000/99208698-99306d00-2804-11eb-81f9-39230e106c87.png)

### 정렬 알고리즘

- **모든 경우에 최적인 정렬 알고리즘은 없다. 각 응용 분야에 적합한 정렬 방법 사용해야 한다.** 
  - 레코드 수의 많고 적음 
  - 레코드 크기의 크고 작음 
  - Key의 특성(문자, 정수, 실수 등) 
  - 메모리 내부/외부 정렬 

- **정렬 알고리즘의 평가 기준**
  - 비교 횟수의 많고 적음 
  - 이동 횟수의 많고 적음

- **단순하지만 비효율적인 방법**
  - 삽입정렬, 선택정렬, 버블정렬 등
- **복잡하지만 효율적인 방법**
  - 퀵정렬, 힙정렬, 병합정렬 등 
- **내부 정렬(internal sorting)** 
  - 모든 데이터가 주기억장치에 저장되어있는 상태에서 정렬
- **외부 정렬(external sorting)**
  - 외부기억장치에 대부분의 데이터가 있고 일부만 주기억장치에 저장된 상태에서 정렬 – 병합정렬 기반(k-way merging) (생략)
- **정렬 알고리즘의 안정성(stability)**
  - 동일한 키 값을 갖는 레코드들의 상대적인 위치가 정렬 후에도 바뀌지 않음

## 1) 선택 정렬 - selection sort

**설명**

**정렬된 왼쪽 리스트와 정렬 안된 오른쪽 리스트 가정**

- 초기에는 왼쪽 리스트는 비어 있고, 정렬할 숫자들은 모두 오른쪽 리스트에 존재

**오른쪽 리스트에서 최소값 선택하여 오른쪽 리스트의 첫번째 수와 교환**

- 왼쪽 리스트 크기 1 증가
- 오른쪽 리스트 크기 1 감소 
- 오른쪽 리스트가 소진되면 정렬 완료

![image](https://user-images.githubusercontent.com/68107000/99208990-6044c800-2805-11eb-8795-5de25fac313b.png)

**pseudocode**

```c
selection_sort(A, n)
for i←0 to n-2 do
    least ← A[i], A[i+1],..., A[n-1] 중에서 가장 작은 값의 인덱스;
    A[i]와 A[least]의 교환;
    i++;
```

**C 구현**

```c
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
void selection_sort(int list[], int n) {
    int i, j, least, temp;
    for (i=0; i<n-1; i++) {
        least = i;
        for (j=i+1; j<n; j++) // 최소값 탐색
            if(list[j]<list[least]) least = j;
        SWAP(list[i], list[least], temp);
    }
}
```

**선택 정렬 복잡도 분석**

- 비교 횟수
  - (n - 1) + (n - 2) + … + 1 = n(n - 1)/2 ∈ **O(n^2)**
- 이동 횟수
  - 각 swap에 3번 : 총 **3(n - 1)**
- **전체 시간 복잡도: O(n^2)**
- 안정성을 만족하지 않음
  - 예) 3 3 1 5

## 2) 삽입 정렬

**설명**

**정렬되어 있는 앞 부분에 새로운 레코드를 올바른 위치에 삽입하는 과정 반복**

![image](https://user-images.githubusercontent.com/68107000/99598738-5d341c80-2a3d-11eb-8e09-420dbaade088.png)

![image](https://user-images.githubusercontent.com/68107000/100042301-86461a00-2e4e-11eb-8e4b-33588ef841e1.png)

**pseudocode**

```c
insertion_sort(A, n)
for i ← 1 to n-1 do
    key ← A[i];
    j ← i-1;
    while j≥0 and A[j]>key do
    	A[j+1] ← A[j];
    	j ← j-1;
    A[j+1] ← key
```

**C 구현**

```c
void insertion_sort(int list[], int n) {
    int i, j, key;
    for(i=1; i<n; i++){
        key = list[i];
        for(j=i-1; j>=0 && list[j]>key; j--) // 비교 횟수
        	list[j+1] = list[j]; // 레코드의 오른쪽 이동
        list[j+1] = key;
    }
}
```

**선택 정렬 복잡도 분석**

- **최선의 경우 O(n)** - 이미 정렬되어 있는 경우
  - **비교: n-1번 ㅡ> 왜냐면 두번째 for loop은 한 번만 실행되고 탈출하니까!**
- **최악의 경우 O(n^2)**
  - 모든 단계에서 앞에 놓인 자료 전부 이동
  - 비교: **O(n^2)** (![image](https://user-images.githubusercontent.com/68107000/99600063-00863100-2a40-11eb-8167-1edca8f430f6.png))
  - 이동(각 단계마다 i+2회 이동 i : 배열이동, 2 : key 복사): **O(n^2)** (![image](https://user-images.githubusercontent.com/68107000/99600084-08de6c00-2a40-11eb-81e3-2ad99c0c3737.png))
- **평균적인 경우 O(n^2)**
- 안정 정렬이다.
- 많은 이동이 필요해서 레코드가 클 경우 비효율적이다.
- 대부분 정렬되어 있으면 효율적이다.

## 3) 버블 정렬

**설명**

인접한 2개의 레코드의 키를 비교하여 순서대로 되어 있지 않으면 서로 **교환**

이러한 비교-교환 과정을 리스트의 왼쪽 끝에서 오른쪽 끝까지 반복(스캔)

![image](https://user-images.githubusercontent.com/68107000/100042355-9d850780-2e4e-11eb-9349-0a24f0666f92.png)

**pseudocode**

```c
BubbleSort(A, n)
for i←n-1 to 1 do
    for j←0 to i-1 do
    	j와 j+1번째의 요소가 크기 순이 아니면 교환
    	j++;
	i--;
```

**C 구현**

```c
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
void bubble_sort(int list[], int n) {
    int i, j, temp;
    for(i=n-1; i>0; i--){
        for(j=0; j<i; j++) // 앞뒤의 레코드를 비교한 후 교환
        	if(list[j]>list[j+1])
        		SWAP(list[j], list[j+1], temp);
    }
}
```

**개선된 버블정렬 C구현**

```c
배열의 뒷부분부터 인접한 원소를 비교하여 작은 원소를 앞으로 보내는 개선된 버블 정렬 알고리즘
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
void improved_bubble_sort(int list[], int n) {
    int i, j, temp, flag = TRUE;
    j = 0;
    while ((j<n-1) && flag) {
        flag = FALSE;
        for (i=n-1; i>j; i--)
            if (list[i] < list[i-1]) {
            	swap(list[i], list[i-1], temp);
            	flag = TRUE;
        	}
        j++;
    }
} 
```



**선택 정렬 복잡도 분석**

- **비교 횟수(최선, 평균, 최악의 경우 모두 일정)**
  - **O(n^2)** (![image](https://user-images.githubusercontent.com/68107000/99600063-00863100-2a40-11eb-8167-1edca8f430f6.png)
  - 개선된 버블정렬의 경우는 최선의 경우 O(n)
-  **이동 횟수**
  - 역순으로 정렬된 경우(최악의 경우) :이동 횟수 = 3 * 비교 횟수
  - 이미 정렬된 경우(최선의 경우) : 이동 횟수 = 0 
  - 평균의 경우 : O(n^2)
- 레코드의 이동 과다
  - 이동연산은 비교연산보다 더 많은 시간이 소요됨

------

위 3개의 정렬은 모두 worst와 평균적 모두 O(n^2)이다.

## 4) 병합 정렬

**설명**

- 리스트를 두 개의 균등한 크기로 **분할**하고 분할된 부분리스트를 **재귀적으로 정렬**한 후, 정렬된 두 개의 부분리스트를 **병합**하여 전체 리스트를 정렬함
- **분할 정복(divide-and-conquer) 설계방식** 
  - 문제를 작은 2개의 부분문제로 분할하고 각 문제를 해결한 다음, 결과를 모아서 원래의 문제를 해결하는 전략
  - 분할된 부분문제가 아직도 해결하기 어렵다면(즉, 충분히 작지 않다면) 분할정복 방법을 다시 적용(재귀호출 이용)

1.**분할(Divide)** : 배열을 같은 크기의 2개의 부분배열로 분할 

2.**정복(Conquer)** : 부분배열을 정렬한다. 부분배열의 크기가 충분히 작지 않으면 재귀호출을 이용하여 다시 분할정복기법 적용 

3.**병합(Combine)** : 정렬된 두 부분배열을 하나의 배열에 통합

**병합 정렬의 전체 과정**

![image](https://user-images.githubusercontent.com/68107000/99602274-902dde80-2a44-11eb-802e-73a3ba7fb83a.png)

**pseudocode**

```c
merge_sort(list, left, right)
if left < right  // 정렬할 데이터의 개수가 2개 이상이면
    mid = (left+right)/2; // 중간 위치 계산
    merge_sort(list, left, mid); //  왼쪽 부분배열 병합 정렬 : merge_sort 함수 재귀 호출
    merge_sort(list, mid+1, right); // 오른쪽 부분배열을 병합 정렬 : merge_sort 함수 재귀 호출
    merge(list, left, mid, right); // 오른쪽 부분배열을 병합 정렬 : merge_sort 함수 재귀 호출
```

**병합 과정**

![image](https://user-images.githubusercontent.com/68107000/99602917-ab4d1e00-2a45-11eb-8a3f-4b99bb1a1039.png)

**pseudocode**

```c
merge(list, left, mid, right):
    // 2개의 인접한 배열 list[left..mid]와 list[mid+1..right]를 병합
	i←left; 	j←mid+1;	 k←left;
    // 1. 분할 정렬된 list의 합병
	while i ≤ mid and j ≤ right do
        if(list[i]<list[j])
            then sorted[k]←list[i];
            k++; i++;
        else
            sorted[k]←list[j];
            k++; j++;
	// 2.
    원소가 남아있는 부분배열을 sorted로 복사한다;
	// 3.
    sorted를 list로 복사한다;
```

**C로 전체 구현**

```c
int sorted[MAX_SIZE]; // 추가 공간이 필요


// i는 정렬된 왼쪽리스트에 대한 인덱스
// j는 정렬된 오른쪽리스트에 대한 인덱스
// k는 정렬될 리스트에 대한 인덱스
void merge(int list[], int left, int mid, int right) {
    int i, j, k, l;
    i = left; j = mid + 1; k = left;
    // 분할 정렬된 list의 합병
    while (i <= mid && j <= right) {
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }

    // 남아 있는 레코드의 일괄 복사
    if (i > mid) // 왼쪽리스트는 이미 다 읽은 경우
        for (l = j; l <= right; l++)
            sorted[k++] = list[l];
    else // 오른쪽리스트는 이미 다 읽은 경우
        for (l = i; l <= mid; l++)
            sorted[k++] = list[l];

    
    // 배열 sorted[]의 리스트를 배열 list[]로 복사
    for (l = left; l <= right; l++) list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right) {
    int mid;
    if (left < right) {
        mid = (left + right) / 2; // 리스트의 균등분할
        merge_sort(list, left, mid); // 부분리스트 정렬
        merge_sort(list, mid + 1, right);//부분리스트 정렬
        merge(list, left, mid, right); // 합병
    }
}
```

**병합 정렬 복잡도 분석**

- **비교 횟수**
  -  ![image](https://user-images.githubusercontent.com/68107000/100046318-914f7900-2e53-11eb-967a-862f81d64bfc.png)
  -  크기n (= 2^k이라고 가정)인 리스트를 정확히 균등 분배한다면 lg_2(n)번의 패스
  - 2* (n/2) + 4*(n/4)… + 2k (n/2^k ), k = log_2(n) ⇒ n+n+⋯+n, K회 더함 ⇒ **nlgn**
- **이동 횟수** 
  - 레코드의 이동이 각 패스에서 2n번 발생하므로 **전체 레코드의 이동은 2n*lg_2(n)번 발생** (즉, sorted로 한번, 다시 리스트로 한번 이동)
  - 레코드의 크기가 큰 경우에는 매우 큰 시간적 낭비 초래 
  - 레코드를 연결 리스트로 구성하여 병합 정렬할 경우, 
    - 링크 인덱스만 변경되므로 데이터의 이동은 무시할 수 있을 정도로 작아짐
    - 따라서 크기가 큰 레코드를 정렬할 경우, 다른 어떤 정렬 방법보다 매우 효율적 
    - 하지만 가운데 위치를 찾는 것이 문제가 되므로 잘 사용하지 않는다.

- 최선, 평균, 최악의 경우 큰 차이 없이 **O(nlgn)의 복잡도**
- **안정적**이며 데이터의 초기 분산 순서에 영향을 덜 받음

## 5) 퀵 정렬

**설명**

- 평균적으로 가장 빠른 정렬 방법으로 알려져 있음 
- 분할정복 기법 
- **축값(pivot, 또는 피벗)**을 중심으로 하나의 리스트를 축값보다 작은 부분리스트와 축값보다 큰 부분리스트로 분할하고, 각 부분리스트를 다시 퀵정렬함(재귀호출)

![image](https://user-images.githubusercontent.com/68107000/100047481-e7252080-2e55-11eb-9ede-7aef599716e7.png)

![image](https://user-images.githubusercontent.com/68107000/100047791-b0033f00-2e56-11eb-800f-c96bc463b81f.png)

**분할 과정**

![image](https://user-images.githubusercontent.com/68107000/100048580-7c291900-2e58-11eb-9f6a-23088dbbce44.png)

- **축값(pivot) : 리스트의 가장 왼쪽 원소라고 가정**
- 두 개의 인덱스 변수 low와 high를 사용한다. 
- low 위치의 값이 축값보다 작으면 통과, 크면 정지
- high 위치의 값이 축값보다 크면 통과, 작으면 정지
- 정지된 위치의 두 원소를 교환
- low와 high가 교차하면 종료

**C로 전체 구현**

```c
void quick_sort(int list[], int left, int right) {
    if ( left < right ) { // 정렬할 범위가 2개 이상의 데이터이면
        // 1. partition 함수 호출로 축값을 기준으로 2개의 리스트로 분할 (partition 함수의 반환 값이 축값의 위치)
        int q = partition(list, left, right);
        // 2. left에서 축값 바로 앞까지를 대상으로 재귀 호출(축값 제외)
        quick_sort(list, left, q-1); 
        // 3. 축값 바로 다음부터 right까지를 대상으로 재귀 호출(축값 제외)
        quick_sort(list, q+1, right); 
    }
}

int partition(int list[], int left, int right) {
	int pivot, temp;
	int low, high;
	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do
			low++;
		while (low <= right && list[low] < pivot);
		do
			high--;
		while (high >= left && list[high] > pivot);
		if (low < high) SWAP(list[low], list[high], temp);
	} while (low < high);
	SWAP(list[left], list[high], temp);
	return high;
}
```

**퀵 정렬 복잡도 분석**

- **최선**의 경우(거의 균등하게 부분리스트로 분할되는 경우)

  - 패스 수 : log_2(n)

    ![image](https://user-images.githubusercontent.com/68107000/100178760-f2408500-2f17-11eb-8324-752543f74f08.png)

  - 각 패스 안에서의 비교횟수 : n 

  - 총 비교횟수 : nlgn

  - 총 이동횟수 : 비교횟수에 비하여 적으므로 무시 가능

- **최악**의 경우(극도로 불균등하게 부분리스트로 분할되는 경우) 

  - 패스 수 : n 

    ![image](https://user-images.githubusercontent.com/68107000/100178782-fe2c4700-2f17-11eb-82bb-bddf1eea09a1.png)

  - 각 패스 안에서의 비교횟수 : n

  - 총 비교 횟수 : n^2 

  - (예) 이미 정렬된 리스트를 정렬할 경우

    ![image](https://user-images.githubusercontent.com/68107000/100178883-359af380-2f18-11eb-8e2b-35b8345ef9ef.png)

중앙값(median)을 축값으로 선택하면 불균등 분할을 완화할 수 있다.

일반적으로 리스트의 왼쪽, 오른쪽, 중간값 3개의 원소 중 크기 순으로 중간값을 선택하는 방법(median of three)이 많이 사용된다.

## 6) 힙 정렬 - Heapsort

**설명**

- 힙을 이용한 정렬(오름차순 정렬시: 최대 힙 사용) 
  - 제 1단계 : 정렬해야 할 n개의 원소들을 최대 힙으로 구성 
  - 제 2단계 : 루트(최대값)와 가장 마지막 원소를 교환한 다음, 마지막 원소(최대값)를 제외하고 downheap을 반복적으로 수행 
- n개의 원소를 최대 힙으로 구성하기 위해 걸리는 시간은 O(n) 만큼 소요되고, downheap 연산을 n − 1 번 수행해야 하므로 O(nlogn) 시간이 걸림. 따라서 전체적으로 O(nlogn) 시간이 걸린다.
- 이와 같이 **힙구조를 사용하는 정렬 알고리즘**을 **힙 정렬**이라고 한다.

이와 관련된 자세한 내용을 적은 링크이다. #(링크 추가 예정 - 분명 배웠는데 왜 관련 내용이 없지???)

1. 힙구성

   ![image](https://user-images.githubusercontent.com/68107000/100177676-e0f67900-2f15-11eb-8ba8-a37716c4b481.png)

2. 힙정렬

   ![image](https://user-images.githubusercontent.com/68107000/100177937-53ffef80-2f16-11eb-866f-d2a362388779.png)

   ![image](https://user-images.githubusercontent.com/68107000/100177955-5c582a80-2f16-11eb-9dce-8ac404af1b5e.png)

## 정렬 알고리즘의 비교

![image](https://user-images.githubusercontent.com/68107000/100042463-d58c4a80-2e4e-11eb-8430-b900708a4301.png)

쉘 정렬과 기수 정렬은 생략한다. 참고로 d는 number of digits를 의미한다. (4862의 d=4)

삽입 정렬에서 최선의 경우는 정렬이 되어 있을 때이다.

퀵 정렬에서 최악은 경우는 피벗값에 계속해서 극단적인 값(가장 작은 값 또는 가장 큰 값)이 선택될 때이다.



### 정수 60000개로 실험한 결과

![image](https://user-images.githubusercontent.com/68107000/100178028-801b7080-2f16-11eb-88d3-1858e786c513.png)

