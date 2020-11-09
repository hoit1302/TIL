package sec01;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import javax.swing.JFrame;

public class KeyTest extends JFrame{
	KeyTest(){
		addKeyListener(new MyKey());
		setSize(300,200);
		setVisible(true);
	}
	
	//내부 클래스로 리스터 구현
	class MyKey implements KeyListener{

		@Override // 눌렀을 때
		public void keyPressed(KeyEvent e) {
			System.out.println(e.getKeyChar()); // 입력한 한 문자 return
			System.out.println(e.getKeyCode()); // 입력한 한 문자의 ascii code 값 return
			System.out.println(e);
		}
		
		@Override // 
		public void keyTyped(KeyEvent e) {
			System.out.println(e);
		}
		
		@Override // 뗐을 때
		public void keyReleased(KeyEvent e) {
			System.out.println(e);
		}
		
	}
	
	public static void main(String[] args) {
		new KeyTest();
	}
}
