package sec01;

import java.awt.Color;
import java.awt.Container;
import java.awt.Font;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class KeyTest2 extends JFrame {

	Container c;
	JLabel lbl;

	KeyTest2() {
		setTitle("Key 이벤트 예제");
		lbl = new JLabel("<Enter>키도 배경색이 변경됩니다.");
		lbl.setFont(new Font("", Font.BOLD, 20));

		c = getContentPane(); // content 영역을 할당받음
		c.setBackground(Color.red);

		// 2. 리스너 등록
		c.addKeyListener(new MyKey());
		add(lbl);
		setSize(400, 400);
		setVisible(true);
		c.requestFocus(); // 컨텐트팬 포커스 설정
	}

	// KeyAdapter 클래스로 리스너 정의
	class MyKey extends KeyAdapter {
		@Override
		public void keyPressed(KeyEvent e) {
			// Math.random()은 0이상 1미만의 정수 반환
			int r = (int) (Math.random() * 256);
			int g = (int) (Math.random() * 256);
			int b = (int) (Math.random() * 256);

			if (e.getKeyCode() == KeyEvent.VK_ENTER) {
				c.setBackground(new Color(r, g, b));
				String color = "(" + r + "," + g + "," + b + ")";
				lbl.setText(color);
			}
			if (e.getKeyChar() == 'q')
				System.exit(0);
			// 보통 문제가 없으면 0, 문제가 있으면 1을 리턴하도록 작성한다.
		}
	}

	public static void main(String[] args) {
		new KeyTest2();
	}
}
