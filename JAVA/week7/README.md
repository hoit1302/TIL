# GUI - 그래픽 사용자 인터페이스

## 개념

**Graphical User Interface**는**컴포넌트**들로 구성된다.

## GUI의 종류

- AWT(Abstract Windowing Toolkit) 패키지
  - 자바가 처음 나왔을 때부터 배포된 GUI 패키지, 최근에는 거의 사용하지 않는다.
  - AWT 컴포넌트는 중량 컴포넌트(heavy weight component)
  - 운영체제에 의존적이다. OS에 따라 다르게 보인다.

- **Swing 패키지**
  -  AWT 기술을 기반으로 작성된 자바 라이브러리
  - 모든 AWT 기능 + 추가된 풍부하고 화려한 고급 컴포넌트
  - AWT 컴포넌트를 모두 스윙으로 재작성. AWT 컴포넌트 **이름 앞에 J자**를 덧붙임
  - 순수 자바 언어로 구현
  - 스윙 컴포넌트는 **경량 컴포넌트(light weight component)**
  - **플랫폼에 독립적**이다.
  - 현재 자바의 GUI로 사용됨



## 패키지 계층 구조

![image](https://user-images.githubusercontent.com/68107000/96226503-b12a8c00-0fcd-11eb-9175-76f3bd9eee64.png)



## 컨테이너와 컴포넌트

![image](https://user-images.githubusercontent.com/68107000/96227081-81c84f00-0fce-11eb-948a-02b7acf19a33.png)

- **최상위 컨테이너**
  - **다른 컨테이너에 포함되지 않**고도 화면에 출력되며 **독립적**으로 존재 가능한 컨테이너
  - 스스로 화면에 자신을 출력하는 컨테이너 : ***JFrame***, JDialog, JApplet
- **컨테이너**
  - 다른 컴포넌트를 포함할 수 있는 GUI 컴포넌트
  - Swing 컨테이너: JPanel JFrame, JApplet, JDialog, JWindow
- **컴포넌트**
  - **컨테이너에 포함되어야** 화면에 출력될 수 있는 GUI 객체
  - **다른 컴포넌트를 포함할 수 없는** 순수 컴포넌트



## GUI 프로그램 작성 절차

1. 컨테이너를 생성한다.
2. 컴포넌트를 추가한다.



## GUI 프로그램 작성 방법

클래스 JFrame를 **상속**받아 사용한다.

```java
class Frame extends JFrame{
    // 생성자
    Frame() {
        setTitle("윈도우 프로그램");
       	setSize(300, 100);
        setVisible(true);
    }
    public static void main(String[] args){
		new Frame();
    }
}
```



## 배치 관리자

컨테이너 안의 각 컴포넌트의 위치와 크기를 결정하는 작업

- 컨테이너마다 하나의 배치관리자 존재 

- 디폴트 배치 관리자 - 컨테이너 생성 시 자동으로  배치관리자가 생성됨

  ![image](https://user-images.githubusercontent.com/68107000/96223454-e7b1d800-0fc8-11eb-92cb-1edc6abae0fa.png)

- 컨테이너에 부착되는 컴포넌트의 위치와 크기 결정

- 컨테이너의 크기가 변경되면, 컴포넌트의 위치와 크기 재결정

- **java.awt 패키지에 구현되어 있음**

- 대표 유형

  ![image](https://user-images.githubusercontent.com/68107000/96223410-d1a41780-0fc8-11eb-9879-efc75f64f610.png)



## 컨테이너에 새로운 배치 관리자 설정하기

**setLayout(LayoutManager lm)** 메소드 호출한다. Im을 새로운 배치 관리자로 설정한다.

new연산자를 이용하여 **배치관리자 객체를 만들고** 이 객체를 컨테이너의 setLayout()메소드를 사용하여 배치 관리자로 지정한다.

```java
JPanel p = new JPanel();
p.setLayout(new BorderLayout()); // JPanel에 BorderLayout 설정
```



### #1 배치 관리자: BorderLayout

- 컨테이너의 공간을 **동(EAST), 서(WEST), 남(SOUTH), 북(NORTH), 중앙 (CENTER)**의 **5개 영역**으로 나눈다.
- 5개 영역 중 응용프로그램에서 지정한 영역에 컴포넌트 배치한다.
- 만약, 영역을 지정하지 않으면 컴포넌트는 중앙(Center)에 놓여진다.

```java
add(new JButton("head"), BorderLayout.NORTH);

JButton b1 = new JButton("head");
add(b1, "North");
```



### #2 배치 관리자: FlowLayout

- 컴포넌트가 삽입되는 순서대로 왼쪽에서 오른쪽으로 배치한다.
- 배치할 공간이 없으면 아래로 내려와서 반복한다.

```java
setLayout(new FlowLayout());
add(new JButton("버튼1")); // 원하는 만큼
```



### #3 배치 관리자: GridLayout

- 컨테이너를 프로그램에서 설정한 동일한 크기의 2차원 격자(그리드)로 분할한다.
- 각 셀에 컴포넌트를 하나씩 배치한다.
- 컴포넌트는 삽입 순서대로 왼쪽에서 오른쪽으로, 위에서 아래로 순서대로 배치된다.
- 생성자
  - GridLayout() 
  - GridLayout(int rows, int cols) 
  - GridLayout(int rows, int cols, int hGap, int vGap)

```java
setLayout(new GridLayout(2,3));
add(new JButton("버튼1")); 	// 6번
```



## 패널

패널은 **컴포넌트들을 포함**하고 있도록 설계된 **컨테이너** 중의 하나이다.

```java
JPanel panel = new JPanel();
panel.setBackground(color.pink);
panel.add(new JButton("OK"));
panel.add(new JButton("Cancel"));

add(panel);
```

