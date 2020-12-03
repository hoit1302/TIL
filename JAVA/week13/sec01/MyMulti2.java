package sec01;
// 대문자 출력 스레드
class UpperThread extends Thread {
	public void run() {
		for (char i = 'A'; i <= 'Z'; i++) {
			System.out.print(i);
			try {
				Thread.sleep(300);
			} catch (InterruptedException e) {
				return;
			}
		}
	}
}
// 소문자 출력 스레드
class LowerThread extends Thread {
	public void run() {
		for (char i = 'a'; i <= 'z'; i++) {
			System.out.print(i);
			try {
				Thread.sleep(200);
			} catch (InterruptedException e) {
				return;
			}
		}
	}
}

public class MyMulti2 {
	public static void main(String[] args) {
		UpperThread ut = new UpperThread();
		LowerThread lt = new LowerThread();
		ut.start();
		lt.start();
	}
}