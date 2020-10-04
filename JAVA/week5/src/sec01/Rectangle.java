package sec01;

//�߻�޼��� �ݵ�� ����
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
		System.out.println("�̸�:" + name);
		System.out.println("����:" + getLength());
		System.out.println("����:" + getWidth());
		System.out.println("����:" + getArea());
		System.out.println("�ѷ�:" + getPerimeter());
	}

}