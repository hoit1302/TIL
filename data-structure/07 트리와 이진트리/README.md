# 트리와 이진트리

## 트리의 정의 및 용어

> **트리**: 계층적인 관계를 나타내는 특별한 자료구조(비선형 리스트)
>
> 부모-자식 관계의 노드들로 이루어짐

- 용어
  - **노드(node)**
  - **에지(edge)**: 간선
  - **루트(root)**
  - **단말노드 or 리프(terminal node or leaf)**: 자식이 없는 노드
  - **내부노드(internal node)**: 적어도 하나의 자식을 가지는 비단말 노드
  - **자식(child), 부모(parent), 형제(sibling), 조상(ancestor), 후손(descendant) 노드**: 조상과 후손은 자신도 포함한다는 점!
  - **부분 트리(subtree)**
  - **레벨(level)**: 각 층의 번호(0 또는 1로 시작)
  - **높이(height)**: 최대 레벨 (깊이(depth)라고도 함)
  - **차수(degree)**: 노드가 가지고 있는 자식 노드의 개수





## 이진트리

> **이진트리**: 공집합이거나
>
> 공집합이 아닌 경우 특별히 지정된 노드인 루트 (root)가 있고, 각 노드가 왼쪽 부분트리 및 오른쪽 부분트리를 갖는 트리임. 
>
> 그리고 왼쪽 부분트리와 오른쪽 부분트리도 각각 이진트리임
>
> 각 노드는 최대 2개의 자식 노드가 존재함(왼쪽 자식노드, 오른쪽 자식노드)

- 이진트리는 **<u>순서화 트리</u>**임. 즉 **왼쪽, 오른쪽 부분트리가 구분됨**





## 이진트리의 성질과 분류

- 성질

  - 노드의 개수가 𝑛개이면 에지(간선)의 개수는 𝑛-1	(트리의 모양이나 𝑛 값에 상관없이 항상)
  - 높이가 ℎ인 이진트리의 노드 개수 𝑛:

  $$
  ℎ+1 <= 𝑛  <= 2^{h+1}-1
  $$

  - 𝑛개의 노드를 갖는 이진트리의 높이 ℎ:

  $$
  ⌈log_2(n+1)-1⌉ (=⌊log_2n⌋) <= h <= n-1
  $$

- 분류

  ![image-20201012103014273](C:\Users\Jueun\AppData\Roaming\Typora\typora-user-images\image-20201012103014273.png)

  - 포화 이진트리(full binary tree)

    트리의 각 레벨마다 노드들이 **꽉 차있는** 이진트리를 의미함

    전체 노드 개수(높이가 h일 때) 
    $$
    2^{h+1}-1
    $$

  - 완전 이진트리(complete binary tree)

    **레벨 0부터 ℎ-1까지**는 노드들로 **모두** 채워져 있고, 

    마지막 레벨 ℎ 에서 는 왼쪽부터 오른쪽으로 노드가 순서대로 채워져 있는 이진트리

  - 경사 이진트리(skewed binary tree) 또는 사향 이진트리





## 이진트리의 표현

### 배열 표현법

모든 이진트리를 **포화 이진트리라고 가정**하고, 각 노드에 레벨순위로 번호를 붙여서 그 번호를 배열의 인덱스로 삼아 노드의 데이터를 배열에 저장하는 방법

![image-20201012124134801](C:\Users\Jueun\AppData\Roaming\Typora\typora-user-images\image-20201012124134801.png)

- (내용 추가!)

- 장점: **임의의 노드**에 대해 부모, 왼쪽/오른쪽 자식노드의 위치 계산이 용이
- 단점: 완전 이진트리가 아니면(예 – 경사 이진트리) **메모리 낭비**가 큼. 노드의 삽입, 제거 시 배열 이동 등 부가연산이 필요함. 





### 연결리스트 표현법

포인터를 이용하여 부모노드가 자식노드를 가리키게 하는 방법

노드는 구조체로 표현하고 링크는 포인터로 표현한다.

![image-20201012123925473](C:\Users\Jueun\AppData\Roaming\Typora\typora-user-images\image-20201012123925473.png)

```c
typedef struct TreeNode {
    int data;
    struct TreeNode* left,* right;
} TreeNode;
void main() {
    TreeNode* n1= (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* n2= (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* n3= (TreeNode*)malloc(sizeof(TreeNode));
    
    n1‐>data = 10; n1‐>left = n2; n1‐>right = n3;
    n2‐>data = 20; n2‐>left = NULL; n2‐>right = NULL;
    n3‐>data = 30; n3‐>left – NULL; n3‐>right = NULL;
}
```





## 이진트리의 운행(순회)

> 운행:  이진트리의 노드들을 체계적인 순서로 "방문"하는 것

------

### 전순위 운행 - vLR

재귀 호출 이용(스택)

```pseudocode
preorder(x)
if x≠NULL
	then print DATA(x);	
		 preorder(LEFT(x));
		 preorder(RIGHT(x));
```

예) 구조화된 문서의 출력

------

### 중순위 운행 - LvR

재귀 호출 이용(스택)

```pseudocode
inorder(x)
if x≠NULL
	then inorder(LEFT(x));
		 print DATA(x);
		 inorder(RIGHT(x));
```

예) 수식 표현 이진트리

------

### 후순위 운행 - LRv

재귀 호출 이용(스택)

```pseudocode
postorder(x)
if x≠NULL
	then postorder(LEFT(x));
		 postorder(RIGHT(x));
		 print DATA(x);
```

예) 수식 트리, 디렉토리 용량 계산

------

### 레벨순위 운행 -  각 노드를 레벨 순으로 방문

큐 사용

![image-20201012103953767](C:\Users\Jueun\AppData\Roaming\Typora\typora-user-images\image-20201012103953767.png)

```c
Void level_order(TreeNode *ptr) {
	QueueType q;
    init(&q);
	if( ptr == NULL ) return;

    enqueue(&q, ptr);
    while (!is_empty(&q));
        ptr = dequeue(&q);
        printf(%d”, ptr‐>data);
        if (ptr‐>left) enqueue(&q, ptr‐>left);
        if (ptr‐>right) enqueue(&q, ptr‐>right);
    }
}
```

- 방법: 작은 레벨부터 방문, 레벨이 같으면 왼쪽부터 오른쪽으로 방문

  1) 루트를 큐에 삽입

  2) 큐에 있는 노드를 꺼내 방문하고, 그 노드의 자식 노드를 큐에 삽입

  3) 큐가 empty가 될 때까지 반복
  
  



## 이진트리 연산

### 노드 개수

각 부분트리에 대하여 재귀 호출을 하여 노드 개수를 구해서 더한 다음 여기에 다시 1을 더하여 반환

```c
int get_node_count(TreeNode* node){
	int count = 0;
	if (node != NULL)
		count = 1 + get_node_count(node->left) + get_node_count(node->right);
	return count;
}
```



### 높이

각 부분트리에 대하여 재귀 호출하여 높이를 구하여 그 값을 반환하고, 부분트리들의 반환값 중 최대값+1을 반환

```c
// 1부터 시작
int get_height(TreeNode* node) {
	int height = 0;
	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));
	return height;
}
```





## 이진트리의 응용(1): 수식표현 트리

> **수식표현 트리** : 산술식을 트리 형태로 표현한 것
>
> - 내부노드: 연산자(operator)
> - 단말노드(리프): 피연산자(operand)

![image-20201012104931070](C:\Users\Jueun\AppData\Roaming\Typora\typora-user-images\image-20201012104931070.png)

![image-20201012104821425](C:\Users\Jueun\AppData\Roaming\Typora\typora-user-images\image-20201012104821425.png)

### 계산

**후순위 운행**을 이용

부분트리의 값을 재귀 호출로 계산

![image-20201012124352722](C:\Users\Jueun\AppData\Roaming\Typora\typora-user-images\image-20201012124352722.png)

```pseudocode
// 알고리즘: 내부노드를 방문할 때 양쪽 부분트리의 값을 이용하여 해당 노드에 저장된 연산자를 이용하여 계산한다.
evaluate(exp)

if exp = NULL
	then return 0;
	else x←evaluate(exp->left);
		 y←evaluate(exp->right);
		 op←exp->data;
		 return (x op y);
```





## 이진트리의 응용(2): 이진탐색 트리

**이진탐색 트리(Binary search tree, BST)**

![image-20201012131747396](C:\Users\Jueun\AppData\Roaming\Typora\typora-user-images\image-20201012131747396.png)

```
"탐색(검색) 작업을 효율적으로 하기 위한 트리 자료구조"
key(왼쪽 부분트리) < key(루트) < key(오른쪽 부분트리)
```

- 비어있는 널(NULL) 트리도 이진탐색트리이고, 왼쪽 부분트리와 오른쪽 부분트리도 각각 이진탐색트리이다.
- 이진탐색트리를 **중순위 운행**하면 오름차순으로 정렬된 값을 얻을 수 있다.
- 모든 노드의 키는 **유일**하다고 가정한다.

------

### 탐색 연산

```pseudocode
// 알고리즘 의사코드 – 재귀적 방법
search(x, key)

if x = NULL then return NULL;		// 실패 탐색
if key = x‐>data then return x;		// 성공 탐색
else if key < x‐>data				
	then return search(x‐>left, key);	// 키값이 작으면 왼쪽 부분트리
	else return search(x‐>right, key);  // 키값이 크면  오른쪽 부분트리
```

최대 **높이**만큼 탐색함. 



------

### 삽입 연산

```pseudocode
insert_node(T, key) //트리 T에 key 삽입

    p ← NULL; // p는 부모노드, t는 현재노드
    t ← T;
    
    while t ≠ NULL do // 삽입 위치 찾기(parent 찾기)
        p ← t;
        if key < p‐>key
        	then t ← p‐>left;
            else t ← p‐>right;
    //  if (key < p‐>key) 	then t ← p‐>left;
    //  else t ← p‐>right;
    
    z ← make_node(key);
    
    if p = NULL then T ← z; // 트리가 비어있음
    else if z‐>key < p‐>key // 노드 insert
        then p‐>left ← z
    	else p‐>right ← z
//  if (p ≠ NULL) // 트리가 비어있지 않음 -> 노드 insert
//    	if (z‐>key < p‐>key)   then p‐>left ← z
//    	else p‐>right ← z
//  else T ← z; // 트리가 비어있음
```

- 이진 탐색트리에 원소를 삽입하기 위해서는 먼저 탐색을 수행하는 것이 필요
- 탐색에 실패한 위치가 바로 새로운 노드를 삽입하는 위치
- 탐색에 성공한 경우 삽입할 수 없다.
- **최악의 경우 시간 복잡도 : 𝑂(ℎ)**, 단 ℎ : 이진탐색 트리의 높이
- 항상 단말노드 위치에 삽입됨.



------

### 삭제 연산

- 3가지 경우

  ![image-20201014193142811](C:\Users\Jueun\AppData\Roaming\Typora\typora-user-images\image-20201014193142811.png)

  1. 삭제하려는 노드가 **단말 노드**일 경우

     - 단말노드의 부모노드를 찾아서 연결을 끊으면 된다. 

     ![image-20201014193222786](C:\Users\Jueun\AppData\Roaming\Typora\typora-user-images\image-20201014193222786.png)

  2. 삭제하려는 노드가 하나의 왼쪽 또는 오른쪽 **부분트리** 중 **하나**만 가지고 있는 경우

     - 해당 노드는 삭제하고 그 노드의 부분트리는 부모 노드에 붙여준다.

     ![image-20201014193236514](C:\Users\Jueun\AppData\Roaming\Typora\typora-user-images\image-20201014193236514.png)

  3. 삭제하려는 노드가 두 개의 부분트리 모두 가지고 있는 경우

     -  중순위 선행자(inorder predecessor: 삭제 노드의 값보다 작은 값들 중에서 가장 큰 값) 또는 중순위 계승자(inorder successor: 삭제 노드의 값보다 큰 값들 중에서 가장 작은 값)을 가진 노드를 삭제 노드 위치로 가져온다.

- Inorder successor값은 어디에 있을까?

![image-20201014194202404](C:\Users\Jueun\AppData\Roaming\Typora\typora-user-images\image-20201014194202404.png)

------

### 이진탐색 트리의 성능 분석

- 이진 탐색트리에서의 탐색, 삽입, 삭제 연산의 시간 복잡도는 트리의 높이 ℎ 에 비례한다. 
- 따라서 최악의 경우(예 : 경사 이진트리) 시간복잡도는 O(𝑛) 
- 평균적인 경우 시간복잡도는 O(log_2(𝑛))
  - 참고: 𝑛개의 노드를 갖는 이진트리의 높이
    - 최대: 𝑛-1
    - 최소: ⌊log_2(n)⌋

