## 배열

"자료형이 같은 자료들을 하나로 묶는 방법"

- 1차원 배열

  int A[6];

- 문자열

  ```c
  char s[12] = "game over";
  ```

  '\0': terminating null characters (ASCII 코드: 00000000)

  strcmp(), strcpy(), strcat(), strlen(), 등. <string.h> 포함 (또는 <cstring>)

- 2차원 배열

  행 우선(row major)

  ```c
  int A[4][3];
  ```

  ```c
   A[row][col]에서 A[j][k]의 실제 주소
   base + (j*col + k) * sizeof(int)
  ```

  다차원 배열로 확장 가능

  ```c
   A[dep][row][col]에서 A[i][j][k]의 실제 주소
   base + (i*row*col + j*col + k) * sizeof(int)
  ```

- 배열의 응용

  - 다항식(polynomial) 표현 방법 (코드 참고!)

    방법1) 다항식의 index를 모든 항에 대한 정보를 배열에 저장

    - 하나의 다항식을 하나의 배열로 표현
    - 모든 항의 계수(coefficient) 값을 배열에 저장

    방법2) 희소 다항식

    - 다항식의 0이 아닌 항만 저장
    - (계수, 차수) 형식으로 배열에 저장
    - 하나의 배열로 여러 개의 다항식을 나타낼 수 있음

    

  - 희소 행렬(sparse matrix: 대부분의 항들이 0인 행렬) 표현 방법

    방법1) 2차원 배열을 이용하여 배열의 전체 원소를 저장

    - 장점: 행렬의 연산들을 간단하게 구현
    - 단점: 메모리 공간 낭비

    방법2) 0이 아닌 원소들만 저장

    - 장점: 희소 행렬의 경우, 메모리 공간의 절약
    - 단점: 각종 행렬 연산들의 구현이 복잡



## 구조체

"자료형이 다른 자료를 하나로 묶는 방법"

```c
typedef struct person {
    char name[10];
    int age;
    float height;
};
struct person a;
```

```c
typedef struct _person {
    char name[10];
    int age;
    float height;
    struct _person *link; // 자기참조 구조체 self-referential structure
} person;
person a, b;

main() {
	b = a;  // 구조체 변수의 대입: 가능
    if (a>b)// 구조체 변수끼리의 비교: 불가능
}
```

## 포인터

"다른 변수의 주소를 가지고 있는 변수"

- 연산자

  *: 포인터가 가리키는 곳의 내용을 추출

  &: 변수의 주소를 추출

  ```c
   p     // 포인터의 값(주소)
  *p     // 포인터가 가리키는 값
  *p++   // == *(p++) 우선순위가 ++이 더 높음
  *p--   // 포인터가 가리키는 값을 가져온 다음, 
         //포인터가 한칸 감소한다.
  (*p)++ //포인터가 가리키는 값을 증가시킨다.
  ```

- call by value

  ```c
  void swap(int* px, int* py) {
      int tmp;
      tmp = *px;
      *px = *py;
      *py = tmp;
  }
  ```

- 배열과 포인터

  컴파일러가 배열의 이름은 배열의 첫번째 주소로 대치.

  ```c
  A == &A[0];
  A[1] == *(A+1)
  ```

- 포인터의 포인터

  ```c
  int a = 7;
  int* p;
  p = &a;
  int** pp; // 포인터를 가리키는데 그 내용도 int형 포인터야.
  pp = &p;
  printf("%d", **pp); // 7 출력
  ```

- 포인터 연산

  ```c
  int A[5];
  int* p = &(A[3]); // A[3]가 0x1008이면
  *(p+1)	// A[4] (0x100c) 포인터 p가 가리키는 객체의 바로 뒤 객체
  *(p-1) // A[2] (0x1004)포인터 p가 가리키는 객체의 바로 앞 객체
  ```

- 주의할 점

  - 포인터가 아무것도 가리키고 있지 않을 때는 NULL로 설정

  ```c
  int* pi = NULL;
  ```

  - 초기화가 안된 상태에서 사용 금지

  ```C
  main() {
  	char* pc;  // 값 지정 X
  	*pc = 'E'; // 위험한 코드
  }
  ```

  - 포인터 타입 간의 변환 시에는 명시적인 타입 변환 사용

  ```c
  int* pi;
  float* pf;
  pf = (float*) pi;
  ```

  

## 동적 메모리 할당

- 프로그램이 메모리를 할당 받는 방법

  - 정적 메모리 할당 **"static"**

    - 메모리의 크기는 프로그램이 시작하기 전에 결정

    - 프로그램의 수행 도중에 그 크기가 변경될 수 없음

    ```c
    int buffer[100];
    char name[] = "data structures";
    ```

    

  - 동적 메모리 할당 **"dynamic"**

    - 프로그램의 실행 도중에 메모리를 할당 받는 것
    - 필요할 때 필요한 만큼 할당을 받아 사용하고, 필요 없으면 반납
    - 메모리를 매우 효율적으로 사용 가능

- 예제

  ```C
  #include <stdlib.h>
  struct Example {
      int number;
      char name[10];
  }
  void main() {
      struct Example* p;
      // 구조체 2개 크기 할당
      p = (struct Example*)malloc(2*sizeof(struct Example));
      if (p == NULL) {
          fprintf(stderr, "can't allocate memory\n");
          exit(1);
      }
      p->number = 1;
      strcpy(p->name, "Jueun Park");
      (p+1)->number = 2;
      strcpy((p+1)->name, "Kim");
      free(p);
  }
  ```

  size_t 는 unsigned integer

