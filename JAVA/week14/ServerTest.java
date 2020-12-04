import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class ServerTest {
	public static void main(String[] args) {
		BufferedReader in = null;
		BufferedWriter out = null;
		ServerSocket server = null;
		Socket socket = null;
		Scanner scanner = new Scanner(System.in);
		try {
			server = new ServerSocket(9999); // 1. 서버 소켓 생성
			System.out.println("연결을 기다리고 있습니다.....");
			socket = server.accept(); // 2. 클라이언트로부터 연결 요청 대기. 수락이 되면 새로운 소켓이 생성됨
			System.out.println("연결되었습니다.");
			in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			out = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
			while (true) {
				String inputMessage = in.readLine(); // 3. 클라이언트로부터 한 행 읽기 -> 가능한 이유는 버퍼에 저장이 되어 있기 때문.
				if (inputMessage.equalsIgnoreCase("bye")) { // equalsIgnoreCase(): 대소문자 구분 없이 처리
					System.out.println("클라이언트에서 bye로 연결을 종료하였음");
					break; // "bye"를 받으면 연결 종료
				}
				System.out.println("클라이언트: " + inputMessage); // 클라이언트가 보내온 메세지 출력
				System.out.print("보내기>>"); // 프롬프트
				String outputMessage = scanner.nextLine(); // 키보드에서 한 행 읽기
				out.write(outputMessage + "\n"); // 키보드에서 읽은 문자열 전송
				out.flush(); // out의 스트림 버퍼에 있는 모든 문자열 전송
			}
		} catch (IOException e) {
			System.out.println(e.getMessage());
		} finally {
			try {
				scanner.close();
				socket.close();
				server.close();
			} catch (IOException e) {
				System.out.println("클라이언트와의 채팅 중 오류가 발생하였습니다.");
			}
		}
	}
}
