package sec01;

import javax.swing.*;

public class HelloFrame extends JFrame{
	
//	생성자
	HelloFrame(){
		setTitle("첫 번째 윈도우 프로그램");
		setSize(300, 200);
		
		//	버튼 컴포넌트 생성: JBotton
		JButton btn1 = new JButton("확인");
		add(btn1);
		
		setVisible(true);
	}
	
	public static void main(String[] args) {
//		객체 생성
		HelloFrame f = new HelloFrame();	// f(객체변수)가 생성된 객체 메모리를 가리킴
		new HelloFrame();	// 객체만 생성됨.
		
	}
}
		
