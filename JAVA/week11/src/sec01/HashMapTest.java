package sec01;

import java.util.HashMap;
import java.util.Scanner;

public class HashMapTest {
	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		HashMap<String, String> dic = new HashMap<>();
		String key;
		dic.put("apple", "사과");
		dic.put("grape", "포도");
		dic.put("orange", "오렌지");
		dic.put("mango", "망고");
		
		// 전체 출력
		for (String k : dic.keySet()) {
			String v = dic.get(k);
			System.out.println(k + ": " + v);
		}
		
		// 검색기능
		while (true) {
			System.out.print("단어 입력: ");
			key = in.next();
			if (key.equals("quit"))	break;
			String value = dic.get(key);
			if (value == null)
				System.out.println("없는 단어입니다.");
			else
				System.out.println("뜻: " + value);
		}
	}
}
