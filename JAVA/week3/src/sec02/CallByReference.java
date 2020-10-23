package sec02;

class Circle {
	int r;

	Circle(int r) {
		this.r = r;
	}
}

public class CallByReference {
	public static void main(String[] args) {
		Circle c = new Circle(10);
		System.out.println(c.r);
		
		add(c); // 객체전달
		System.out.println(c.r);
	}

	static void add(Circle c) {
		c.r++;
	}
}
