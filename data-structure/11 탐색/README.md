# 탐색(Searching, 검색)

## 탐색의 개념

- 여러 개의 자료 중에서 원하는 자료를 찾는 작업 
- 컴퓨터가 가장 많이 하는 작업 중의 하나
- 탐색을 효율적으로 수행하는 것은 매우 중요
- 탐색 키(search key) 
  - 항목을 서로 구별해 주는 필드
- 탐색을 위하여 사용되는 자료구조의 예
  - 배열, 연결 리스트, 트리, 그래프, 해시 테이블 등



## 1) 순차 탐색(Sequential search)

**설명**

탐색 방법 중에서 가장 간단하고 직접적인 탐색 방법

정렬되지 않은 리스트를 처음부터 마지막까지 하나씩 검사하는 방법 

**평균 비교 횟수** 

성공 탐색 : (𝑛+1)/2번 비교

실패 탐색 : 𝑛번 비교 

**시간 복잡도** : 𝑂(𝑛)

**구현 - C**  

```c
int seq_search(int key, int low, int high) {
    int i;
        for(i=low; i<=high; i++)
            if(list[i]==key)
                return i; // 성공 탐색
    return -1; // 실패 탐색
}
```

### 순차 탐색의 변형

리스트 인덱스의 범위 체크를 하지 않음.

반복문의 리스트 끝 테스트 배제

리스트 끝에 탐색 키 저장, 키 값을 찾을 때 반복문 탈출

```c
int seq_search2(int key, int low, int high) {
    int i;
    list[high+1] = key; // 키값을 찾으면 종료
        for(i=low; list[i] != key; i++);
        	if(i==(high+1)) return -1; // 탐색 실패
    		else return i; // 탐색 성공
}
```



## 2) 이진 탐색

**설명**

정렬된 배열에서의 탐색에 적합(정렬된 연결리스트에서는 부적합 - 중앙값 찾기 어렵기 때문)

배열의 중앙값(median)을 조사하여 찾고자 하는 항목이 왼쪽 또는 오른쪽 부분 배열에 있는지를 알아내어 탐색의 범위를 대략 반으로 줄여가며 탐색을 재귀적으로 진행

**시간 복잡도**: 𝑂(log𝑛)

**예시**: 10억 명중에서 특정한 이름 탐색

- 이진 탐색 : 최대 30번의 비교 필요, 10억 = 109 ≈ 2^30
- 순차 탐색 : 최악의 경우 10억번, 평균 5억번의 비교 필요

**의사 코드 구현 - 재귀 함수**

```C
search_binary(list, low, high)
    middle ← low에서 high사이의 중간 위치
    if( 탐색값 = list[middle] ) return TRUE;
    else if (탐색값 < list[middle] )
    	return (list[0]부터 list[middle-1]에서 탐색);
    else if (탐색값 > list[middle] )
    	return (list[middle+1]부터 list[high]에서 탐색);
```

**C 코드 구현 - 반복 함수**

```c
int search_binary2(int key, int low, int high) {
    int middle;
    while( low <= high ){ // 아직 숫자들이 남아 있으면
        middle = (low+high)/2;
        if( key == list[middle] ) return middle; // 탐색 성공
        else if( key > list[middle] ) low = middle+1; // 왼쪽 부분리스트 탐색
        else high = middle-1; // 오른쪽 부분리스트 탐색
    }
    return -1; // 탐색 실패
}
```



## 3) 색인 순차 탐색(Indexed sequential search)

**설명**

**인덱스(index) 테이블**을 사용하여 탐색의 효율을 증대시킨다.

주 자료 리스트에서 일정 간격(대략 𝑛𝑛/𝑚𝑚)으로 발췌한 자료를 저장하는 방식이다.

주 자료 리스트와 인덱스 테이블은 **모두 정렬**되어 있어야 한다.

**예시** 

인덱스 테이블 : 간격 3으로 저장한다. 

Index[i] ≤ key < index[i+1] 인 𝑖를 찾고

주 자료 테이블에서 순차 탐색을 하면 총 비교 횟수는 = 𝑛/3 + 3 

![image](https://user-images.githubusercontent.com/68107000/101120306-a5079600-3630-11eb-9b76-a1cbce2989aa.png)

**C 코드 구현**

```c
// INDEX_SIZE는 인덱스 테이블의 크기, n은 전체 데이터의 수
int search_index(int key) {
int i, low, high;
if(key<list[0] || key>list[n-1]) return -1; // 키값 범위 밖
for(i=0; i<INDEX_SIZE; i++) // 인덱스 테이블 조사하여 키 구간 결정
if(index_list[i].key<=key && index_list[i+1].key>key)
break;
if(i==INDEX_SIZE) { // 마지막 인덱스 구간이면
low = index_list[i-1].index;
high = n;
}
else {
low = index_list[i].index;
high = index_list[i+1].index;
}
return seq_search(key, low, high); // 예상되는 범위만 순차 탐색
}
```



## 4) 보간 탐색(Interpolation search)

**설명**

선형 보간법(linear interpolation) 

- 관측된 값을 바탕으로 관측되지 않은 값을 추정하는 방법이다.
- 양쪽 끝점의 값이 주어졌을 때, 그 사이에 위치한 값을 추정하기 위하여 직선 거리에 따라 선형적으로 계산하는 방법이다.

사전이나 전화번호부를 탐색하는 방법

- ‘ㅎ’으로 시작하는 단어는 사전의 뒷부분에서 찾고 ‘ㄱ’으로 시작하는 단어는 앞부분에서 찾음
- c.f. 이진 탐색 : 원소값에 대한 사전 지식을 활용 안 함 - blind 방식의 탐색

보간 탐색은 이진 탐색과 유사하나 리스트를 **불균등 분할하여 탐색**

직관(intuition)에 의해, 원소들이 일정하게(uniformly) 분포되어 있다고 가정한다.

![image](https://user-images.githubusercontent.com/68107000/101121021-6a066200-3632-11eb-99a8-a54fa8e4cd26.png)

**시간 복잡도** (증명 생략)

최악의 경우 : 𝑂𝑂(𝑛𝑛), 평균적인 경우 : 𝑂𝑂(loglog𝑛𝑛) □ 다음 비교 위치 계산시 부가 연산들이 필요하므로, 테이블이 작은 경우는 이진 탐색이 효율적이고, 테이블이 큰 경우는 보간 탐색이 매우 효율적임

**예시**

-> 손으로 푼 거 사진 덧붙이기

**C 코드 구현**

```c
int search_interpolation(int key, int n) {
int low, high, j;
low = 0;
high = n-1;
while ((list[high] >= key) && (key > list[low])){
j = ((float)(key-list[low]) / (list[high]-list[low]) *
(high-low) ) + low;
if( key > list[j] ) low = j+1;
else if (key < list[j]) high = j-1;
else low = j;
}
if (list[low] == key) return(low); // 탐색 성공
else return -1; // 탐색 실패
}
```



## 5) AVL 트리

### 이진탐색(binary search)과 이진 탐색트리(binary search tree)의 차이점

이진 탐색과 이진 탐색트리는 근본적으로 같은 원리에 의한 탐색 구조이다.

**이진 탐색**은 데이터들이 **배열**에 저장되어 있으므로 삽입,삭제가 매우 비효율적이다. 데이터의 삽입,삭제 시 원소들을 이동이 필요하다.

**이진 탐색트리**는 **연결리스트**로 구현하여 매우 빠르게 삽입/삭제 연산을 수행한다. 삽입, 삭제가 빈번히 이루어진다면 이진 탐색트리가 유리하다. **탐색 연산의 시간복잡도**를 보면 포화 이진트리는 𝑂(log𝑛)이고 경사 이진트리 : 𝑂(𝑛)으로 순차 탐색과 동일하다.

### 높이균형(Height-balanced) 이진탐색트리

**설명**



**A**delson-**V**elskii와 **L**andis에 의해 1962년에 제안된 이진탐색트리로 **AVL 트리**라고 불린다.

**모든 노드의 왼쪽과 오른쪽 부분트리의 높이 차가 1이하인 이진탐색 트리**를 말한다.

**균형 인수(balance factor)** = (왼쪽 부분트리의 높이 – 오른쪽 부분트리의 높이)

모든 노드의 균형 인수가 ±1 이하이면 AVL 트리

![image-20201204214358700](C:\Users\Jueun\AppData\Roaming\Typora\typora-user-images\image-20201204214358700.png)

(참고)![파일_000](https://user-images.githubusercontent.com/68107000/101166357-7ebb1800-367b-11eb-9bc0-6a5b35db1215.png)

**연산**

삽입, 삭제시 트리의 높이가 **비균형 상태**로 되면 **노드들을 재배치**하여 높이 균형 상태를 유지해야 한다.

탐색, 삽입, 제거 연산의 최악의 경우 및 평균 **시간 복잡도 : 𝑂(log𝑛)** 



AVL 트리의 높이는 포화 이진트리의 높이 보다 최대 44% 큼

이 부분 손 글씨로 정리해야함.

### 탐색 연산

이진탐색 트리와 동일

### 삽입 연산

- 삽입 위치에서 루트까지의 경로에 있는 조상 노드들의 균형 인수에 영향을 미친다.
- 균형 인수가 ±2가 된 가장 가까운 조상 노드의 부분트리에 대해서만 재균형(rebalancing)을 한다.
- 삽입 노드부터 균형 인수가 ±2가 된 가장 가까운 조상 노드를 중심으로 회전 (단회전 또는 복회전)

높이 ℎ 인 AVL 트리에 **최대 1번 회전** 필요 ㅡ> **𝑂(log𝑛)**

(참고로 삭제 연산에서는 h/2번 회전 필요)

삽입 후 AVL 트리의 높이 균형이 깨지는 경우를 4가지로 분류해보면 아래와 같이 할 수 있다.

삽입된 노드 N으로부터 가장 가까우면서 균형 인수가 ±2가 된 조상 노드를 A라고 한다. 

- **LL 회전** : N이 A의 왼쪽 자식노드의 왼쪽 부분트리에 삽입된 경우에 A부터 N까지의 경로상 노드의 오른쪽 회전 (단회전)

  ![image](https://user-images.githubusercontent.com/68107000/101161070-5a5b3d80-3673-11eb-89df-a81e835c50a9.png)

  ```c
  AvlNode* rotate_LL(AvlNode *parent){
      Avl_node* child = parent->left_child;
      parent->left_child = child->right_child;
      child->right_child = parent;
      return child;
  }
  ```

  

- **RR 회전** : N이 A의 오른쪽 자식노드의 오른쪽 부분트리에 삽입된 경우에 A부터 N까지의 경로상 노드의 왼쪽 회전(단회전)

  ![image](https://user-images.githubusercontent.com/68107000/101161116-6d6e0d80-3673-11eb-8c02-7057f9e48cc3.png)

  ```c
  Avl_node* rotate_RR(Avl_node *parent){
      Avl_node* child = parent->right_child;
      parent->right_child = child->left_child;
      child->left_child = parent;
      return child;
  }
  ```

  

- **LR 회전** : N이 A의 왼쪽 자식노드의 오른쪽 부분트리에 삽입된 경우에 A부터 N까지의 경로상 노드의 왼쪽-오른쪽 회전(복회전) 

  ![image](https://user-images.githubusercontent.com/68107000/101161180-8d053600-3673-11eb-8084-f501367916d9.png)

  ```c
  Avl_node* rotate_LR(Avl_node* parent) {
      Aavl_node* child = parent->left_child;
      parent->left_child = rotate_RR(child);
      return rotate_LL(parent);
  }
  ```

  

- **RL 회전** : N이 A의 오른쪽 자식노드의 왼쪽 부분트리에 삽입된 경우에 A부터 N까지의 경로상 노드의 오른쪽-왼쪽 회전(복회전)

  ![image](https://user-images.githubusercontent.com/68107000/101161246-a7d7aa80-3673-11eb-8fcc-0a77058e949e.png)

  ```c
  Avl_node* rotate_RL(Avl_node *parent) {
      Avl_node* child = parent->right_child;
      parent->right_child = rotate_LL(child);
      return rotate_RR(parent);
  }
  ```

**예시**

![image](https://user-images.githubusercontent.com/68107000/101163309-c8edca80-3676-11eb-8fb5-6fa2994afb57.png)
![image](https://user-images.githubusercontent.com/68107000/101163341-d440f600-3676-11eb-925f-3415d017c0f6.png)
![image](https://user-images.githubusercontent.com/68107000/101163373-defb8b00-3676-11eb-807e-56de197609b8.png)

e의 첫번째 그림에서 8은 2로 변하지 않는다.

i의 첫번째 그림에서 7은 2로 변하지 않는다.



