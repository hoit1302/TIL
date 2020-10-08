package sec01;

public class Circle extends Shape {
	private double radius;

	public Circle(String name, double radius) {
		this.name = name;
		this.radius = radius;
	}

	public double getRadius() {
		return radius;
	}

	public void setRadius(double radius) {
		this.radius = radius;
	}

	@Override
	double getArea() {
		return radius * radius * Math.PI;
	}

	@Override
	double getPerimeter() {
		return 2 * radius * Math.PI;
	}

	@Override
	void showInfo() {
		System.out.println("�̸�:" + name);
		System.out.println("������:" + getRadius());
		System.out.println("����:" + getArea());
		System.out.println("�ѷ�:" + getPerimeter());
	}

}
