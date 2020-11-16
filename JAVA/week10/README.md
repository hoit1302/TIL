# 스윙 컴포넌트 활용

## 키보드 이벤트 처리

- 키 이벤트는 사용자가 키보드를 이용하여 입력을 하는 경우 발생

- 키 이벤트를 받을 수 있는 조건

  - 모든 컴포넌트

  - **현재 포커스(focus)를 가진 컴포넌트가 키 이벤트 독점**

    - 컴포넌트나 응용프로그램이 키 이벤트를 독점하는 권한

    - ```java
      component.setFocusable(true); // component가 여러 개 있을 때 우선적으로 입력 받기 위해 설정
      component.requestFocus(); // componenent에 포커스 강제 지정
      ```

1. 이벤트 리스너 클래스 작성

   ```java
   class myKeyListener implements KeyListener{
       void keyPressed(KeyEvent e) { // 1 키를 누르는 순간
       	// 이벤트 처리 루틴
       }
       void keyTyped(KeyEvent e) { // 2 누른 키를 떼는 순간, Unicode 키인 경우에만 호출된다.
       	// 이벤트 처리 루틴
       }
       void keyReleased(KeyEvent e) { // 3 누른 키를 떼는 순간
       	// 이벤트 처리 루틴
       }
   }
   ```

2. 이벤트 리스너 등록

   ```java
   component.addKeyListener(new myKeyListener());
   ```

   

### 유니코드(Unicode) 키

- 국제 산업 표준
- 전 세계의 문자를 컴퓨터에서 일관되게 표현하기 위한 코드 체계
- 문자들에 대해서만 키 코드 값 정의
  - A~Z, a~z, 0~9, !, @, & 등
- 문자가 아닌 키 경우에는 표준화된 키 코드 값이 없다.
  - Function키, Home키, Up키, Delete키, Control키, Shift키, Alt키 등은 플랫폼에 따라 키 코드 값이 다를 수 있다.

### 가상 키(Vitual Key)

- 가상 키는 KeyEvent 클래스에 상수로 선언되어 있다.
- 가상 키의 일부 소개
  - ![image](https://user-images.githubusercontent.com/68107000/98619787-4740a080-2347-11eb-9c73-c4add9803b05.png)

### 가상 키와 입력된 키 판별

- **KeyEvent 객체**

  - 입력된 키 정보를 가진 이벤트 객체
  - KeyEvent 객체의 메소드로 입력된 키 판별

- **KeyEvent 객체의 메소드로 입력된 키 판별**

  - ```java
    char KeyEvent.getKeyChar()
    
    public void keyPressed(KeyEvent e) {
        if(e.getKeyChar() == 'q') System.exit(0);
    }
    ```

    - **키의 유니코드 문자 값 리턴** (Unicode 문자 키인 경우에만 의미 있음)
    - 입력된 키를 판별하기 위해 문자 값과 비교한다.

  - ```java
    int KeyEvent.getKeyCode()
        
    public void keyPressed(KeyEvent e) {
        if(e.getKeyCode() == KeyEvent.VK_F5) System.exit(0);
    }
    ```

    - **모든 키에 대한 정수형 키 코드 리턴**
    - 입력된 키를 판별하기 위해 가상키(Virtual Key) 값과 비교한다.

    

## 스윙컴포넌트 활용

### 스윙 컴포넌트의 공통 메소드

- **모양**

  ```java
  void setForeground(Color) // 전경색 설정
  void setBackground(Color) // 배경색 설정
  void setOpaque(boolean) // 불투명성 설정
  void setFont(Font) // 폰트 설정
  Font getFont() // 폰트 리턴
  ```

- **상태**

  ```java
  void setEnabled(boolean) // 컴포넌트 활성화-비활성화
  void setVisible(boolean) // 컴포넌트 보이기-숨기기
  boolean isVisible() // 컴포넌트의 보이는 상태 리턴
  ```

- **위치와 크기**

  ```java
  int getWidth() // 폭 리턴
  int getHeight() // 높이 리턴
  int getX() // x 좌표 리턴
  int getY() // y 좌표 리턴
  Point getLocationOnScreen() // 스크린 자표상에서의 컴포넌트 좌표 리턴
  void setLocation(int, int) // 위치 지정
  void setSize(int, int) // 크기 지정
  ```

- **컨테이너**

  ```java
  Component add(Component) // 자식 컴포넌트 추가
  void remove(Component) // 자식 컴포넌트 제거
  void removeAll() // 모든 자식 컴포넌트 제거
  Component[] getComponents() // 자식 컴포넌트 배열 리턴
  Container getParent() // 부모 컨테이너 리턴
  Container getTopLevelAncestor() // 최상위 부모 컨테이너 리턴
  ```

### JLabel

- 문자열이나 이미지를 화면에 출력하기 위한 목적.

- 생성자

  - ```java
    JLabel() // 빈 레이블
    JLabel(Icon image) // 이미지 레이블
    JLabel(String text) // 문자열 레이블
    JLabel(String text, Icon image, int hAlign) // 문자열과 이미지를 모두 가진 레이블
    ```

    - hAlign(수평 정렬 값): SwingConstants.LEFT, SwingConstants.RIGHT, SwingConstants.CENTER

###  JButton

- 버튼 모양의 컴포넌트. 사용자로부터 명령을 입력 받기 위한 목적.

- 생성자

  - ```java
    JButton() // 빈 버튼
    JButton(Icon image) // 이미지 버튼
    JButton(String text)  // 문자열 버튼
    JButton(String text, Icon image) // 문자열과 이미지를 모두 가진 버튼
    ```

### ImageIcon

- 이미지 파일로부터 이미지를 읽기 위한 목적.

- png, gif, jpg를 지원한다.

- 이미지 로딩하기

  - 이미지 저장은 프로젝트 폴더에 저장해야 상대경로로 접근할 수 있다.

  - ```java
    new ImageIcon(String path)
    ```

