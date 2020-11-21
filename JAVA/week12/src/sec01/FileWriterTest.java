package sec01;

import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class FileWriterTest {
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(System.in);
		
		System.out.print("# 저장할 파일명: ");
		String filename = in.next();
		System.out.println("# 저장은 마지막 라인에 q를 입력");
		// 파일 출력 스트림 생성(파일 열기)
		// 스트림을 생성하고 파일을 열어 스트림과 연결
		
		FileWriter out = new FileWriter(filename); // 새로 쓰기, 덮어쓰기
//		FileWriter out = new FileWriter(filename, true); // 이어서 쓰기
		
		String str;
		while(!(str=in.nextLine()).equals("q"))
			out.write(str+"\r\n"); // 파일 쓰기, write()로 문자 하나씩 파일에 기록
		// char[] buf = new char[1024];
		// out.write(buf, 0 buf.length); 이렇게 블록 단위로 쓰는 것도 가능하다. buf[0]부터 버커 크기만큼 쓴다.
		out.close(); // 스트림 닫기. 더 이상 스트림에 기록할 수 없다.
		
		System.out.println(filename+" 저장되었습니다.");
	}
}
