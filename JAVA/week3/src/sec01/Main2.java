package sec01;

import java.util.Scanner;


public class Main2 {

	double pi = 3.14;
	
//	�ذ� ù��° ���: ���� �޼ҵ�� ���� ������� ����� �� �ֱ⿡ ���� ������ �ٲ���.
	static double pi2 = 3.14;
	
//	�ذ� �ι�° ���: �ν��Ͻ� ����� �����ϱ� ���� ��ü ����
	Main2() {  }
	
	public static void main(String[] args) { // ���� �޼ҵ�
		System.out.println(pi); // error
//		: static �޼��忡�� non-static �ʵ��� pi ���� ����� �� ����.
		
//		�ذ� ù��° ���
		System.out.println(pi2); 
		
//		�ذ� �ι�° ���
		Main2 m = new Main2();
		System.out.println(m.pi);
		
				
}