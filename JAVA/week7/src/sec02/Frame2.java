package sec02;

import java.awt.FlowLayout;

import javax.swing.*;

public class Frame2 extends JFrame {
	Frame2() {
		setTitle("FlowLayoutTest");
		// ������Ʈ ����
		// ��ġ ������ ����
//		FlowLayout f1 = new FlowLayout();
		setLayout(new FlowLayout());
//		JButton b1 = new JButton("��ư1");
//		add(b1);
		add(new JButton("��ư1"));
		add(new JButton("��ư2"));
		add(new JButton("��ư3"));
		add(new JButton("��ư4"));
		setSize(300,150);
		setVisible(true);
	}
	
	public static void main(String[] args) {
		new Frame2();
	}
}
