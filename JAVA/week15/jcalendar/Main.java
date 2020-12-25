package jcalendar;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class Main extends JFrame {

    Container c = getContentPane();
    JLabel presentDate, desc, desc2, copyright;
    JTextField newDate;
    JTextArea memo;
    JButton btnBack, btnFront, btnSubmit, btnWriteMemo;
    JToggleButton btnMon; // 새로운 컴포넌트
    JPanel calendar;
    Calendar cal = Calendar.getInstance();
    int year = cal.get(Calendar.YEAR);
    int month = cal.get(Calendar.MONTH); // 0: 1월, 11: 12월
    int firstDay; // 1: 일요일, 7: 월요일
    int lastDate;


    Main() {

        setTitle("달력");
        c.setLayout(null);

        // 보여지는 달의 년도와 날짜를 표기하는 Label 생성, 위치와 폰트 지정 후 프레임에 추가
        presentDate = new JLabel(); // default로 현재 날짜의 년도-달을 보여준다
        presentDate.setBounds(0, 20, 500, 30);
        presentDate.setFont(new Font("Dialog", Font.PLAIN, 20));
        presentDate.setHorizontalAlignment(JLabel.CENTER);
        c.add(presentDate);



        /* 상단 3개의 버튼 start */
        // 시작하는 요일을 지정하는 토글 버튼 추가
        btnMon = new JToggleButton("월요일 시작");
        btnMon.addActionListener(new StartMonday()); // (액션 이벤트 리스너)클릭 시 동작 설정
        btnMon.setBounds(30, 20, 80, 30);
        btnMon.setMargin(new Insets(0, 0, 0, 0));
        btnMon.setFont(new Font("Dialog", Font.PLAIN, 12));
        // 이전 달과 다음 달을 보여주는 button 생성, 위치와 폰트 지정 후 프레임에 추가
        btnBack = new JButton("<<");
        btnBack.addActionListener(new Back()); // (액션 이벤트 리스너)클릭 시 동작 설정
        btnBack.setBounds(390, 20, 30, 30);
        btnBack.setMargin(new Insets(0, 0, 0, 0));
        btnBack.setFont(new Font("Dialog", Font.BOLD, 14));
        // 다음 달을 보여주는 button 생성, 위치와 폰트 지정 후
        btnFront = new JButton(">>");
        btnFront.addActionListener(new Front()); // (액션 이벤트 리스너)클릭 시 동작 설정
        btnFront.setBounds(420, 20, 30, 30);
        btnFront.setMargin(new Insets(0, 0, 0, 0));
        btnFront.setFont(new Font("Dialog", Font.BOLD, 14));
        // 프레임에 추가
        c.add(btnMon);
        c.add(btnBack);
        c.add(btnFront);
        /* 상단 3개의 버튼 end */



        /* 달력 이동 관련 요소 start */
        // "달력 이동하기" Label 생성, 위치와 폰트 지정 후 프레임에 추가
        desc = new JLabel("달력 이동하기");
        desc.setBounds(30, 365, 100, 30);
        desc.setFont(new Font("Dialog", Font.PLAIN, 14));
        // 사용자에게 원하는 YYYY MM을 입력받는 textfield 생성, 위치 지정 후 프레임에 추가
        newDate = new JTextField(1000);
        newDate.setText("입력 예시: YYYY MM");
        newDate.setBorder(javax.swing.BorderFactory.createEmptyBorder()); // 테투리 삭제
        newDate.setBounds(30, 395, 350, 30);
        // 입력받은 YYYY MM 정보를 전달하는 button 생성, 위치와 폰트 지정 후 프레임에 추가
        btnSubmit = new JButton("확인");
        btnSubmit.addActionListener(new InputDate());
        btnSubmit.setBounds(390, 395, 60, 30);
        c.add(desc);
        c.add(newDate);
        c.add(btnSubmit);
        /* 달력 이동 관련 요소 end */



        /* 메모 적기 관련 요소 start */
        // "메모 적기" Label 생성, 위치와 폰트 지정 후 프레임에 추가
        desc2 = new JLabel("메모 적기");
        desc2.setBounds(30, 430, 100, 30);
        desc2.setFont(new Font("Dialog", Font.PLAIN, 14));
        c.add(desc2);
        // jTextarea
        memo = new JTextArea(10, 400);
        memo.setBounds(30, 460, 350, 70);
        c.add(memo);
        // 입력받은 메모를 적는 button 생성, 위치와 폰트 지정 후 프레임에 추가
        btnWriteMemo = new JButton("적기");
        btnWriteMemo.addActionListener(new WriteMemo());
        btnWriteMemo.setBounds(390, 500, 60, 30);
        c.add(btnWriteMemo);
        /* 메모 적기 관련 요소 end */



        /* footer 영역 start */
        // "copyright" Label 생성, 위치와 폰트 지정 후 프레임에 추가
        copyright = new JLabel("ⓒ Jueun");
        copyright.setBounds(0, 540, 500, 30);
        copyright.setHorizontalAlignment(JLabel.CENTER);
        copyright.setFont(new Font("Dialog", Font.PLAIN, 10));
        c.add(copyright);
        /* footer 영역 end */



        // 현재 달력 보이기
        changeCalendar(year, month); // 1일로 바꿔서 계산해야 해서
        showCalendar();


        // 사이즈 지정, 창 사이즈 변경 불가, gui 창 띄우기
        setSize(500, 610);
        setResizable(false);
        setVisible(true);
    }

    void changeCalendar(int year, int month) { // parameter는 이미 검사되어 올바르게 변형된 수
        cal.set(year, month, 1); // 해당 달의 시작 요일 알기 쉽도록 1일로 지정
        lastDate = cal.getActualMaximum(Calendar.DATE);
        firstDay = cal.get(Calendar.DAY_OF_WEEK); // 1:일요일 ~ 7:월요일
        presentDate.setText(year + "년 " + (month + 1) + "월");
        memo.setText(year + "년 " + (month+1) + "월에 적고 싶은 내용을 메모하세요");
    }

    void showCalendarSunday() {
        calendar = new JPanel();
        if (firstDay == 8) firstDay = 1; // 월요일 -> 일요일 달력 시 조정 (시작하는 요일 1:일요일 7:토요일)
        // 그리드 레이아웃 사용, 그리드의 row, col의 수 계산
        if ((lastDate + firstDay - 1) % 7 == 0)
            calendar.setLayout(new GridLayout(1 + (lastDate + firstDay - 1) / 7, 7));
        else
            calendar.setLayout(new GridLayout(2 + (lastDate + firstDay - 1) / 7, 7));
        calendar.setBackground(Color.white);

        char[] days = {'일', '월', '화', '수', '목', '금', '토'};
        for (char day : days) { // 요일 정보 라벨 추가
            JLabel l = new JLabel(Character.toString(day));
            l.setHorizontalAlignment(JLabel.CENTER);
            calendar.add(l);
        }
        for (int i = 1; i < firstDay; i++) { // 시작하는 요일 전까지의 빈 칸 채우기
            JLabel l = new JLabel("-");
            l.setHorizontalAlignment(JLabel.CENTER);
            calendar.add(l);
        }
        for (int i = 1; i <= lastDate; i++) { // 해당 달의 최대 날짜까지 라벨 추가하기
            JLabel l = new JLabel(Integer.toString(i));
            l.setHorizontalAlignment(JLabel.CENTER); // 가운데 맞춤
            calendar.add(l);
        }
        // 이 후의 공백이 있으면 채우기. 라벨을 추가하지 않으면 이전 달력과 겹쳐 이상하게 보일 수 있음
        for (int i = (lastDate + firstDay - 1) % 7; (i % 7) != 0; i++) { 
            JLabel l = new JLabel("-");
            l.setHorizontalAlignment(JLabel.CENTER);
            calendar.add(l);
        }
        calendar.setBounds(30, 60, 420, 290);
        c.add(calendar);
        SwingUtilities.updateComponentTreeUI(calendar); // 바뀐 컴포넌트 업데이트
    }

    void showCalendarMonday() {
        calendar = new JPanel();
        if (firstDay == 1) firstDay = 8; // 일요일 달력 -> 월요일 달력 시 조정 (시작하는 요일 2:월요일 8:일요일)
        if ((lastDate + firstDay - 2) % 7 == 0)
            calendar.setLayout(new GridLayout(1 + (lastDate + firstDay - 2) / 7, 7));
        else
            calendar.setLayout(new GridLayout(2 + (lastDate + firstDay - 2) / 7, 7));
        calendar.setBackground(Color.white);

        char[] days = {'월', '화', '수', '목', '금', '토', '일'};
        for (char day : days) { // 요일
            JLabel l = new JLabel(Character.toString(day));
            l.setHorizontalAlignment(JLabel.CENTER);
            calendar.add(l);
        }
        for (int i = 2; i < firstDay; i++) { // 시작하는 요일 1:일요일 7:토요일
            JLabel l = new JLabel("-");
            l.setHorizontalAlignment(JLabel.CENTER);
            calendar.add(l);
        }
        for (int i = 1; i <= lastDate; i++) { // 날짜
            JLabel l = new JLabel(Integer.toString(i));
            l.setHorizontalAlignment(JLabel.CENTER);
            calendar.add(l);
        }
        for (int i = (lastDate + firstDay - 2) % 7; (i % 7) != 0; i++) { // 나머지 공백 채우기
            JLabel l = new JLabel("-");
            l.setHorizontalAlignment(JLabel.CENTER);
            calendar.add(l);
        }
        calendar.setBounds(30, 60, 420, 290);
        c.add(calendar);
        SwingUtilities.updateComponentTreeUI(calendar);
    }

    void showCalendar() {
        if (btnMon.isSelected()) { // 월요일 버튼이 선택되었으면
            showCalendarMonday(); // 월요일 시작 달력 로딩
        } else { // 월요일 버튼이 선택되지 않았으면
            showCalendarSunday(); // 일요일 시작 달력 로딩
        }
    }

    // 이전 달 보여주기
    class Back implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            month--;
            if (month == -1) { // 1월의 이전 달일 경우
                year = year - 1; // 전년도,
                month = 11; // 11: 12월로 이동
            }
            changeCalendar(year, month);
            showCalendar();
        }
    }
    // 다음 달 보여주기
    class Front implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            month++;
            if (month == 12) { // 12월의 다음 달일 경우
                year = year + 1; // 다음 년,
                month = 0; // 0: 1월로 이동
            }
            changeCalendar(year, month);
            showCalendar();
        }
    }
    // '월' toggle button 바꿔 보이기
    class StartMonday implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            // 이 메서드에서 버튼이 선택되었는지 확인하여 관련 내용을 로딩한다.
            showCalendar();
        }
    }

    class InputDate implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            String[] temp = newDate.getText().split(" ");
            try { // 정수 변환 과정에서 오류가 발생 대비
                if (0 <= Integer.parseInt(temp[0]) // 입력된 년도가 음수가 아니고
                        && 0 < Integer.parseInt(temp[1]) // 입력된 달이 음수가 아니면서
                        && Integer.parseInt(temp[1]) < 13) { // 달이 13보다 작을 때
                    newDate.setText("");
                    year = Integer.parseInt(temp[0]);
                    month = Integer.parseInt(temp[1]) - 1;
                    changeCalendar(year, month); // 보여줄 년도와 달을 바꾸고
                    showCalendar(); // 캘린더를 로딩한다.
                } else { // 잘못된 형식일 경우 오류 메세지 입력창에 안내
                    newDate.setText("잘못된 형식으로 입력하셨습니다. 입력 예시: YYYY MM");
                }
            } catch (Exception error) {  // 오류 발생 시, 오류 메세지 입력창에 안내
                newDate.setText("잘못된 형식으로 입력하셨습니다. 입력 예시: YYYY MM");

            }
        }
    }

    class WriteMemo implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            String temp = memo.getText();
            String filename = year + "_" + (month + 1) + ".txt"; // 파일 이름 지정
            FileWriter out;
            try {
                out = new FileWriter(filename, true); // 이어서 쓰기 가능
                out.write(temp + "\r\n"); // 파일 쓰기, write()로 문자 하나씩 파일에 기록
                out.close(); // 스트림 닫기. 더 이상 스트림에 기록할 수 없다.
            } catch (IOException ioException) {
                ioException.printStackTrace();
            }
            memo.setText("");
        }
    }

    public static void main(String[] args) {
        new Main();
    }
}
