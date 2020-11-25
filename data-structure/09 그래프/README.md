# 그래프



Seven Bridges of Königsberg (지금은 러시아 칼리닌그라드)

- 한 붓 그리기: 모든 다리를 한번만 건너서 처음 출발했던 장소로 돌아오는 문제
- 그래프 개념을 만들어 증명 (1736)
- 오일러 사이클(Eulerian cycle)
  - 모든 정점에 연결된 에지의 수가 짝수이면 오일러 사이클이 존재한다.

## 그래프 정의

**연결**되어 있는 **객체 간의 관계**를 표현하는 자료구조이다.

가장 일반적인 자료구조의 형태이다. 트리(tree), 이진트리도 그래프의 특수한 경우로 볼 수 있다.

![image](https://user-images.githubusercontent.com/68107000/97969359-49fd3c00-1e03-11eb-8dda-2261a3eeace5.png)

- **그래프 G**는 (V, E)로 표시
  - 그래프는 **정점(vertex)와 에지(edge, 간선)** 들의 집합으로 구성되어 있다.
  - 즉, 정점 집합과 에지 집합의 **순서쌍**
- **정점(vertex)**
  - 여러 가지 특성을 가질 수 있는 객체 의미
  - V(G) : 그래프 G의 정점들의 집합
  - V(G1) = {V0, V1, V2, V3, V4}
  - |V| = n
  - 노드(node)라고도 불림
- **에지(edge)**
  - 정점들 간의 **관계**를 의미
  - E(G) : 그래프 G의 에지들의 집합
  - E(G1) = {(V0, V3), (V1, V2), (V3, V4)}
  - E(G2) = {<0, 1>, <1, 0>, <1, 2>}
  - |E| = m
  - 간선 또는 링크(link)라고도 불림

### 예시

- 전기회로의 소자 간 연결 상태
- 운영체제의 프로세스와 자원 관계
- 사회 연결망(social network)
- 지도에서 도시들의 연결 상태
- 도로망, 지하철망
- 선수과목 관계
- 영역 간 인접관계
- 나눔의 관계 (나머지가 0인 관계)

## 종류

### 무향 그래프(undirected graph)

무향 에지를 사용한다. 이는 무방향/양방향을 의미한다.

도로의 왕복통행 길을 예시로 들 수 있다.

**(A, B) = (B, A)**

### 방향 그래프(directed graph, digraph) 또는 유향 그래프

방향 에지를 사용한다. 즉 에지를 통해서 한쪽 방향으로만 갈 수 있다는 것을 의미한다.

도로의 일방통행 길을 예시로 들 수 있다.

**<A, B> ≠ <B, A>**

- 특별한 언급이 없으면, 그래프는 자가 루프(self-loop)와 중복 에지(multiple edge)가 없는 단순 그래프(simple graph) 를 의미한다.

### 가중치 그래프(weighted graph)

**에지에 비용(cost)** 과 같은 가중치(weight)가 할당된 그래프

무향 그래프 및 방향 그래프 모두에 해당

예) 정점=동시, 에지=도로를 연결하는 도로, 가중치=거리 또는 통행료

------

### 부분 그래프(subgraph)

![image](https://user-images.githubusercontent.com/68107000/97967612-cd695e00-1e00-11eb-8605-e4116ccc4cf4.png)

정점 집합 V(G)와 에지 집합 E(G)의 부분 집합으로 이루어진 그래프

- Spanning subgraph: G의 정점을 모두 가지고 있을 경우
- Spanning Tree: G의 정점을 모두 가지고 있고 연결은 다 되어 있으나 cycle이 아닌 경우

### 인접 정점(adjacent vertex)

어떤 정점에서 에지에 의해 직접 연결된 정점

### 차수(degree)

- **무향** 그래프의 차수
  - 하나의 정점에 연결된 다른 정점의 수
  - 무향 그래프 정점들의 모든 차수의 합은 에지 개수의 2배이다.
  - ![image](https://user-images.githubusercontent.com/68107000/97966417-289a5100-1dff-11eb-864f-a7aafa194a21.png)
- **방향** 그래프의 차수
  - 진입 차수(in-degree)
  - 진출 차수(out-degree)
  - 방향 그래프의 모든 진입(또는 진출) 차수의 합은 에지의 수와 같다.
  - ![image](https://user-images.githubusercontent.com/68107000/97966670-7d3dcc00-1dff-11eb-9842-06f63b8385bd.png)

### 경로(path)

- **무향** 그래프의 정점 s로부터 정점 t까지의 경로
  - 정점의 나열 s, v1 , v2 , ..., vk , t
  - 나열된 정점들 간에 반드시 에지 (s, v1), (v1, v2), ... , (vk, t)가 존재
- **방향** 그래프의 정점 s로부터 정점 t까지의 방향(유향) 경로
  - 정점의 나열 s, v1 , v2 , ..., vk , t
  - 나열된 정점들 간에 반드시 방향 에지 , , … ,< vk , t>가 존재
- **경로의 길이(length)**: 경로를 구성하는 에지의 수
- **단순 경로**: 경로 중에서 **반복**되는 정점 및 에지가 **없는** 경로
- **사이클(cycle)**: 단순 경로의 시작 정점과 끝 정점이 동일한 경로

```
예시
G1의 0, 1, 2, 3은 경로지만 0, 1, 3, 2는 경로 아님
G1의 1, 0, 2, 3은 단순경로이지만 1, 0, 2, 0은 단순경로가 아님
G1의 0, 1, 2, 0과 G3의 0, 1, 0은 사이클
```

### 연결성(connectivity)

- **비연결 그래프(disconnected graph)**
- **연결 그래프(connected graph)**
  - 무향 그래프 G에 있는 모든 정점 쌍에 대하여 경로가 존재
  - **strongly connected graph**: **유향 그래프에서** 모든 두 정점 쌍(pair)에서 유향 경로가 존재
- **트리(unrooted tree)**
  - 그래프의 특수한 형태로서 **사이클을 갖지 않는** 연결 그래프(connected acyclic graph)
  - minimally connected (연결 그래프에서 최소로 연결되어 있다.)
  - c.f. rooted tree, unrooted tree
- **완전 그래프(complete graph)**
  - **모든 정점**이 **서로 인접**되어 있는 그래프
  - maximally connected  (연결 그래프에서 최대로 연결되어 있다.)
  - n개의 정점을 가지는 완전 그래프의 에지 개수
    - 무향 그래프는 n(n-1)/2개이고
    - 방향 그래프는 n(n-1)개이다.

```
예시
G1은 연결 그래프
G2는 비연결 그래프
G2에서 정점 3이 없다면 트리
```

### 그래프 표현 방법-1 인접 행렬(adjacent matrix)

- ```c
  if (그래프에 에지 (i, j)가 존재) A[i][j] = 1;
  else                          A[i][j] = 0;
  ```

- 인접 행렬의 대각선 성분은 모두 0이다. (자가 루프가 없는 단순 그래프)

- 무향 그래프의 인접 행렬은 **대각선 대칭**이다. (**symmetric**)

- **삼각 행렬(triangular matrix)** 만으로도 표현 가능하다.

- 일반적으로 인접 행렬은 0, 1로 이루어진 부울(boolean) 행렬이다. 즉, 에지의 존재 여부만 표시한다.

- 예시

  - ![image](https://user-images.githubusercontent.com/68107000/97968242-bd05b300-1e01-11eb-8869-1086c24e1978.png)

- 에지의 길이나 비용(cost) 고려하여 가중치를 부여하면 **가중치 그래프(weighted graph)** 가 된다.

  - ```c
    weight(<i,j>) 값은 Wij 이렇게 표현한다.
    
    if (그래프에 에지 <i, j>가 존재)  A[i][j] = Wij;
    else if (i==j)                 A[i][j] = 0;
    else (에지 <i,j>가 존재하지 않음) A[i][j] = ∞;
    ```

- 예시

  - ![image](https://user-images.githubusercontent.com/68107000/97968325-d73f9100-1e01-11eb-814a-37d3ebe1d4ca.png)

- **공간 복잡도: O(n^2)**
  
  - 희소 그래프인 경우, 매우 비효율적이다. 행렬 원소 대부분이 ∞이거나 0이기 때문이다.

### 그래프 표현 방법-2 인접 리스트(adjacency list)

- 각 정점에 인접한 정점들을 **연결 리스트**로 표현

- n개의 연결 리스트로 구성

- 각 연결 리스트마다 포인터 변수가 리스트의 처음 노드를 가리킴

- 연결 리스트가 없으면 즉, 차수가 0이면 포인터 변수값은 null

- 예시

  - ![image](https://user-images.githubusercontent.com/68107000/98393410-92835680-209c-11eb-993b-1f8b62d6a71d.png)

- 정점의 개수가 n, 에지의 개수가 m일 때,

  - 무향그래프 : n개의 포인터 변수 + 2m개의 일반 노드
  - 방향그래프 : n개의 포인터 변수 + m개의 일반 노드

-  자료 구조

  ```c
  typedef struct GraphNode{
      int vertex;	// index
      struct GraphNode *link;
  } GraphNode;
  typedef struct GraphType {
      int n; // 정점의 개수
      GraphNode* adj_list[MAX_VERTICES]; // head pointer의 배열
  } GraphType;
  ```

- 효율성: 정점의 개수와 에지의 개수에 의존

  - 에지 개수를 구하는 알고리즘 : **O(n+m)**
  - m = n(n-1)/2 인 경우(완전 그래프-모든 정점이 서로 인접되어 있는 그래프, worst case): **O(n^2)**

## 2) 그래프 탐색(Graph search) 또는 운행(traversal)

- 그래프의 **가장 기본적인 연산** 중 하나이다.
- 하나의 정점으로부터 시작하여 차례대로 모든 정점들을 한번씩 방문하는 것을 말한다.
- 그래프 관련 많은 문제들은 그래프의 노드들을 **체계적으로 탐색**하는 것으로 해결 가능하다.
- 특**정한 정점에서 특정 정점까지 갈 수 있는지 없는지를 탐색** 
  - (예 1) 도로망에서 특정 도시로부터 다른 도시로 갈 수 있는지 여부
  - (예 2) 전자회로에서 특정 단자와 다른 단자가 서로 연결되어 있는지 여부

## 2-1) 깊이우선 탐색(DFS)

깊이우선 탐색 (DFS : depth-first search)

- 일단 임의의 한쪽 방향으로 갈 수 있을 때까지 가다가 더 이상 갈 수 없게 되면 가장 가까운 갈림 길로 돌아와서 그곳으로부터 다른 방향으로 다시 탐색을 진행한다.

- 갈림길로 돌아가기 위해서는 **스택**이 필요한데, **재귀 함수 호출**로 묵시적인 스택을 이용하여 구현할 수 있다.

  - 예로 미로 찾기가 있다.

- 알고리즘은 이러하다.

  ``` C
  depth_first_search(v)
      v를 방문;  v가 방문되었다고 표시(mark);
      for all u ∈ (v에 인접한 정점들) do
      	if (u가 아직 방문되지 않았으면) 
              then depth_first_search(u)
  ```

- 공간 효율성 ㅡ 차수 높은 거 따라가는 거 기억하죠?

  - 인접리스트 :  **O(n+m)** (그래프 O(n+m), visited[] O(n), 스택 O(n) )
  - 인접행렬 : **O(n^2)** (그래프 O(n^2), visited[] O(n), 스택 O(n) )

## 2-2) 너비우선 탐색(BFS)

너비우선 탐색(BFS : breadth-first search)

- **시작 정점으로부터 거리가 가까운 정점들을 먼저** 차례로 방문하고 멀리 떨어져 있는 정점을 나중에 방문하는 운행 방법이다.

- **큐**를 사용하여 구현할 수 있다.

- 알고리즘은 이러하다.

  ```c
  breadth_first_search(v)
      
  	v를 방문;  v가 방문되었다고 표시(mark);	 v를 큐 Q에 삽입;
      while (not is_empty(Q)) do
          큐 Q에서 삭제(dequeue)한 정점을 w;
          for all u ∈ (w에 인접한 정점들) do
              if (u가 아직 방문되지 않았으면) 
                  then u를 방문;  u가 방문되었다고 표시(mark);  u를 큐 Q에 삽입;
  ```

- 공간 효율성 

  - **인접리스트** : **O(n+m)** (그래프 O(n+m), visited[] O(n), 큐 O(n) )
  - **인접행렬** : **O(n^2)** (그래프 O(n^2), visited[] O(n), 큐 O(n) )

## 3) 연결 성분(Connected component)

최대로 연결된 부분 그래프(Maximal connected subgraph) 

![image](https://user-images.githubusercontent.com/68107000/98486965-b644c900-2263-11eb-872e-f92c21cfbe35.png)

- 연결 성분의 개수를 세는 프로그램

  - DFS 또는 BFS를 반복 이용

  - 탐색 프로그램의 visited[v] = TRUE;를 visited[v] = count;로 교체

  - ```C
    void find_connected_component(GraphType *g) {
        int i;
        count = 0;
        for (i=0; i<g->n; i++)
            if (!visited[i]) { // 아직 방문되지 않은 경우
                count++;
                dfs_mat(g, i);
        }
    }
    ```



## 강연결 방향그래프(strongly connected digraph)와 강연결 성분(strongly connected component 또는 strong component)

예시

![image](https://user-images.githubusercontent.com/68107000/98487318-9b735400-2265-11eb-846c-4ae97eb121f0.png)

강연결 방향그래프가 아니고

강연결 성분 2개로 구성되어 있다.

## 이중연결 그래프(biconnected graph)와 이중연결 성분(biconnected component 또는 bicomponent)

**이중연결 그래프(biconnected graph)**

- 절점이 없는 연결 그래프
- 즉 한 정점을 지웠을 때 나머지가 연결되어 있다는 뜻이다.

**절점(cut vertex or articulation point)**

- G=(V,E)의 정점으로서 그 정점과 연결된 에지들을 제거했을 때, 나머지 부분 그래프가 두 개 이상의 연결 성분으로 구성
- 즉 한 정점을 지웠을 때 그래프가 분리가 된다면 그 점은 절점이다는 뜻이다.

**이중연결 성분(biconnected component 혹은 bicomponent)**

- G의 이중연결 부분그래프 H로서, H를 포함하는 더 큰 이중연결 부분 그래프가 없는 경우
- 즉 **G의 최대 이중연결 부분그래프**(maximal biconnected subgraph)
- 이중 연결 그래프는 이중 연결 성분이 1개이다.
- 이중 연결 그래프가 아니면 이중 연결 성분이 1개 이상이다.

특징

-  그래프가 컴퓨터 네트워크인 경우, 절점의 불량은 통신 불량 초래
- 두 이중연결 성분들의 **교집합**은 최대 하나의 정점 (= 절점) **(0..1)**
- 두 이중연결 성분들의 **에지 교집합**은 공집합
- 즉, 이중연결 성분은 **그래프의 에지 집합을 분할(partition)**

## 4) 스패닝 트리(spanning tree, 신장 트리)

- **연결 그래프 G**의 스패닝(또는 신장) 트리란 G의 부분그래프로서 **그래프의 모든 정점을 포함**하는 트리

- 즉, **모든 정점들이 연결되어 있어야 하고 사이클이 존재해서는 안된다**는 뜻이다.

- 𝑛개의 정점을 갖는 그래프의 스패닝 트리는 반드시 𝑛-1개의 에지를 가진다. - 트리의 특징

- 최소 비용을 사용하는 네트워크 구축 시 사용 : 통신망, 도로망, 유통망 등

- 깊이우선 스패닝 트리 알고리즘

  - ```C
    depth_first_search(v)
    v를 방문하였다고 표시;
    for all u ∈ (v에 인접한 정점) do
        if (u가 아직 방문되지 않았으면)
            then (v, u)를 스패닝트리 에지라고 표시;
            	depth_first_search(u);
    ```

- 예시

  - ![image](https://user-images.githubusercontent.com/68107000/98487941-88fb1980-2269-11eb-82ad-ccb19c9414ad.png)

## 4) 최소 스패닝 트리 (MST : minimum spanning tree)

가중치 그래프의 스패닝 트리들 중에서 에지들의 **가중치의 합이 최소인 스패닝 트리** 

- 네트워크에 있는 모든 정점들을 최소의 비용으로 연결(여러 개 일 수 있음)

- 예시

  - ![image](https://user-images.githubusercontent.com/68107000/98488014-0e7ec980-226a-11eb-8c3a-4e856e86be9d.png)
  - G의 스패닝 트리 : (a), (b), (c), (d)
  - G의 최소 스패닝 트리 : (c)

- MST 응용

  - 도로 건설 - 도시들을 **모두 연결**하면서 **도로의 길이를 최소**로 하는 문제
  - 전기 회로 – 단자들을 **모두 연결**하면서 **전선의 길이를 최소**로 하는 문제
  - 통신 - **전화선의 길이가 최소**가 되도록 전화 케이블 망을 구성하는 문제
  - 배관 - 파이프를 **모두 연결**하면서 파이프의 **총 길이를 최소**로 하는 문제

  

### 4-1) Prim의 MST 알고리즘

- **임의의 시작 정점에서 출발**하여 스패닝 트리 집합을 단계적으로 확장해 나간다.

  - 시작 단계에서는 시작 정점만이 스패닝 트리 집합에 포함된다.

- 스패닝 트리 집합에 인접한 정점 중에서 **최소 가중치로 연결된 정점을 선택**하여 스패닝 트리의 정점 및 에지 집합에 추가한다.

- 이 과정을 스패닝 트리 집합이 **𝑛-1개의 에지를 가질 때까지** 반복

- **예시 1**

  - ![image](https://user-images.githubusercontent.com/68107000/98488236-55b98a00-226b-11eb-97b6-024c3a40ae1b.png)

- **예시 2**

  - ![image](https://user-images.githubusercontent.com/68107000/99012676-42236180-2592-11eb-9b8f-fbec3e224f58.png)

- **pseude code**

  - ```c
    // 입력: 가중치 그래프 G
    // dist[u]는 현재 MST에 속해있는 정점과 속해있지 않는 정점 u까지의 최소 가중치
    // 출력: 에지의 집합 T
    Prim(G, s)
        // 초기화
        for each u∈V(G) do
            dist[u] ← ∞;
        dist[s] ← 0;
        우선순위 PQ에 모든 정점 삽입(우선순위는 dist[]);
            
        for i ← 0 to n‐1 do
            u ← deleteMin(PQ); // 가중치가 가장 작은 정점 u
            u를 출력;
    		// dist 재계산
            for each v ∈ (u의 인접 정점) do
                if (v ∈ PQ and weight[u][v] < dist[v])
                then dist[v] ← weight[u][v];
    ```

- **시간복잡도: O(n^2)**

  - 선택된 정점 집합에서 선택 안된 정점으로 가는 에지들 중 **가장 dist가 적은 에지 선택** : 주 반복문은 정점의 수 𝑛만큼 반복
  - **방금 선택된 정점 기준**으로 선택되지 않은 정점으로의 **dist 재계산** : 내부 반복문은 𝑛번 반복

### 4-2) Kruskal의 알고리즘

- **의미**

  -  MST가 **가중치 값이 작은 에지들**로 구성되어야 함
  -  MST가 트리이므로 **사이클이 없고 연결되도록** 구성

- **방법**

  - 그래프 G에 남아있는 에지들 중에서 **최소의 가중치를 갖는 에지 선택**
  - 선택한 에지가 MST로 이미 선택된 에지들과 **사이클을 형성하면 선택 취소**(구성 과정에서 MST로 선택된 에지들은 포리스트 형성 -> 무슨 말인지 모르겠음)
  - 위의 과정을 반복하여 선택한 에지의 수가 |V|-1 이면 종료

- **알고리즘**

  - **v ≡ w**: v와 w가 같은 연결 성분 내에 있다. v≡w일 때 (v,w)를 첨가하면 **사이클이 형성**된다. 그러므로 에지 선택 시 v≢w일 때만 (v,w)를 선택할 수 있다.

  - ```C
    /* G가 연결 그래프라고 가정함 */
    E_T = ∅; /* 스패닝 트리의 에지 집합 */
    while (ET contains fewer than n-1 edges and E is not empty) {
        choose the least cost edge (x,y) from E;
        delete (x,y) from E;
        if (not x≡y in T) add(x,y) to E_T;
        else discard(x,y);
    }
    ```

- **예시1**

  ![image](https://user-images.githubusercontent.com/68107000/99217474-76f61980-281b-11eb-80bc-955d063509de.png)

- **예시2**

  ![image](https://user-images.githubusercontent.com/68107000/99217499-807f8180-281b-11eb-96d4-f53e5ab70c5a.png)

- **시간복잡도**

  (참고로 에지개수 = m)

  1. 최소 에지 선택
     - E의 에지들을 미리 정렬하여 사용할 경우, 정렬-O(mlogm), 최소 에지 선택-O(1)
     - E를 힙으로 구축하여 운영할 경우, 힙 구축-O(m), 최소 에지 선택(delemeMin)-O(logm)
  2. v ≡ w 테스트: O(log m)

  - **총 연산: O(mlogm)**

  - prim 알고리즘O(n^2)과 비교하면
    - 에지 수가 적은 그래프 : Kruskal의 알고리즘이 효율적
    - 에지 수가 많은 그래프 : Prim 알고리즘이 효율적

## 5) 최단경로 – Dijkstra의 알고리즘

- **개념**

  - 그래프에서 정점 u로부터 정점 v로 가는 경로 중에서 최단 경로란 **경로를 구성하는 에지들의 가중치 합이 최소가 되는 경로**(유일하지 않을 수 있음)
  - 가중치가 음수이면 dijkstra algorithm은 올바른 결과를 구할 수 없음.
  - 시작 정점으로부터 다른 모든 정점까지의 최단 경로도 찾을 수 있음
    - Single-Source Single-Destination Problem 
    - Single-Source All-Destination Problem 

- **예시**

  모든 정점에 대한 문제로 풂.

  ![image](https://user-images.githubusercontent.com/68107000/99216844-0ef30380-281a-11eb-9299-076330867a39.png)

  ![image](https://user-images.githubusercontent.com/68107000/99216866-19150200-281a-11eb-88e1-3451bd35920f.png)

- **알고리즘**

  수행 중 정점들의 분류 범주

  - 트리 정점 : 현재까지 구성된 최단 경로 트리 내의 정점 (집합 S) 
  - 그 이외의 정점 : 트리 정점 이외의 정점 

  1차원 배열 - distance[]

  - distance 배열의 초기값(시작 정점 v): distance[v] = 0 
  - 정점이 집합 S에 있는 경우 : 시작 정점 v에서 그 정점까지의 최단경로  - 이미 계산됨
  - 정점이 집합 S에 없는 경우 : 시작 정점 v에서 S에 있는 정점들을 통해 그 정점까지 가는 잠정적인 최단경로

  매 단계에서 S에 속해있지 않은 정점들 중에서 distance값이 가장 작은 정점을 S에 추가

  새로운 정점 u가 S에 추가되면 distance값 갱신

  ```c
  // 입력: 가중치 그래프 G, 가중치는 음수가 아니라고 가정
  // 출력: distance 배열, distance[u]는 시작 정점 v에서 u까지의 최단 거리이다.
  shortest_path(G, v)
      
  S←{v} // v 방문
  for 각 정점 w∈G do
  	distance[w]←weight[v][w];
  
  while 모든 정점이 S에 포함되지 않으면 do
  	u ← 집합 S에 속하지 않는 정점 중에서 최소 distance 정점;
  	S←S∪{u} // u 방문
      for u에 인접하고 S에 있지 않은 각 정점 z do
          if distance[u]+weight[u][z] < distance[z]
          then distance[z] ← distance[u] + weight[u][z];
  ```

- **시간 복잡도**

  - 자료구조 : Prim의 최소 스패닝 트리 알고리즘과 유사

  - 시간복잡도 : 𝑂(n^2) (정점의 개수가 𝑛일 때) 

    주 반복문을 n-1번 반복, 내부 반복문 2*𝑛번(1: choose, 2: distance[u] 재계산)

## 6) 위상정렬

- **사이클이 없는 방향 그래프(DAG : Directed Acyclic Graph)** 의 위상정렬
  - DAG에서 에지 <u, v>가 있다면 **정점 u는 정점 v를 선행함**
  - 방향 그래프 정점들의 선행 순서를 위배하지 않으면서 모든 정점을 순서적으로 나열

- **예시**

  ![image](https://user-images.githubusercontent.com/68107000/99215024-1bc12880-2815-11eb-9152-4ceb3fd3ad07.png)

  위상 순서: (0 1 2 3 4 5), (1 0 2 3 4 5), (1 0 4 2 3 5), (0 1 4 2 3 5)

  위상 순서 아님: (2 0 1 3 4 5) - 2번 정점이 0번 정점 앞에 오기 때문이다.

  stack을 사용한다면 1 4 0 2 3 5

  queue를 사용한다면 0 1 2 4 3 5

  ![image](https://user-images.githubusercontent.com/68107000/99215201-968a4380-2815-11eb-9c1d-d2678d70d412.png)

  stack을 사용한다면 0 1 2 3 5 4

  queue를 사용한다면 0 1 2 3 4 5

  5와 4는 선행관계가 없으므로 자료구조를 선택하는 것에 따라 순서가 달라진다.

- **위상정렬 알고리즘**

  1. 진입 차수가 0인 임의의 정점(**선행자가 없는 임의의 정점**) 출력
  2. 출력한 정점에 부착된 모든 **에지들을 제거**하여 **진입 차수 재계산**
  3. 모든 정점이 제거될 때까지 1~2 반복
  4. 진입 차수가 0인 것이 없으면, 그래프가 사이클을 포함한 것으로서 해가 존재하지 않음

```c
Input: 그래프 G=(V,E)
Output: 위상정렬 순서

top_sort(G)
for i←0 to n‐1 do
    if( 모든 정점이 선행 정점을 가지면 )
    	then 사이클이 존재하고 위상 정렬 불가;
    선행 정점을 가지지 않는 정점 v 선택; (저장 : 스택이나 큐 사용)
	v를 출력;
	v와 v에서 나온 모든 방향 에지들을 그래프에서 삭제;
```

