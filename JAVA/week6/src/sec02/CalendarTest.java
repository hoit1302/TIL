package sec02;

import java.util.Calendar;

public class CalendarTest {
	public static void main(String[] args) {
		
		int year, month, date;
		
//		Calendar�� �߻�Ŭ�����̹Ƿ� Object ���� �Ұ�. ��� Calendar Object�� �������ִ� �޼��� ����.
		Calendar c = Calendar.getInstance();
		
		year = c.get(Calendar.YEAR);
		month = c.get(Calendar.MONTH) + 1;	// 1���� 0���� ǥ��
		date = c.get(Calendar.DATE);
		
		System.out.println(year+"��");
		System.out.println(month+"��");
		System.out.println(date+"��");
	}
}
