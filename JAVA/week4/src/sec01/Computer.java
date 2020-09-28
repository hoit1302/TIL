package sec01;

public class Computer extends Calculator {
	@Override
	double areaCircle(double r) {
//		super.areaCircle(r); // 부모의 메서드 강제로 호출!
		double area = Math.PI * r * r;
		return area;
	}
}
