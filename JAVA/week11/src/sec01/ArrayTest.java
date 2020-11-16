package sec01;

import java.util.ArrayList;
import java.util.Scanner;

public class ArrayTest {

	public static void main(String[] args) {
		// 문자열만 삽입가능한 ArrayList 컬렉션 생성
		ArrayList<String> list = new ArrayList<String>();
		String str;
		Scanner in = new Scanner(System.in);
		for (int i = 0 ; i < 4; i++) {
			System.out.println("과일 이름>>");
			String s = in.next();
			list.add(s);
		}
		
		//ArrayList에 들어있는 모든 이름 출력
		for (int i = 0 ; i < list.size(); i++) {
			String name = list.get(i);
			System.out.print(name + " ");
		}
		System.out.println(list);
		
		System.out.println();
		System.out.print("찾는 이름>>");
		str = in.next();
		int index = list.indexOf(str);
		if (index == -1)
			System.out.println("검색 실패");
		else
			System.out.println(index + "에 위치함");
	}
}
