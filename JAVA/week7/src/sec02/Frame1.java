package sec02;

import java.awt.BorderLayout;

import javax.swing.*;

public class Frame1 extends JFrame{
	
	// ������
	Frame1() {
		setTitle("BorderLayoutTest");
		setSize(1000,500);
	
		// ������Ʈ ����
		JButton b1 = new JButton("��ư1");
		JButton b2 = new JButton("��ư2");
		JButton b3 = new JButton("��ư3");
		JButton b4 = new JButton("��ư4");
		JButton b5 = new JButton("��ư5");
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
