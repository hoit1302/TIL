# 패키지

## 패키지 개념과 필요성

패키지는 **비슷한 종류의 클래스나 인터페이스들을 하나의 집단으로 묶어 놓은 것**을 말한다.

- 클래스 간의 **이름 중복**으로 발생하는 **충돌을 막아**준다. 이름이 같더라도 경로명이 달라 서로 다른 파일로 취급한다.
- 클래스를 **기능 별로 분류**할 수 있어 필요한 **클래스의 식별이 용이**하다. 사용이 편리해진다.



## 패키지 사용하기

다른 패키지에 작성된 클래스를 사용하기 위한 방법은 3가지가 있다.

- import를 이용하지 않는 경우

  - 소스에 **클래스 이름의 완전 경로명** 사용한다.

  ```java
  public static void main(String[] args) {
  	java.util.Scanner in = new java.util.Scanner(System.in);
  }
  ```

- 필요한 클래스만 import하는 경우

  - **import 패키지.클래스**
  - 소스 시작 부분에 클래스의 경로명을 import한다.
  - 소스에는 클래스 명만 명시하면 된다.

  ```java
  import java.util.Scanner;
  public static void main(String[] args) {
  	Scanner in = new Scanner(System.in);
  }
  ```

- 패키지 전체를 import하는 경우

  - **import 패키지.***
  - 소스 시작 부분에 패키지 경로명.*을 import한다.
  - 소스에는 클래스 명만 명시하면 된다.
  - java.util.* 할 경우, java.util 패키지 내의 모든 클래스만을 지정한다. **소스 시작 부분에 클래스의 경로명을 import한다.**

  ```java
  import java.util.*;
  public static void main(String[] args) {
  	Scanner in = new Scanner(System.in);
  }
  ```

  

## 패키지 만들기

- **클래스 파일(.class)이 저장**되는 위치는?

  - 클래스나 인터페이스가 **컴파일**되면 **클래스 파일 생성**
  - 클래스 파일은 **패키지로 선언된 디렉터리에 저장**

- 패키지 선언

  - 소스 파일의 맨 앞에 컴파일 후 저장될 패키지 지정

  - ```java
    package packageName;
    ```



## JDK 주요 패키지

- **java.lang**
  - 자동으로 import 됨 - import 문 필요 없음
  - 스트링, 수학 함수, 예외처리 등 자바 프로그래밍에 필요한 기본적인 클래스와 인터페이스
    - String, StringBuffer, Object, Wrapper, Class, Math, System, Runtime 클래스
- **java.util**
  - 날짜, 시간, 벡터, 해시맵 등과 같은 다양한 유틸리티 클래스와 인터페이스 제공
    - Arrays, Random, Calendar 클래스
    - Arrays.binarySearch(arr, 40);
    - Calendar.YEAR
- **java.io**
  - 키보드, 모니터, 프린터, 디스크 등에 입출력을 할 수 있는 클래스와 인터페이스 제공
- **java.awt**
  - GUI 프로그램을 작성하기 위한 AWT 패키지
- **javax.swing**
  - GUI 프로그래밍을 작성하기 위한 스윙 패키지



# 예외처리

## 예외(Exception)

- 뜻: 프로그램 실행 중에 발생되는 비정상적인 상황

- 종류
  - 컴파일 시에 발생하는 에러
  - 런타임 시에 발생하는 에러
    - 객체를 선언만 하고 생성하기 전에 참조를 한 경우
    - 0으로 정수를 나눴을 경우
    - 배열의 크기에 벗어난 인덱스를 접근한 경우
    - 파일을 접근을 하려고 하는데 실제 파일이 없는 경우
    - 등



## try-catch 블록

예외처리: 발생한 예외에 대해 개발자가 작성한 프로그램 코드에서 대응하는 것

```java
try{
    // 예외가 발생할 가능성이 있는 실행문
} catch(처리할 예외 타입 선언){
    // 예외 처리문
} finally {
    // 예외 발생 여부와 상관없이 무조건 실행되는 문장, 생략가능
}
```



## 자바 예외 클래스

![image](https://user-images.githubusercontent.com/68107000/96240489-ed64e900-0fdb-11eb-9b19-a2c9756ebd9a.png)