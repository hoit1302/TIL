package sec01;

//추상메서드 반드시 구현
public class Rectangle extends Shape {
	private double length;
	private double width;

	public Rectangle(String name, double length, double width) {
		this.name = name;
		this.length = length;
		this.width = width;
	}

	public double getLength() {
		return length;
	}

	public void setLength(double length) {
		this.length = length;
	}

	public double getWidth() {
		return width;
	}

	public void setWidth(double width) {
		this.width = width;
	}

	@Override
	double getArea() {
		// TODO Auto-generated method stub
		return length * width;
	}

	@Override
	double getPerimeter() {
		// TODO Auto-generated method stub
		return 2 * (length + width);
	}

	@Override
	void showInfo() {
		// TODO Auto-generated method stub
		System.out.println("이름:" + name);
		System.out.println("가로:" + getLength());
		System.out.println("세로:" + getWidth());
		System.out.println("면적:" + getArea());
		System.out.println("둘레:" + getPerimeter());
	}

}