# 자바 스레드 기초

## 1. 스레드 개념

### **프로세스**

- 메모리를 할당 받아 실행중인 프로그램을 말한다.

### **스레드(thread)**

- 운영체제에 의해 관리되는 하나의 작업 혹은 태스크를 말한다.
- 스레드와 태스크(혹은 작업)은 바꾸어 사용해도 무관하다.
- 프로그램인 동시에, 여러 작업을 실행할 목적으로 생성한 실행과 흐름의 단위로, 경량 프로세스를 말한다.

### **멀티스레딩(multi-threading)**

- 여러 스레드를 동시에 실행시키는 응용프로그램을 작성하는 기법이다.

### **스레드 구성** 

- **스레드 코드** 
  - 작업을 실행하기 위해 작성한 프로그램 코드 
  - 개발자가 작성
- **스레드 정보** 
  - 스레드 명, 스레드 ID, 스레드의 실행 소요 시간, 스레드의 우선 순위 등 
  - 운영체제가 스레드에 대해 관리하는 정보



### 자바 스레드

- 자바 가상 기계(JVM)에 의해 스케쥴되는 실행 단위의 코드 블럭

- 스레드의 생명 주기는 JVM에 의해 관리됨 : JVM은 스레드 단위로 스케쥴링 

- 하나의 JVM은 하나의 자바 응용프로그램만 실행한다.

  - 자바 응용프로그램이 시작될 때 JVM이 함께 실행된다.
  - 자바 응용프로그램이 종료하면 JVM도 함께 종료된다. 

- 응용프로그램은 하나 이상의 스레드로 구성이 가능한다.


자바의 모든 애플리케이션은 메인 스레드가 main()메소드를 실행하면서 시작한다.

메인스레드는 main() 메소드의 첫 코드부터 아래로 순차적으로 실행하고, main()메소드의 마지막 코드를 실행하거나 return문을 만나면 실행이 종료된다. 

하나의 프로그램에서 여러 가지 작업(스레드)을 동시에 할 수 있다. 모든 자바 프로그램은 적어도 하나의 스레드(main 스레드)를 가지고 있으며, 필요하다면 추가적인 스레드를 생성할 수 있다.

------

## 2. 스레드 구현 방법

(참고사항) - JAVA의 lang 패키지는 JAVA 프로그래밍에 필요한 가장 기본적인 클래스들이 모여있는 패키지이다. import구문으로 호출해야 사용할 수 있는 다른 패키지들과는 달리 lang패키지는 import구문 없이도 자동으로 프로그램에 포함된다.

### 2-1. java.lang.Thread 클래스를 상속받아 스레드 작성

```java
public class MyThread1 extends Thread {

	// 스레드 코드 꼭 재정의 해주어야 한다.
	@Override 
	public void run() { // public 지우면 error. 상속받은 Thread에서 run()이 public으로 정의되어 있기 때문에 접근 지정자를 줄이면 안된다.
		for (int i = 10; i >= 1; i--) {
			System.out.print(i);
			try {
				sleep(1000); // Thread class에서 제공하는 정적 메소드, 단위는 ms
				// 실행 중인 스레드를 잠시 멈추게 할 수 있음.
			} catch (InterruptedException e) {
				e.printStackTrace();
			} 
		}
	} // run() 메소드가 종료하면 스레드는 종료된다.

	public static void main(String[] args) {
		MyThread1 t = new MyThread1();
		t.start(); // 자동으로 run method 호출
	}
}
```



###  2-2. java.lang.Runnable 인터페이스를 구현하여 스레드 작성

```java
// #1 Runnable 인터페이스를 구현한 클래스 작성
public class MyRunnable implements Runnable {

	// 반드시 run() 메서드 구현
	@Override
	public void run() { 
		for (int i = 10; i >= 1; i--) {
			System.out.print(i);
			try {
				Thread.sleep(1000); // Thread class에서 제공하기에.
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}

	public static void main(String[] args) {
		// #2 스레드 객체 생성하고, 내가 만든 Runnable 객체를 Thread 생성자에게 넘겨준다. 
		Thread t = new Thread(new MyRunnable()); // 중요!
		// #3 스레드 시작
		t.start();
	}
}
```



### 그렇다면 스레드를 생성하기 위해서는 어떤 방법을 사용하는 것이 더 좋은가? 

Runnable 인터페이스를 사용하는 편이 더 일반적이다. 이유는 자바는 다중 상속을 지원하지 않기 때문이다. Runnable 객체는 Thread가 아닌 다른 클래스를 상속받을 수 있기 때문에 Thread클래스에서 상속받으면 다른 클래스를 상속받을 수 없다. 

------

## 3. 스레드 동기화 (Thread Synchronization)

멀티스레드 프로그램 작성 시 다수의 스레드가 공유 데이터에 동시에 접근하는 경우 공유 데이터의 값에 예상치 못한 결과가 발생할 수 있다.

멀티스레드의 공유 데이터의 동시 접근 문제 해결하는 방법에는 2가지가 있다.

첫번째 방법은 공유 데이터를 접근하는 모든 스레드를 한 줄로 세우는 것이다.

두번째 방법은 한 스레드가 공유 데이터에 대한 작업을 끝낼 때까지 다른 스레드가 대기 하도록 하는 것이다. 한 스레드에 독점 권한을 주는 것이다.

### **동기화란?**

스레드 사이의 실행순서 제어하여 공유데이터에 대한 접근을 원활하게 하는 기법이다.

자바의 스레드 동기화 방법에는 2가지가 있다.

- **synchronized 키워드로 동기화 블록 지정**
- wait()-notify() 메소드로 스레드의 실행 순서 제어

### **synchronized 키워드로 동기화 블록 지정**

**synchronized 키워드** 

- 임계 영역(criitical section) 표기 키워드 
- 스레드가 독점적으로 실행해야 하는 부분(동기화 코드)을 표시하는 키워드이다.
- 메소드 전체 혹은 코드 블록을 지정할 수 있다.

```java
synchronized void print(String text) { // 동기화 메소드
    ...
    for(int i=0; i<text.length(); i++)
    	System.out.print(text.charAt(i));
    ...
}
```

```java
void execute(String text) {
    ...
    synchronized(this) { // 동기화 코드 블록
        ...
        for(int i=0; i<text.length(); i++)
        	System.out.print(text.charAt(i));
        ...
    }
}
```

synchronized 블록이 실행될 때, 먼저 실행한 스레드가 모니터를 소유한다. 여기서 모니터란 해당 객체를 독점적으로 사용할 수 있는 권한을 말한다. 모니터를 소유한 스레드가 모니터를 내놓을 때까지 다른 스레드는 대기한다.