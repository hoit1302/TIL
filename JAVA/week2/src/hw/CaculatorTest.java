package hw;

public class CaculatorTest {
	public static void main(String[] args) {
		Calculator c = new Calculator(10, 20);
		System.out.println(c.add());
		System.out.println(c.minus());
		System.out.println(c.multiply());
		System.out.println(c.divide());
	}
}
