package sec02;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.SwingConstants;

public class MyPhoto extends JFrame{
	JLabel lbl, imglbl;
	JButton btn;
	MyPhoto(){
		setTitle("MyPhoto");
		Font f = new Font("", Font.BOLD, 30); // 폰트 통일
		Color c = new Color(255, 187, 0);
		lbl = new JLabel("TWICE", SwingConstants.CENTER);
		lbl.setFont(f);
		lbl.setForeground(c);
		// 이미지 불러오기
		ImageIcon img1 = new ImageIcon("p1.png"); // 프로젝트 폴더 안에 사진
		ImageIcon img2 = new ImageIcon("p2.png"); // 음악, text 파일 모두 접근 가능
		
		imglbl = new JLabel(img1);
		btn = new JButton("변경");
		btn.setFont(f);
		// 리스너 등록
		btn.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// 레이블의 이미지를 변경
				imglbl.setIcon(img2);
			}
			
		});
		
		add(lbl, "North");
		add(imglbl, "Center");
		add(btn, "South");
		setSize(900,900);
		setVisible(true);
	}
	
	public static void main(String[] args) {
		new MyPhoto();
	}
}
