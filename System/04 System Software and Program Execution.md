# program EXECUTION 

![04-1](https://user-images.githubusercontent.com/68107000/95711342-85419a80-0c9d-11eb-9f4d-b5dd1771d644.PNG)

<br>

## program execution과 관련한 System Software

- 컴파일러(compiler)
- 어셈블러(assembler)
- 링커(linker)
- 로더(loader)

+) 상용 컴파일러 소프트웨어(**gcc, visual c**)가 <u>컴파일러, 어셈블러, 링커 등을 내포</u>하고 있어 소스파일에서 실행 파일 변환이 **한 번에** 이루어짐 ( = make한다)

+) 로더 기능은 운영 체제에 포함되어 수행된다.

<br>

## programming language

- **고급 언어(high level language)**

  <u>machine independent</u> - 시스템의 종류에 무관

  인간이 이해하기 가장 쉬운 언어

  어셈블리 언어나 기계어로 변환시켜주는 소프트웨어 필요

  - compiler (C)
  - interpreter (Java)

  ```c
  temp = v[k];
  v[k] = v[k+1];
  v[k+1] = temp;c
  ```

  <br>

- **어셈블리 언어(Assembly language)**

  <u>machine dependent</u> - 시스템에 따라

  0과 1의 조합을 상징적인 코드로 변환하여 인간의 이해도를 향상

  Machine language와 1대 1 매핑

  ```assembly
  lw $to 0($2)
  lw $t1 4($2)
  sw $t1 0($2)
  sw $t0 4($2)
  ```

  <br>

- **기계어(Machine language)**

  <u>machine dependent</u> - 시스템에 따라

  컴퓨터가 직접 이해 가능한 언어

  ```m
  0000 1001 1100 0110 1010 1111 0101 1000
  1010 1111 0101 1000 0000 1001 1100 0110 
  1100 0110 1010 1111 0101 1000 0000 1001 
  0101 1000 0000 1001 1100 0110 1010 1111
  ```

  <br>

## Linker

### separate Compile

- 코드

> File “**one.c**” ㅡ> one.o
>
> ```c
> int x;
> char y;
> 
> add(void){
>     extern int z;		// 선언. extern: 내 파일 외에 어딘가 있어~
>     x++ 
>     y++
>     z--;
>     z++;
>  }
> ```

> File “**two.c**” ㅡ> two.o
>
> ```c
> int z = 6;				// 구현
> ```

<br>

- separate compile: ㅡ> object file (.o or .obj)

  변수, 함수의 위치 불명확, type만 파악

  - > **one.o**
    >
    > Symbol Table
    >
    > | **Symbol** | **Address** | **Type**       |
    > | ---------- | ----------- | -------------- |
    > | add        | 0x0420      | function       |
    > | x          | 0x00f0      | int            |
    > | y          | 0x00f4      | char           |
    > | **z**      | **0x????**  | **extern int** |
    >
    > ```assembly
    > Symbol Table
    > 
    > (z--;는 아래와 같이)
    > load r1, ????
    > sub r1, 1
    > store r1, ????
    > 
    > (z++;는 아래와 같이)
    > load r1, ????
    > add r1, 1
    > store r1, ????
    > ```

<br>

- linking: ㅡ> executable file (.out or .exe)

  변수, 함수의 위치 명확

  - > **one.o**
    >
    > Symbol Table
    >
    > | **Symbol** | **Address** | **Type**       |
    > | ---------- | ----------- | -------------- |
    > | add        | 0x0420      | function       |
    > | x          | 0x00f0      | int            |
    > | y          | 0x00f4      | char           |
    > | **z**      | **0x10a4**  | **extern int** |
    >
    > ```assembly
    > Symbol Table
    > 
    > (z--;는 아래와 같이)
    > load r1, 10a4
    > sub r1, 1
    > store r1, 10a4
    > 
    > (z++;는 아래와 같이)
    > load r1, 10a4
    > add r1, 1
    > store r1, 10a4
    > ```

<br>

### Header

✨ extern이 많을 때는 어떻게 해야하나요?

✨ header file을 사용하여 코드 수정이 쉽도록!

- **cpp**

  - "c preprocessor (전 처리기)"
  - cpp는 컴파일 전에 작동함.
  - header 파일 내용을 치환해줌.
  -  x의 자료형 바꾸기
    1. extern <u>char</u> x; // 1번만 바꾸면 됨
    2. cpp는 헤더 파일이 포함된 파일을 찾아서
    3. #include "x.h" ㅡ> 치환
    4. 이제 gcc compiles

  

> *<u>At coding time</u>*
>
> x.h
>
> ```c
> extern char x;
> ```
>
> a.c
>
> ```c
> char x;
> x = 0;
> ```
>
> b.c
>
> ```c
> # include "x.h"
> x++;
> ```
>
> c.c
>
> ```c
> # include "x.h"
> x--;
> ```

<br>

> *<u>After cpp</u>*
>
> a.c
>
> ```c
> char x;
> x = 0;
> ```
>
> b.c
>
> ```c
> extern char x;
> x++;
> ```
>
> c.c
>
> ```c
> extern char x;
> x--;
> ```

<br>

## Library

```c 
#include <stdio.h>
```

헤더 파일에는 라이브러리 함수의 선언만 있음

함수의 argument 및 return type을 알려줌

*<u>**실제 함수의 정의는 라이브러리 파일에 있음**</u>*

<br>

### "Static Linking" vs "Dynamic Linking"

![04-2](https://user-images.githubusercontent.com/68107000/95711343-85da3100-0c9d-11eb-860e-5882796bd2d7.PNG)

<br>

#### Static Linking

- **Static Library**
  - *.o
  - link time동안 함수들이 .out or .exe에 복사된다
  - binding(= Linking): compile time(넓은 의미의 컴파일)
- 라이브러리가 프로그램의 실행 파일 코드에 <u>포함</u>됨 **(static library)**

- 실행 <u>파일의 크기가 커짐</u>

- 동일한 라이브러리를 각각의 프로세스가 메모리에 올리므로 <u>메모리 낭비</u> 
  (예: printf 함수의 라이브러리 코드)

<br>

#### Dynamic Linking

- **Shared Library**
  - *.so
  - 함수들이 복사되지 않는다. Just map
  - 실행할 때 공유 라이브러리를 요구하고 로딩된다.
  - binding(= Linking): loading or run time
  - 장점
    - less memory space
  - 단점
    - 실행파일(?)을 줘도 library가 있는지, 같은 버전인지 신경 써야함
    - 조금 느림
    - heavy
- 라이브러리가 실행 시(: <u>로더</u>에 의해 로딩될 때) link됨 **(shared library, 확장자는 .so)**

- 실행 파일에는 라이브러리 자체가 포함되는 것이 아니라 
  라이브러리의 <u>위치를 찾기 위한 간단한 코드</u>만 둠

- 라이브러리가 이미 메모리에 있으면 그 루틴의 주소로 가고, 없으면 디스크에서 읽어옴 



