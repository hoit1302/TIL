package sec01;

public class ShapeTest {
	public static void main(String[] args) {
		Rectangle myRect = new Rectangle("AA", 10, 20);
		myRect.showInfo();

		Circle myCircle = new Circle("BB", 5);
		myCircle.showInfo();
	}

}
