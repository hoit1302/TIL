## java 메모리 영역

**jvm 가상머신은 운영체제에 종속적**

할당 받은 메모리 영역을 세부 영역으로 구분해서 사용

- **메소드 영역 = 클래스 영역 = 정적 영역**
+ 클래스에 대한 정보 (필드 정보 / 메소드 정보 / 메소드 / 생성자 코드)
  
+ 클래스 변수(static bariable)가 저장되는 영역
  
- **힙 영역** 

  * 객체와 배열

- **스택 영역** 

  * 지역 변수(기본 타입 변수, 참조(reference) 변수 - 배열 생성 후 참조 변수 포함)

  * 선언된 블럭 안에서만 스택에 존재하고 벗어나면 스택에서 제거

  * 초기화하지 않으면 오류.



## instance 멤버와 static 멤버

- **인스턴스 멤버**: 객체마다 가지고 있는 멤버(필드, 메소드), 객체를 생성 후 접근
- **정적 멤버**: 객체들이 공유하는 멤버, **static** 키워드 사용, 객체를 생성할 필요 없음

정적 메소드 선언 시(main) 내부에 인스턴스 멤버를 사용할 수 없음

정적 메소드에서는 정적 필드만 사용이 가능하고 정적 메소드만 호출이 가능



## Call By Value vs Call By Reference

- 값에 의한 호출 방식 = 기본자료형의 경우 인수의 값이 매개변수로 **복사**된다.

- 객체가 인자로 전달되는 경우 : 객체를 가리키는 주소가 전달됨 (배열도!)



## 객체 배열

뜻: 객체에 대한 레퍼런스를 원소로 갖는 배열

객체배열에는 객체에 대한 참조값이 저장됨

- 정적 배열 

  ```java
  Song[] songs = new Song[3];
  ```

- 동적 배열

  ```java
  List<Song> songs = ArrayList<Song>();
  ```
