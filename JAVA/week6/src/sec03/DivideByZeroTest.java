package sec03;

import java.util.Scanner;

public class DivideByZeroTest {
	
	public static void main(String[] args) {
		int x, y;
		Scanner in = new Scanner(System.in);
		System.out.println("피젯수:");
		x=in.nextInt();
		System.out.println("젯수:");
		y=in.nextInt();
		
		try {
			int result = x / y;
			System.out.println("결과: "+ result);
		} catch (ArithmeticException e) {
			System.out.println("0으로 나눌 수 없음");
		} finally {
			in.close();
		}
	}
}
