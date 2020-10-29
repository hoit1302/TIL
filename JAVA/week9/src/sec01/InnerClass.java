package sec01;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;

public class InnerClass extends JFrame {
	JButton btn1, btn2;

	InnerClass() {
		setTitle("액션 이벤트 리스너 예제");
		setLayout(new FlowLayout());
		btn1 = new JButton("확인");
		btn2 = new JButton("취소");

		// 2. 리스너 등록
		btn1.addActionListener(new MyGUI1());
		btn2.addActionListener(new MyGUI2());

		add(btn1);
		add(btn2);
		setSize(300, 150);
		setVisible(true);
	}

	// 1. 내부 클래스로 이벤트 리스너 작성
	class MyGUI1 implements ActionListener {
		@Override
		public void actionPerformed(ActionEvent e) {
			// 실행할 코드
			setTitle("확인");
			// 버튼의 문자열을 변경
			btn1.setText("OK");                		
		}
	}

	class MyGUI2 implements ActionListener {
		@Override
		public void actionPerformed(ActionEvent e) {
			// 실행할 코드
			setTitle("취소");
		}
	}

	public static void main(String[] args) {
		new InnerClass();
	}
}
