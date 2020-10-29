# 자바의 이벤트처리

## 개념

**이벤트의 발생에 의해 프로그램 흐름이 결정되는 방식** 

- **실행**될 코드는 **이벤트의 발생에 의해 전적으로 결정**된다.
- 프로그램의 개발자가 **프로그램의 흐름을 결정**하는 방식이다.
- **GUI 응용프로그램**은 **이벤트 기반 프로그래밍**으로 작성된다.
- 이벤트 종류
  - **사용자의 입력** : 마우스 드래그, 마우스 클릭, 키보드 누름 등
  - 센서로부터의 입력, 네트워크로부터 데이터 송수신
  - 다른 응용프로그램이나 다른 스레드로부터의 메시지

### 리스너 인터페이스

자바는 다양한 리스너 인터페이스 제공한다.

ActionListener (인터페이스)는 버튼 클릭 이벤트를 처리하기 위한 인터페이스로, 상속받으면 1개의 추상 메소드를 개발자가 구현해야 한다. 

```java
public interface ActionListener extends EventListener {
    /* Invoked when an action occurs. */
    public void actionPerformed(ActionEvent e);
}
```

MouseListener (인터페이스)는 마우스 조작에 따른 이벤트를 처리하기 위한 인터페이스로,  상속받으면 5개의 추상 메소드를 개발자가 구현해야 한다.

```java
public interface MouseListener extends EventListener {

    /* Invoked when the mouse button has been clicked (pressed and released) on a component. */
    public void mouseClicked(MouseEvent e);

    /* Invoked when a mouse button has been pressed on a component. */
    public void mousePressed(MouseEvent e);

    /* Invoked when a mouse button has been released on a component. */
    public void mouseReleased(MouseEvent e);

    /* Invoked when the mouse enters a component. */
    public void mouseEntered(MouseEvent e);

    /* Invoked when the mouse exits a component. */
    public void mouseExited(MouseEvent e);
}
```



### 이벤트 관련 용어

- **이벤트 소스** - **이벤트를 발생시킨 GUI 컴포넌트**
- **이벤트 객체** - 발생한 **이벤트에 대한 여러 정보**(이벤트 종류, 이벤트 소스, 화면좌표, 눌러진 키..)를 제공하는 객체
- **이벤트 리스너** - 사용자가 작성하며, 이벤트를 처리하는 **자바 프로그램 코드로 클래스**로 작성
- **이벤트 분배 스레드** - 무한 루프를 돌면서, 이벤트가 발생하면 이벤트 리스너를 찾아 호출하는 스레드로 자바 JVM에서 제공

### 이벤트 리스너 작성 과정

1.  이벤트를 처리할 **클래스 정의**

   ```java
   class MyActionListener implements ActionListener {
       // 버튼이 클릭될 때 호출되는 메소드
       public void actionPerformed(ActionEvent e) { 
   	    // 이벤트를 처리할 코드
       }
   }
   ```

2. 컴포넌트에 이벤트 **리스너 등록**

   component.addXXXListener(listener)

   XXX: 이벤트 명, listener: 이벤트 리스너 객체

   ```java
   MyActionListener listener =  MyActionListener(); // 리스너 인스턴스 생성
   btn.addActionListener(new listener); // 리스너 등록
   ```

## 독립 클래스

- 이벤트 리스너를 **완전한 클래스**로 작성

- 이벤트 리스너를 **여러 곳에서 사용할 경우**에 적합 

- 클래스의 각종 변수나 객체의 접근이 불편

- **Object getSource()**

  - 발생한 이벤트의 소스 컴포넌트를 리턴한다.
  - Object 타입으로 리턴하므로 캐스팅(형변환)하여 사용한다.
  - 모든 이벤트 객체에 대해 적용할 수 있다.

- ```java
  class MyListener implements ActionListener{
      @Override
      public void actionPerformed(ActionEvent e) { 
  		JButton btn = (JButton)e.getSource(); // Frame의 버튼에 직접 접근할 수 없음
          btn.setText("OK");
      }
  }
  
  class Frame extends JFrame{
      Frame() {
          JButton btn = new JButton("확인");
          // 리스너 등록
          btn.addActionListener(new MyListener());
      }
  }
  ```

## 내부클래스(inner class)

- **클래스 안에 멤버처럼** 클래스 작성

- 이벤트 리스너를 **특정 클래스에서만 사용할 경우**에 적합

- ```java
  class Frame extends JFrame {
      JButton btn;
      Frame() {
          // 생성자 내용
          // 리스너 등록
  		btn.addActionListener(new MyListener());
      }
      
      // Action 이벤트 리스너를 내부 클래스로 작성
      class MyListener implements ActionListener{
          @Override
          public void actionPerformed(ActionEvent e) { 
              // Frame의 멤버나 JFrame의 멤버에 대한 접근이 용이하다.
              setTitle("확인버튼을 눌렀습니다.");
          }
      }
  }
  ```

- 

## 익명 클래스(anonymous class)

- 클래스의 **이름 없이** 간단히 리스너를 작성할 때 이용한다.

- 클래스조차 만들 필요 없이 **리스너 코드가 간단한 경우**에 적합하다.

- 메소드의 개수가 1,2개인 리스너에 대해 주로 사용한다.

- ```java
  JButton btn = new JButton("확인");
  // 익명 클래스 리스너 등록
  btn.addActionListener(new ActionListener() {
     @Override
      public void actionPerformed(ActionEvent e) { 
          // AnonymousClassListener의 멤버나 JFrame의 멤버를 호출할 수 있음.
  	    setTitle("확인버튼을 눌렀습니다.");
      }
  });
  ```

## 어댑터 클래스(Adapter class)

- 리스너의 모든 메소드를 **단순 리턴**하도록 만든 클래스(JDK에서 제공)

- ![image](https://user-images.githubusercontent.com/68107000/97578951-d50db900-1a34-11eb-82bb-3bffbadbaa64.png)

- 이벤트 리스너의 모든 추상 메소드 구현에 따른 부담
  - 예) 마우스 리스너에서 마우스가 눌러지는 경우(mousePressed())만 처리하고자 하는 경우에도 나 머지 4 개의 메소드를 모두 구현해야 하는 부담
- 추상 메소드가 하나뿐인 리스너는 어댑터가 없다.
  - 예) ActionAdapter, ItemAdapter class는 존재하지 않는다.

### 마우스 이벤트 리스너 작성하기

#### 1 MouseListener 인터페이스 사용

```java
// 내부 클래스로 이벤트 리스너 작성
class MyMouse implements MouseListener {

    @Override
    public void mouseClicked(MouseEvent e) {   }

    @Override
    public void mousePressed(MouseEvent e) {
        int x = e.getX();
        int y = e.getY();
        lbl.setLocation(x, y);
        System.out.println("(" + x + ", " + y + ")");
        System.out.println(e);
    }

    @Override
    public void mouseReleased(MouseEvent e) {  }

    @Override
    public void mouseEntered(MouseEvent e) {  }

    @Override
    public void mouseExited(MouseEvent e) {  }

}
```

#### 2 MouseAdapter 클래스 사용

```java
// 내부 클래스로 이벤트 리스너 작성
class MyMouse extends MouseAdapter {
    @Override
    public void mousePressed(MouseEvent e) {
        int x = e.getX();
        int y = e.getY();
        lbl.setLocation(x, y);
    }
}
```

### JDK에서 제공하는 어댑터 클래스

![image](https://user-images.githubusercontent.com/68107000/97578473-2ec1b380-1a34-11eb-9b26-64f80a35fd97.png)

