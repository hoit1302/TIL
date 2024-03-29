## 접근 제한자

- **public**: 외부 클래스가 자유롭게 사용.
- **protected**: 같은 패키지 또는 **상속 받은 자식 클래스**에 사용.
- **default**: 같은 패키지에 소속된 클래스에서만 사용.
- **private**: 오직 클래스 내부에서만 접근 
  - -> getter, setter 활용.
  - 외부에서 객체에 마음대로 접근할 경우 객체의 무결성이 깨질 수 있음

## 상속(inheritance)

```java
class Student-자식클래스 extends People-부모클래스 {
    // 내용
}
```

클래스 재사용과 확장을 통한 소프트웨어 생산성 향상

**상속과 생성자**

자식 객체를 생성할 때 부모클래스의 생성자를 호출하여 먼저 실행되고 자식 생성자가 실행됨

명시적으로 부모 클래스의 생성자 호출하는 경우

```java
super();
super(param1, param2);
```



## 오버라이딩(@Override)

자식 클래스에서 메소드를 재정의, 즉 수정하여 사용

방법: 부모 메소드와 동일한 시그니처를 가지고 접근 제한을 더 강하게(좁은 범위로) X

부모 클래스 메소드를 호출해야 하는 경우

```java
super.showInfo();
```



