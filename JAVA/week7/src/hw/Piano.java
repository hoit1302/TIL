package hw;

import java.awt.GridLayout;
import javax.swing.*;

public class Piano extends JFrame {
	
	Piano() {
		setTitle("Piano");
		setSize(1000, 300);
		setLayout(new GridLayout());
		String notes = "도레미파솔라시";
		for (int i = 0 ; i < 16; i++)
			add(new JButton(Character.toString(notes.charAt(i%7))));
		
		setVisible(true);
	}
	
	public static void main(String[] args) {
		new Piano();
	}
}
