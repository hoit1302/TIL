# 12 파일 입출력

## 자바의 입출력 스트림에 대한 이해

### 자바의 입출력 스트림

- **입출력 장치와 자바 응용 프로그램 연결**
  - 입력 스트림 : 입력 장치로부터 자바 프로그램으로 데이터를 전달하는 객체 
  - 출력 스트림 : 자바 프로그램에서 출력 장치로 데이터를 보내는 객체
- 특징 
  - 입출력 스트림 기본 단위 : **바이트**
  - 단방향 스트림
  - 선입선출 구조

### 자바의 입출력 스트림 종류

- **문자 스트림** 
  - 문자만 입출력하는 스트림 
  - 문자가 아닌 바이너리 데이터는 스트림에서 처리하지 못함 
  - 문자가 아닌 데이터를 문자 스트림으로 출력하면 깨진 기호가 출력 
  - 바이너리 파일을 문자 스트림으로 읽으면 읽을 수 없는 바이트가 생겨서 오류 발생 
  - 예) 텍스트 파일을 읽는 입력 스트림
  - JDK 문자 스트림 계층 구조
    - ![image](https://user-images.githubusercontent.com/68107000/99741948-bec7ba00-2b15-11eb-9b60-ab4b8d329d6f.png)
- **바이트 스트림**
  - 입출력 데이터를 단순 바이트의 흐름으로 처리 
  - 문자 데이터 든 바이너리 데이터든 상관없이 처리 가능 
  - 예) 바이너리 파일을 읽는 입력 스트림
  - JDK 바이트 스트림 계층 구조
    - ![image](https://user-images.githubusercontent.com/68107000/99741882-93dd6600-2b15-11eb-9991-35bc552a4a2a.png)

## 텍스트 파일 입출력

### FileReader로 텍스트 파일 읽기

**텍스트 파일을 읽기 위해 문자 스트림 FileReader 클래스 이용** 

1. 파일 입력 스트림 생성(파일 열기) 
   - 스트림을 생성하고 파일을 열어 스트림과 연결 
2.  파일 읽기
   - read()로 문자 하나씩 파일에서 읽음 
3.  close()로 스트림 닫기
   - 스트림이 더 이상 필요 없으면 닫아야 함. 닫힌 스트림에서는 읽을 수 없음

**예제 코드**

```java
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class FileReaderTest {
	public static void main(String[] args) throws IOException {
		// 1
		FileReader in = new FileReader("text.txt");
		int ch;

		while ((ch = in.read()) != -1)
			System.out.print((char) ch);
		System.out.println();
		in.close();

		// 2
		File f = new File("text.txt");
		FileReader in2 = new FileReader(f);
		
		while ((ch = in2.read()) != -1)
			System.out.print((char) ch);		
		in2.close();
	}
}

```

**FileReader의 생성자와 주요 메소드**

![image](https://user-images.githubusercontent.com/68107000/99742213-5fb67500-2b16-11eb-9ef2-c826b8148083.png)

### FileWriter로 텍스트 파일 쓰기

**텍스트 파일에 쓰기 위해 문자 스트림 FileWriter 클래스 이용** 

1. 파일 출력 스트림 생성(파일 열기)
   - 스트림을 생성하고 파일을 열어 스트림과 연결 
2. 파일 쓰기
   - write()로 문자 하나씩 파일에 기록 
   - 블록 단위로 쓰기 가능 
3. close()로 스트림 닫기

**예제 코드**

```java
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
		String str;
		while(!(str=in.nextLine()).equals("q"))
			out.write(str+"\r\n"); // 파일 쓰기, write()로 문자 하나씩 파일에 기록
		out.close(); // 스트림 닫기. 더 이상 스트림에 기록할 수 없다.
        
  		FileWriter out2 = new FileWriter(filename, true); // 이어서 쓰기      
        char[] buf = new char[1024];
		out.write(buf, 0 buf.length); // 이렇게 블록 단위로 쓰는 것도 가능하다.
        // buf[0]부터 버커 크기만큼 쓴다.

		System.out.println(filename + " 저장되었습니다.");
	}
}
```

**FileWriter의 생성자와 주요 메소드**

![image](https://user-images.githubusercontent.com/68107000/99742238-6f35be00-2b16-11eb-8016-741fa688ded4.png)

### 파일 입출력과 예외처리

**파일 입출력동안 예외 발생 가능**

- **스트림을 생성하는 동안 : FileNotFoundException 발생 가능**

  - 파일의 경로명이 틀리거나, 디스크의 고장 등으로 파일을 열 수 없음

  - ```java
    FileReader fin = new FileReader(“파일명"); // FileNotFoundException 발생가능
    ```

- 파일 읽기, 쓰기, 닫기를 하는 동안 : IOException 발생 가능

  - 디스크 오동작, 파일이 중간에 깨진 경우, 디스크 공간이 모자라서 파일 입출력 불가

  - ```java
    int c = fin.read(); // IOException 발생 가능
    ```

**try-catch 블록 반드시 필요**

- 자바 컴파일러의 강제 사항

- ```java
  try {
      FileReader fin = new FileReader(＂파일명");
      ..
      int c = fin.read();
      ...
      fin.close();
  } catch(IOException e) {
  	System.out.println("입출력 오류");
  }
  ```

## csv 파일 입출력

- CSV(Comma Separated Values) 형식은 데이터의 각 요소를 **콤마(,) 로 구분**하고 개행 문자가 그대로 데이터의 행의 구분을 나타냄 
- CSV 데이터는 .csv라는 확장자가 붙은 파일로 저장함 
- 데이터가 콤마로 구분되므로 읽을 때 콤마 단위로 나누는 처리가 필요함

참고 : 기온 공공 데이터 활용 [#](https://data.kma.go.kr)

```java
public class CsvTest {
	public static void main(String[] args) throws IOException {
		FileReader fr = new FileReader("sample.csv");

		String line = null;
		String csvSplit = ",";
		BufferedReader br = new BufferedReader(fr);
        
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
```

