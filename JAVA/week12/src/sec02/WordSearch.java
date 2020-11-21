package sec02;

//이 파일을 모두 읽어 Vector<String>에 저장하고, 
//영어 단어를 입력 받고 백터를 검색하여 
//그 단어로 시작하는 모든 단어를 출력하는 프로그램

import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;
import java.util.Vector;

public class WordSearch {
	public static void main(String[] args) throws IOException {
		Vector<String> v = new Vector<>();
		FileReader f = new FileReader("word.txt");
		Scanner fs = new Scanner(f);
		while (fs.hasNext())
			v.add(fs.next());
		fs.close();

		// 단어 검색
		Scanner in = new Scanner(System.in);
		while (true) {
			boolean found = false;
			System.out.print("단어>>");
			String search = in.next();
			if (search.equals("q")) {
				System.out.println("종료합니다...");
				break;
			}
			for (int i = 0; i < v.size(); i++) {
				String vs = v.get(i);
				if (vs.length() < search.length())
					continue;

				String a = vs.substring(0, search.length());
				if (search.equals(a)) {
					System.out.println(vs);
					found = true;
				}
			}
			if (!found)
				System.out.println("탐색 실패");
		}
	}
}
