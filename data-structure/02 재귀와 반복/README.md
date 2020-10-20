# 2장 재귀와 반복

## 재귀

- 알고리즘이나 프로그램이 수행 도중에 **자기 자신을 다시 호출**하여 문제를 해결하는 기법(순환 또는 되부름이라고도 함)
- 문제의 정의가 재귀적으로 되어 있거나, 문제해결을 위한 자료구조가 재귀적으로 정의되는 경우에 사용할 수 있는 방법
- **일반적으로** 시간 및 공간 사용이 반복문 사용에 비해 **비효율적**임
- 대부분의 재귀는 반복문을 사용하여 작성할 수 있음

### 재귀 호출 중의 시스템 스택의  저장 내용

- 지역 변수 및 인수의 값들

- 복귀 주소

### 재귀 알고리즘의 구조

- 재귀 호출을 하는 부분
- 재귀 호출을 멈추는 부분 ㅡ> 없다면 시스템 오류 중 하나인 stack overflow가 발생할 때까지 무한정 호출



### 재귀(Recursion) vs 반복(Iteration)

컴퓨터에서의 되풀이(again and again, over and over) : 재귀와 반복

- **재귀** : 재귀 호출 이용
  - 재귀적인 문제에서는 자연스러운 방법
  - 함수 호출의 **오버헤드(overhead-부가적인 연산 및 기억 공간)**가 있음
- **반복** : for문이나 while문, repeat문 등을 이용
  - 수행 속도가 빠름
  - 문제 자체가 재귀적인 경우는 프로그램 작성이 어려울 수도 있음

## 계승(factorial)

### 반복적 정의와 프로그램

```c
int factorial_iter(int n) {
    int i, fact = 1;
    for (i = n; i > 0; i--)
        fact = fact * i;
    return(fact);
}
```

- **공간복잡도**![image](https://user-images.githubusercontent.com/68107000/96525099-0825af00-12b5-11eb-9449-0792d9ea49e9.png)(n, i, fact로 3)

- **시간복잡도** ![image](https://user-images.githubusercontent.com/68107000/96525155-30ada900-12b5-11eb-9d96-c21baef0d840.png) (기본 연산 : 정수 곱셈)

### 재귀적 정의와 프로그램

```c
int factorial(int n) {
    if (n == 0) return 1;
    else return n * factorial(n‐1);
}
```

- **공간복잡도**  ![image](https://user-images.githubusercontent.com/68107000/96525311-871ae780-12b5-11eb-957e-6fbcda9a11de.png)(재귀 호출과 시스템 스택 이해 필요)

- **시간복잡도**

  ![image](https://user-images.githubusercontent.com/68107000/96525515-1a541d00-12b6-11eb-85a4-5d844327d9c9.png)



## 이진 탐색

자료가 **배열(array)에 정렬**된 상태에서는 **이진 탐색(binary search)이 매우 효율적**임

(가장 간단한 탐색 알고리즘은 순차 탐색(sequential search, 선형 탐색)으로서 𝑛개의 자료를 순서대로 하나씩 탐색하는 방법)

- 이진 탐색은 찾고자 하는 키(key) 값과 전체 자료의 중앙에 있는 자료를 비교한다. 
- 만약 일치하지 않는다면 찾고자 하는 키값은 앞부분 또는 뒷부분 중 어느 한 곳에 있음.
- 따라서 한번 탐색 후 다시 탐색할 자료 개수가 약 ½로 감소



```C
binary_search(key, low, high)
    if (low <= high) {
        middle ← (low + high)/2
        if( key == list[middle] ) return middle;
        else if (key < list[middle] )
            return binary_search(key, low, middle-1);
        else return binary_search(key, middle+1, high)
    }
    else return-1
```

- **시간복잡도** 
  - 기본 연산: 키값과 원소의 비교
  - 최악의 경우, n=2^k라고 가정
  - ![image](https://user-images.githubusercontent.com/68107000/96528570-0b716880-12be-11eb-915d-e629b0be973c.png)
- **공간복잡도**   ![image](https://user-images.githubusercontent.com/68107000/96528757-702cc300-12be-11eb-875c-a166c81ea738.png)



## 피보나치 수열

피보나치 수열: 0 1 1 2 3 5 8 13 21 34 55 ⋯

피보나치 수: ![image](https://user-images.githubusercontent.com/68107000/96526995-05798880-12ba-11eb-82d2-d62053a15a80.png)

### 재귀 알고리즘

```C
int fib(int n) {
    if (n==0 or n==1) return n;
    return (fib(n‐1) + fib(n‐2));
}
```

- **시간복잡도** ![image](https://user-images.githubusercontent.com/68107000/96528190-019b3580-12bd-11eb-9bed-8615ab455c1b.png) (기본 연산: 정수 덧셈)
- **공간복잡도** ![image](https://user-images.githubusercontent.com/68107000/96527610-75d4d980-12bb-11eb-9748-8c1bdc4c995b.png)
  - 재귀 호출을 사용했을 경우의 비효율성
  - ![image](https://user-images.githubusercontent.com/68107000/96527647-956c0200-12bb-11eb-9e16-05dae51d70ee.png)
    - 같은 항을 여러 번 중복해서 계산함
    - 이러한 현상은 𝑛이 커지면 훨씬 더 심해짐

### 반복 알고리즘

```C
fib_iter(int n) {
    if (n==0 or n==1) return n;
    else {
        int i, fn, fn1=1, fn2=0;
        for(i=2; i<=n; i++){
            fn = fn1 + fn2;
            fn2 = fn1;
            fn1 = fn;
        }
    return fn;
    }
}
```

- **시간복잡도**![image](https://user-images.githubusercontent.com/68107000/96527203-8e90bf80-12ba-11eb-8269-5ae59deb83cb.png)(기본 연산: 정수 덧셈)
- **공간복잡도** ![image](https://user-images.githubusercontent.com/68107000/96527216-96e8fa80-12ba-11eb-88f9-3864ded79f21.png) (n, i, fn, fn1, fn2)



## 하노이 타워

![image](https://user-images.githubusercontent.com/68107000/96529417-0b726800-12c0-11eb-8821-f415a3a80ae5.png)

재귀 함수를 이용한 하노이 타워 의사코드

```pseudocode
// 말뚝 from에 쌓여있는 n개의 원판을 말뚝 aux를 사용하여 말뚝 to로 옮긴다.
void hanoi_tower(int n, char from, char aux, char to) {
    if (n==1) 
    	from에서 to로 원판을 옮긴다. (print from, to)
    else {
	    hanoi_tower(n-1, from, to, aux);                      // 1
    	from에 있는 한 개의 원판을 to로 옮긴다. (print from, to)  // 2
	    hanoi_tower(n-1, aux, from, to);                      // 3
    }
}

main() {
	hanoi_tower(5, 'A', 'B', 'C');
}
```

- **시간복잡도** (기본 연산: move, print)

  ![image](https://user-images.githubusercontent.com/68107000/96529791-fb0ebd00-12c0-11eb-9f60-3cfc658aab55.png)

- **공간복잡도** ![image](https://user-images.githubusercontent.com/68107000/96530152-c4857200-12c1-11eb-9d0b-ced902b56260.png)

