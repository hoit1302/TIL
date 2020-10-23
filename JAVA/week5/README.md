## 추상클래스 abstract

"추상클래스를 상속받아서 자식이 그 기능을 이용하고 확장한다" 

### 목적

- 상속을 위한 슈퍼 클래스로 활용하는 것

- 서브 클래스에서 추상 메소드 구현
- 다형성 실현

```java
// 미완성된 클래스. 객체 생성 불가
abstract public class Shape {
//	 멤버 변수
//	 일반 메소드 정의
//	 생성자 정의

//	 추상메소드 선언
	abstract double getArea();
	abstract double getPerimeter();
	abstract void showInfo();
}


public class Rectangle extends Shape {
	//추상메서드 반드시 구현
	@Override (재정의)
	double getArea() {
		return length * width;
	}
	@Override
	double getPerimeter() {
		return 2 * (length + width);
	}
	@Override
	void showInfo() {
		System.out.println("면적:" + getArea());
		System.out.println("둘레:" + getPerimeter());
	}
}

```
<br>
✨Q 여러 클래스가 3개의 공통 기능과 1개의 다른 기능을 포함해야한다.

✨A 추상클래스에서 3개의 공통 기능은 일반 메소드로 작성하고 1개의 다른 기능은 추상메소드로 둔다. 구현 시 추상메소드만 다르게 구현하여 효율적으로 코드를 작성한다.
<br>

## 인터페이스 interface

"메소드의 구현을 강제함으로써 구현 객체의 같은 동작을 보장시킬 수 있다"

상수와 추상메소드로 이뤄진다.

```java
interface RemoteControl1 {
        // 상수 필드
	static final int MAX_VOLUME = 10;
	int MIN_VOLUME = 0; //static final을 생략 가능. (컴파일러에 의해)
    
    // 추상 메서드, interface memeber는 public abstract이 디폴트
    void turnOn();
	void turnOff();
	void setVolume(int volume);
}
interface RemoteControl2 {	}

public class Television implements RemoteControl1, RemoteControl2 {
   	// 구현
}

interface control extends RemoteControl1, RemoteControl2{
    
}
```

- **다중 상속**이 가능 !

