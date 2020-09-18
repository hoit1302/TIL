package sec01;

import java.util.Scanner;


public class Main2 {

	double pi = 3.14;
	
//	해결 첫번째 방법: 정적 메소드는 정적 멤버만을 사용할 수 있기에 정적 변수로 바꿔줌.
	static double pi2 = 3.14;
	
//	해결 두번째 방법: 인스턴스 멤버에 접근하기 위해 객체 생성
	Main2() {  }
	
	public static void main(String[] args) { // 정적 메소드
		System.out.println(pi); // error
//		: static 메서드에서 non-static 필드인 pi 값을 사용할 수 없다.
		
//		해결 첫번째 방법
		System.out.println(pi2); 
		
//		해결 두번째 방법
		Main2 m = new Main2();
		System.out.println(m.pi);
		
				
}