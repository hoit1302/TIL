package sec01;

public class Point {
	
	private int x, y; // x, y�� Point class������ ���� ����. 

	void setPoint(int x, int y) {
		this.x = x;
		this.y = y;
	}
	// �޼ҵ�� private�� X
	void showPoint() {
		System.out.println("(" + x + ", " + y + ")");
	}
}
