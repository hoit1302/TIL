package sec02;

import java.util.Calendar;

public class CalendarTest {
	public static void main(String[] args) {
		
		int year, month, date;
		
//		Calendar는 추상클래스이므로 Object 생성 불가. 대신 Calendar Object를 생성해주는 메서드 제공.
		Calendar c = Calendar.getInstance();
		
		year = c.get(Calendar.YEAR);
		month = c.get(Calendar.MONTH) + 1;	// 1월을 0으로 표현
		date = c.get(Calendar.DATE);
		
		System.out.println(year+"년");
		System.out.println(month+"월");
		System.out.println(date+"일");
	}
}
