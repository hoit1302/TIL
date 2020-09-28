package sec01;

public class ComputerTest {
	public static void main(String[] args) {
		int r = 10;
		Calculator c1 = new Calculator();
		System.out.println(c1.areaCircle(r));
		
		Computer c2 = new Computer();
		System.out.println(c2.areaCircle(r));

	}
}
