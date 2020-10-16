package hw;

import java.util.*;

public class PolygonTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		Polygon p = null;

		System.out.print("menu select 1)삼각형 2)직사각형 3) 정사각형:");
		int select = s.nextInt();
		switch (select) {
		case 1:
			p = new Polygon("Triangle", 10, 20);
			p.calcArea(p.width, p.height, select);
			break;
		case 2:
			p = new Polygon("Rectangle", 10, 20);
			p.calcArea(p.width, p.height, select);
			break;

		case 3:
			p = new Polygon("square", 10);
			p.calcArea(p.width);
			break;
		default:
			break;
		}

		p.printArea();
	}

}