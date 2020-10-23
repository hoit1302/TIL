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
		System.out.println("이름:" + name);
		System.out.println("반지름:" + getRadius());
		System.out.println("면적:" + getArea());
		System.out.println("둘레:" + getPerimeter());
	}

}
