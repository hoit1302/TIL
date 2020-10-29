# 우선순위 큐(priority queue)

**우선순위를 가진 원소**들을 저장하는 **큐**

FIFO 순서가 아니라 **우선 순위가 높은 항목이 먼저 제거**된다.

스택이나 FIFO 큐는 우선순위 큐의 특별한 형태라고 볼 수 있다.

![image](https://user-images.githubusercontent.com/68107000/97595589-2cb52000-1a47-11eb-8f33-8bf9ec1d01ff.png)

- 응용분야
  - 시뮬레이션 시스템(우선 순위는 대개 사건(event)의 발생 시각)
  - 네트워크 트래픽 제어 (network management packet 처리)
  - 운영 체제에서의 작업 스케줄링(시스템 프로세스가 응용 프로세스보다 우선 순위 높음)
- 종류
  - 최소(min) 우선순위 큐
  - 최대(max) 우선순위 큐

## ADT

- **객체**: **우선순위를 가진** n개의 element형의 항목들
- **연산**
  - **insert(pq, x)** ::= 우선순위 큐 pq에 원소 x를 추가한다. (**x값이 우선순위**라고 가정)
  - **deleteMin(pq)** ::=  우선순위 큐 pq로부터 가장 우선순위가 높은 원소를 삭제하고 이를 반환한다. (혹은 deleteMax(pq))
  - **peep(pq)** ::= 우선 순위가 가장 높은 원소를 반환한다.(삭제는 안함) 

## 구현 방법

- **배열**을 이용한 우선순위 큐

  - 오름차순으로, 원소의 개수는 우선순위가 가장 큰 값의 인덱스로 활용한다.

  ![image](https://user-images.githubusercontent.com/68107000/97596728-5d498980-1a48-11eb-9a0a-af3e31e8a508.png)

- **연결리스트**를 이용한 우선순위 큐

  - 내림차순으로, 헤드 포인터는 우선순위가 가장 큰 값을 가리킨다.

  ![image](https://user-images.githubusercontent.com/68107000/97596764-69354b80-1a48-11eb-8c5b-8169487738f3.png)

- **힙**을 이용한 우선순위 큐

  ![image](https://user-images.githubusercontent.com/68107000/97596831-7ce0b200-1a48-11eb-86a9-f4651e2f6df5.png) 

  



### 각 구현 방법에 대한 시간 복잡도

**삽입 및 삭제의 기본 연산 : 원소의 비교 및 이동**

| 구현방법             |           삽입            |           삭제            |
| :------------------- | :-----------------------: | :-----------------------: |
| 정렬 안된 배열       |      O(1) - 맨 뒤에       |   O(n) - 최대 n번 비교    |
| 졍렬 안된 연결리스트 |      O(1) - 맨 앞에       |   O(n) - 최대 n번 비교    |
| 정렬된 배열          |   O(n) - 최대 n번 비교    |      O(1) - 맨 뒤를       |
| 정렬된 연결리스트    |   O(n) - 최대 n번 비교    |      O(1) - 맨 앞을       |
| 힙                   | O(log_2(n)) - 트리의 높이 | O(log_2(n)) - 트리의 높이 |



## 힙(heap)

힙 : 노드에 저장된 키값들이 다음의 조건을 만족하는 **완전이진트리**

- **최대 힙(max heap)**
  - **부모 노드의 키값**이 자식 노드들의 키값보다 **크거나 같은** 완전 이진트리 
  - 즉, key(부모 노드) ≥ key(자식 노드)
- **최소 힙(min heap)**
  - **부모 노드의 키값**이 자식 노드들의 키값보다 **작거나 같은** 완전 이진트리
  - 즉, key(부모 노드) ≤ key(자식 노드)



### 높이

앞 정리에서 자세한 내용을 확인할 수 있다.

n개의 노드를 가지고 있는 힙의 높이 ℎ 는 **log_2(n)의 내림**

![image](https://user-images.githubusercontent.com/68107000/97601374-71dc5080-1a4d-11eb-865e-8ae091fb0197.png)

### 구현

**배열**을 이용하여 구현한다.

**부모 노드와 자식노드를 찾기가 쉽다.**

**계산방법**

- **index가 1부터 시작할 경우,**
  - 왼쪽 자식의 인덱스 = 2*i (2*i ≤ n)
  - 오른쪽 자식의 인덱스 = 2*i+1 (2*i+1 ≤ n)
  - 부모의 인덱스 = i/2의 내림 (i ≠ 1)
- **index가 0부터 시작할 경우,**
  - 왼쪽 자식의 인덱스 = 2*i+1 (2*i+1 ≤ n-1)
  - 오른쪽 자식의 인덱스 = 2*i+2 (2*i+2 ≤ n-1)
  - 부모의 인덱스 = i-1/2의 내림 (i ≠ 0)

n은 동일하게 원소 개수이고 그려보면 쉽게 알 수 있다.

### 삽입

**🎃STEP_1🎃** 새로운 노드는 힙의 마지막 노드 다음 위치에 삽입한다.

🎃**STEP_2**🎃 **upheap()**: 부모 노드와의 관계를 보며 최대 힙의 성질을 만족시킨다.

```c
/* upheap 알고리즘 */

insert_max_heap(A, key)
    // step1 새로운 노드는 마지막 다음에 삽입한다.
    heap_size ← heap_size + 1;
    i ← heap_size;
    A[i] ← key;
    
	// step2 지금 루트가 아니고 부모보다 자식이 더 크면 교환한다.
	while i ≠ 1 and A[i] > A[PARENT(i)] do	
        A[i] ↔ A[PARENT];
        i ← PARENT(i);
```

실제로는 교환을 하지 않고, 그냥 부모 노드만 끌어내린 다음에 삽입될 위치가 확실해지면 새로운 노드를 그 위치로 이동시킨다. (코드 확인~)

최악의 경우, 단말노드에서 루트까지 올라가야 하므로 트리의 높이에 해당하는 비교 연산 및 이동 연산이 필요하다. 따라서 **힙의 높이만큼 O(lgN)**

### 삭제

🎃**STEP_1**🎃 루트를 삭제하여 그 값을 반환한다.

🎃**STEP_2**🎃 마지막 노드를 루트로 이동시킨다. (완전 이진 트리의 구조적 성질을 만족)

🎃**STEP_3**🎃 **downheap()**: 자식 노드 중 큰 값과의 관계를 보며 최대 힙의 성질을 만족시키도록 한다.

```c
/* downheap 알고리즘 */

delete_max_heap(A)
    item ← A[1]; // step1 삭제된 루트 노드의 값, return할 값
    A[1] ← A[heap_size]; // step2 마지막 노드를 루트로 이동
    heap_size ← heap_size-1;
    i ← 2; /* i는 왼쪽 자식 노드의 인덱스 */
    while (i ≤ heap_size) do
        // step3-1 자식 노드 중 큰 값 찾기
        if (i < heap_size and A[i+1] > A[i])
            then largest ← i+1; /* 오른쪽 노드가 있고 오른쪽이 왼쪽보다 클 때 */
            else largest ← i; /* 오른쪽 노드가 없거나 왼쪽이 오른쪽보다 클 때 */
        // step3-2 자식 노드 중 큰 값과 부모를 비교
        if A[PARENT(largest)] > A[largest]
	        then break; /* 부모가 자식보다 크면!!! 자리잡고 빠져나가기~! */ 
		// step3-3 반복을 위해 왼쪽 자식노드로 이동
        A[PARENT(largest)] ↔ A[largest];
        i ← CHILD(largest); 
    end
    return item;
```

최악의 경우, 루트에서 가장 아래 레벨까지 내려가야 하므로 트리의 높이에 해당하는 비교 연산 및 이동 연산이 필요하다. 따라서 **힙의 높이만큼 O(lgN)**

## 힙의 응용: 힙 정렬(Heapsort)

🎃**STEP_1**🎃 정렬해야 할 n개의 원소들을 **최대 힙으로 구성**한다.

- 최대 힙으로 구성할 때 2가지 방법이 있다.
  - **on-line (O(nlgn))**
  - **off-line (O(n))**, ✅더 효율적인 힙 구성 방법

🎃**STEP_2**🎃 루트(최대값)와 가장 마지막 원소를 **교환**한 다음, **마지막 원소(최대값)를 제외**하고 **downheap**을 반복적으로 수행

### 시간 복잡도

n개의 원소를 최대 힙으로 **구성**하는데 **O(n)** 만큼 소요된다.

**downheap 연산**을 **n − 1 번** 수행해야 한다.

따라서 전체적으로 **O(nlgn)** 시간이 걸린다.

### 힙 정렬 프로그램1 연속적 삽입 (on-line)

```c
// 우선 순위 큐인 힙을 이용한 정렬
void heap_sort(element a[], int n) {
    int i;
    HeapType h;
    init(&h);
    
    // step1, heap 구성
    for (i=0;i<n;i++)
    insert_max_heap(&h, a[i]);

    // step2, downheap 반복
    for(i=(n-1);i>=0;i--)
    	a[i] = delete_max_heap(&h);
}
```

### 힙 정렬 프로그램2 (off-line)

**step1, 효율적으로 힙구성하기**

![image](https://user-images.githubusercontent.com/68107000/97600388-5886d480-1a4c-11eb-807e-981d14c07fd2.png)

**step2, 동일**

![image](https://user-images.githubusercontent.com/68107000/97606481-2f1d7700-1a53-11eb-85ec-c98e82d812e6.png)![image](https://user-images.githubusercontent.com/68107000/97606517-380e4880-1a53-11eb-9681-920af2031db6.png)

