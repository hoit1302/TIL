package sec01;
// Runnable 인터페이스를 구현하여 스레드 작성

// #1 Runnable 인터페이스를 구현한 클래스 작성
public class MyRunnable implements Runnable {

	// 반드시 run() 메서드 구현
	@Override
	public void run() { 
		for (int i = 10; i >= 1; i--) {
			System.out.print(i);
			try {
				Thread.sleep(1000); // Thread class에서 제공하기에.
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}

	public static void main(String[] args) {
		// #2 스레드 객체 생성하고, 내가 만든 Runnable 객체를 Thread 생성자에게 넘겨준다. 
		Thread t = new Thread(new MyRunnable()); // 중요!
		// #3 스레드 시작
		t.start();
	}

}
