package sec01;
// *: 해당 클래스와 인터페이스만을 포함한다. 해당 하위 패키지를 포함하지 않는다

import java.awt.*; // 배치관리자
import java.awt.event.*; // 다양한 리스너 인터페이스
import javax.swing.*; // 다양한 컴포넌트

class MYGUI1 implements ActionListener{
	// 이벤트 발생 시 자동으로 실행
	@Override
	public void actionPerformed(ActionEvent e) {
		// 이벤트에 대한 모든 정보가 ActionEvent 클래스인 매개변수 e로 넘어오게 되어있다.
		// 실행할 명령어
		// 이벤트가 발생된 소스가 무엇인지 알 수 있는 Object getSource() 메서드
		// 이벤트가 발생한 컴포넌트를 돌려줄 때 Object이기에 적절히 캐스팅(형변환)해서 사용해야한다.
		JButton btn = (JButton)e.getSource(); 
		if (btn.getText().equals("확인"))
			btn.setText("OK");
		else
			btn.setText("확인");
	}
	
}
public class IndepClass extends JFrame {
	
	// 생성자
	IndepClass(){
		setTitle("액션 이벤트 리스너 예제");
		setLayout(new FlowLayout());
		JButton btn = new JButton("확인");
		
		// 리스너 등록

		btn.addActionListener(new MYGUI1());
		add(btn);
		setSize(300,150);
		setVisible(true);
	}

	public static void main(String[] args) {
		new IndepClass();
	}
}
