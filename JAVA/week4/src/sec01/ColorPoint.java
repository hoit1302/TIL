package sec01;

public class ColorPoint extends Point {
	String color;
	
	void setColor(String color) {
		
		this.color = color;
	}
	// Point class가 다른 패키지로 이동 시 showPoint의 접근 지정자가 default일 때 오류
	void showColorPoint() {
		System.out.println(color);
		showPoint(); 
	}
}
