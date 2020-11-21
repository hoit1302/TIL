package sec01;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;

public class CsvTest {
	public static void main(String[] args) throws IOException {
		FileReader fr = new FileReader("sample.csv"); // 입력 스트림 생성, 한 문자씩 읽어온다.
		String line = null;
		String csvSplit = ",";
		BufferedReader br = new BufferedReader(fr);
		// Scanner는 공백 단위를 기준으로, BufferedReader는 한 줄을 기준으로 경계를 잡음.
		// 많은 양의 데이터를 읽어올 때 효율적
		// 생성자에 입력 스트림을 요구
		// 이처럼 스트림을 연결하여 쓸 수 있다.
		
		while ((line = br.readLine()) != null) {
			String arr[] = line.split(csvSplit);
			// #1
			for (String s : arr)
				System.out.print(s);
			System.out.println();
			// #2
			System.out.println(Arrays.asList(arr));
		}
	}
}
