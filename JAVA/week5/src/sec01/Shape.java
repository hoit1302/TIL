package sec01;

abstract public class Shape {
//	 ��� ����
	protected String name;

//	 �Ϲ� �޼ҵ� ����
	String getName() {
		return name;
	}

//	 ������ ����

//	 �߻�޼ҵ� ����: ����
	abstract double getArea();

//	�߻�޼ҵ� ����: �ѷ�
	abstract double getPerimeter();

//	�߻�޼ҵ� ����: ���
	abstract void showInfo();
}
