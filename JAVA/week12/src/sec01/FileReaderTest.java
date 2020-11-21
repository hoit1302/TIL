package sec01;

import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class FileReaderTest {
	public static void main(String[] args) throws IOException {
		// #1
		FileReader in = new FileReader("text.txt"); // 예외처리는 try-catch로 할 수 있고 throws로 할 수 있음
		int ch; // 반환값이 정수형이기 대문에

		while ((ch = in.read()) != -1) // 더 이상 읽을 것이 없으면 -1을 반환하기에
			System.out.print((char) ch); // 문자로 casting해서 출력
		System.out.println();
		in.close();

		// #2
		File f = new File("text.txt");
		FileReader in2 = new FileReader(f);
		
		while ((ch = in2.read()) != -1)
			System.out.print((char) ch);		
		in2.close();
	}
}
