package sec02;

import java.awt.Color;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class PanelTest extends JFrame {
	public PanelTest() {
		JPanel panel = new JPanel();
		panel.setBackground(Color.pink);

		JButton b1 = new JButton("OK");
		JButton b2 = new JButton("Cancel");
		// setBackground는 JComponent class가 제공. JComponent를 상속받는 Jbutton, JPanel 등은 사용 가능
		b1.setBackground(Color.yellow);	

		panel.add(b1);
		panel.add(b2);
		add(panel);
		setSize(300, 100);
		setVisible(true);
	}

	public static void main(String[] args) {
		new PanelTest();
	}

}
