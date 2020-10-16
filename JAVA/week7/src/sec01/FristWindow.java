package sec01;

import javax.swing.JFrame;

public class FristWindow {

	public static void main(String[] args) {
		
		//JFrame 클래스 이용 => 객체 생성
		JFrame f = new JFrame();
		f.setTitle("첫 윈도우 프로그램");
		f.setSize(300, 200);
		f.setVisible(true);
		// 하지만 잘 사용되지 않는다. 확장성이나 융통성 부분이 결여된다.
		

	}

}
