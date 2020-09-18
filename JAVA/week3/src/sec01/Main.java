package sec01;

import java.util.Scanner;

//Ű���� static
//���� ���: '��ü�� ������� ���'�� �޼ҵ� ������ ��ġ. ��ü���� �����ϴ� ���
//	���� �ʵ� �� ���: ��ü ���� Ŭ���������ε� ��� ������ �ʵ�(Ŭ����.������)
//	���� �޼ҵ�: ��ü�� ���� Ŭ���������ε� ȣ�� ������ �޼ҵ�(Ŭ����.�޼ҵ��)
class Circle1 {
	static double PI = 3.14; // ���� ����
	static double area(double r) { // ���� �޼ҵ�
		double area = PI * r * r;
		return area;
	}
}

//���� �޼ҵ忡���� ���� ������ ���� ����. (�翬�� �̾߱�)
class Circle2 {
	double PI = 3.14; // �ν��Ͻ� ����
	static double area(double r) { 
		double area = PI * r * r;  // error
		return area;
	}
}

//�ν��Ͻ� ���: ��ü�� ������ �� ����� �� �ִ� �ʵ�� �޼ҵ�.
//	�ν��Ͻ� �ʵ�: �� ������ ��ü���� ������ �ִ� ���. ��ü���� �ٸ� ������ ����
//	�ν��Ͻ� �޼ҵ�: '��ü�� �־��' ȣ�� ������ �޼ҵ�
class Circle3 {
	double PI = 3.14; // �ν��Ͻ� ����
	double area(double r) { // �ν��Ͻ� �޼ҵ�
		double area = PI * r * r;
		return area;
	}
}


public class Main {
//	���� �޼ҵ忡���� ���� �ʵ常 ����� �����ϰ� ���� �޼ҵ常 ȣ���� ����
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		double r = in.nextDouble();
		System.out.println(Circle1.PI); // Ŭ���� �̸� ������ ����
		System.out.println(Circle1.area(r));
		
		System.out.println(Circle2.area(r));
		
		Circle3 c3 = new Circle3();
		System.out.println(c3.area(r));
		in.close();
	}
}