package sec01;

public class Computer extends Calculator {
	@Override
	double areaCircle(double r) {
//		super.areaCircle(r); // �θ��� �޼��� ������ ȣ��!
		double area = Math.PI * r * r;
		return area;
	}
}
