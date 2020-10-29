package sec01;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

//간단한 리스너의 경우, 익명 클래스 사용 추천
//메소드의 개수가 1,2개인 리스너(ActionListener, ItemListener)에 대해 주로 사용

public class AnonyClass extends JFrame {
	JButton btn1, btn2;

	AnonyClass() {
		setTitle("액션 이벤트 리스너 예제");
		setLayout(new FlowLayout());
		btn1 = new JButton("확인");
		btn2 = new JButton("취소");

		// 2. 익명리스너 등록
		btn1.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				// 실행할 코드
				setTitle("등록버튼을 눌렀군요");
				btn1.setBackground(Color.red);
			}
		});

		btn2.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				setTitle("취소버튼을 눌렀군요");
			}
		});
		add(btn1);
		add(btn2);
		setSize(300, 150);
		setVisible(true);
	}

	public static void main(String[] args) {
		new AnonyClass();
	}
}
