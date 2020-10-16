package sec02;

import java.awt.FlowLayout;

import javax.swing.*;

public class Frame2 extends JFrame {
	Frame2() {
		setTitle("FlowLayoutTest");
		// 컴포넌트 생성
		// 배치 관리자 변경
//		FlowLayout f1 = new FlowLayout();
		setLayout(new FlowLayout());
//		JButton b1 = new JButton("버튼1");
//		add(b1);
		add(new JButton("버튼1"));
		add(new JButton("버튼2"));
		add(new JButton("버튼3"));
		add(new JButton("버튼4"));
		setSize(300,150);
		setVisible(true);
	}
	
	public static void main(String[] args) {
		new Frame2();
	}
}
