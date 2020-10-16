package sec02;

import java.awt.BorderLayout;

import javax.swing.*;

public class Frame1 extends JFrame{
	
	// 생성자
	Frame1() {
		setTitle("BorderLayoutTest");
		setSize(1000,500);
	
		// 컴포넌트 생성
		JButton b1 = new JButton("버튼1");
		JButton b2 = new JButton("버튼2");
		JButton b3 = new JButton("버튼3");
		JButton b4 = new JButton("버튼4");
		JButton b5 = new JButton("버튼5");
		add(b1, BorderLayout.NORTH); //add(b1, "North");
		add(b2, BorderLayout.SOUTH);
		add(b3, BorderLayout.EAST);
		add(b4, BorderLayout.WEST);
		add(b5, BorderLayout.CENTER);
		setVisible(true);
	}
	
	public static void main(String[] args) {
		new Frame1();
	}
}
