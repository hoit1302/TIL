package sec02;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class AdapterClass extends JFrame {

	JLabel lbl;

	AdapterClass() {
		setTitle("Mouse 이벤트 예제");
		lbl = new JLabel("cheer up");
		lbl.setForeground(Color.red);
		add(lbl);
		setLayout(new FlowLayout());
		// 리스너 등록
		addMouseListener(new MyMouse());
		setSize(400, 400);
		setVisible(true);
	}

	// 1. 내부클래스로 어댑터 클래스 상속받아 필요한 클래스만 오버라이딩
	class MyMouse extends MouseAdapter {

		@Override
		public void mousePressed(MouseEvent e) {
			int x = e.getX();
			int y = e.getY();
			lbl.setLocation(x, y);
			System.out.println("(" + x + ", " + y + ")");
			System.out.println(e);
		}
	}

	public static void main(String[] args) {
		new AdapterClass();
	}
}
