package sec01;

public class ColorPoint extends Point {
	String color;
	
	void setColor(String color) {
		
		this.color = color;
	}
	// Point class�� �ٸ� ��Ű���� �̵� �� showPoint�� ���� �����ڰ� default�� �� ����
	void showColorPoint() {
		System.out.println(color);
		showPoint(); 
	}
}
