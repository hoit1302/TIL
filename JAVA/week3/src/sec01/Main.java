package sec01;

import java.util.Scanner;

//키워드 static
//정적 멤버: '객체와 상관없는 멤버'로 메소드 영역에 위치. 객체들이 공유하는 멤버
//	정적 필드 및 상수: 객체 없이 클래스만으로도 사용 가능한 필드(클래스.변수명)
//	정적 메소드: 객체가 없이 클래스만으로도 호출 가능한 메소드(클래스.메소드명)
class Circle1 {
	static double PI = 3.14; // 정적 변수
	static double area(double r) { // 정적 메소드
		double area = PI * r * r;
		return area;
	}
}

//정적 메소드에서는 정적 변수만 접근 가능. (당연한 이야기)
class Circle2 {
	double PI = 3.14; // 인스턴스 변수
	static double area(double r) { 
		double area = PI * r * r;  // error
		return area;
	}
}

//인스턴스 멤버: 객체를 생성한 후 사용할 수 있는 필드와 메소드.
//	인스턴스 필드: 힙 영역의 객체마다 가지고 있는 멤버. 객체마다 다른 데이터 저장
//	인스턴스 메소드: '객체가 있어야' 호출 가능한 메소드
class Circle3 {
	double PI = 3.14; // 인스턴스 변수
	double area(double r) { // 인스턴스 메소드
		double area = PI * r * r;
		return area;
	}
}


public class Main {
//	정적 메소드에서는 정적 필드만 사용이 가능하고 정적 메소드만 호출이 가능
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		double r = in.nextDouble();
		System.out.println(Circle1.PI); // 클래스 이름 만으로 접근
		System.out.println(Circle1.area(r));
		
		System.out.println(Circle2.area(r));
		
		Circle3 c3 = new Circle3();
		System.out.println(c3.area(r));
		in.close();
	}
}