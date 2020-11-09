package sec02;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class ImageViewer extends JFrame{

	// 내부 클래스와 생성자에서 공통으로 접근하기 쉽도록 멤버 변수로 선언
	JButton btnprev, btnnext;
	ImageIcon[] image;
	JLabel imageLabel;
	int cnt;
	
	
	ImageViewer() {
		setTitle("랜선으로 떠나는 여행");
		Font f = new Font("", Font.BOLD, 30);
		
		JPanel panel = new JPanel();
		btnprev = new JButton("<<");
		btnnext = new JButton(">>");
		btnprev.setFont(f);
		btnnext.setFont(f);
		image = new ImageIcon[4];
		
		panel.setBackground(Color.pink);
		// 이미지 로딩
		for (int i = 0 ; i < image.length; i++) {
			String path = "./image/p"+i+".png";
			image[i] = new ImageIcon(path);
		}
		
		// 처음이미지
		cnt = 0;
		imageLabel = new JLabel(image[cnt]);
		
		// 내부 클래스로 리스너 구현
		class Preview implements ActionListener{
			@Override
			public void actionPerformed(ActionEvent e) {
				cnt--;
				imageLabel.setIcon(image[cnt%4]);
			}
		}
		class Next implements ActionListener{
			@Override
			public void actionPerformed(ActionEvent e) {
				cnt++;
				imageLabel.setIcon(image[cnt%4]);
			}
		}
		
		// 리스터 등록
		btnprev.addActionListener(new Preview());
		btnnext.addActionListener(new Next());
		
		// 컴포넌트 부착
		add(imageLabel, "Center");
		panel.add(btnprev);
		panel.add(btnnext);
		add(panel, "South");
		setSize(900, 900);
		setVisible(true);
	}

	public static void main(String[] args) {
		new ImageViewer();
	}
}
