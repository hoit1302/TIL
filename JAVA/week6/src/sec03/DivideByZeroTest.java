package sec03;

import java.util.Scanner;

public class DivideByZeroTest {
	
	public static void main(String[] args) {
		int x, y;
		Scanner in = new Scanner(System.in);
		System.out.println("������:");
		x=in.nextInt();
		System.out.println("����:");
		y=in.nextInt();
		
		try {
			int result = x / y;
			System.out.println("���: "+ result);
		} catch (ArithmeticException e) {
			System.out.println("0���� ���� �� ����");
		} finally {
			in.close();
		}
	}
}
