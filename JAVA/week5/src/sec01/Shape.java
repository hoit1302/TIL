package sec01;

abstract public class Shape {
//	 멤버 변수
	protected String name;

//	 일반 메소드 정의
	String getName() {
		return name;
	}

//	 생성자 정의

//	 추상메소드 선언: 면적
	abstract double getArea();

//	추상메소드 선언: 둘레
	abstract double getPerimeter();

//	추상메소드 선언: 출력
	abstract void showInfo();
}
