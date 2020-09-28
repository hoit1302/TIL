package sec01;

public class Point {
	
	private int x, y; // x, y는 Point class에서만 접근 가능. 

	void setPoint(int x, int y) {
		this.x = x;
		this.y = y;
	}
	// 메소드는 private로 X
	void showPoint() {
		System.out.println("(" + x + ", " + y + ")");
	}
}
