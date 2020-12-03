package sec01;

public class MyMulti1 implements Runnable {

	@Override
	public void run() {
		String tname = Thread.currentThread().getName(); // 현재 실행 중인 스레드의 이름 얻기
		System.out.println(tname + " 시작");
		for (int i = 1; i <= 5; i++)
			System.out.println(tname + "-" + i);
		System.out.println(tname + "종료");
	}

	public static void main(String[] args) {
		MyMulti1 app = new MyMulti1();
		for (int i = 1; i <= 3; i++) {
			Thread t = new Thread(app);
			t.start();
		}
		System.out.println("main 종료");
	}
}
