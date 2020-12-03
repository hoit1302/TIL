package sec02;
// 두 스레드가 공유 프린터 객체를 통해 동시에 출력하는 경우.
// 동기화 - synchronized 메소드 지정
class SharedPrinter {
	// void print(String text) { 동기화를 하지 않으면 영문과 한글이 섞여서 출력된다.
	synchronized void print(String text) { // 한 스레드에게 독점 권한을 준다. 임계 영역. 상호 배제 영역
		for (int i = 0; i < text.length(); i++)
			System.out.print(text.charAt(i));
		System.out.println();
	}
}

public class WorkerThread extends Thread {
	SharedPrinter p; // 공유 프린트 주소
	String[] text;

	WorkerThread(SharedPrinter p, String[] text) {
		this.p = p;
		this.text = text;
	}

	@Override
	public void run() {
		for (int i = 0; i < text.length; i++)
			p.print(text[i]);
	}

	public static void main(String[] args) {
		SharedPrinter p = new SharedPrinter(); // 공유 데이터 생성

		String[] engText = { "God helps those who help themselves.", "He who hesitate is lost.", "Knowledge is power.",
				"Small drops make a shower." };
		String[] korText = { "(하늘은 스스로 돕는 자를 돕는다.)", "(망설이는 자는 모든 것을 잃는다.)", "(아는 것이 힘이다.)",
		"(작은 물방울이 소낙비를 이룬다.)" };
		WorkerThread t1 = new WorkerThread(p, engText); // 영문 출력 스레드
		WorkerThread t2 = new WorkerThread(p, korText); // 국문 출력 스레드
		t1.start();
		t2.start();
	}
	
}
