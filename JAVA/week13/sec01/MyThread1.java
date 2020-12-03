package sec01;
// Thread 클래스를 상속받아 스레드 작성하기
public class MyThread1 extends Thread {

	// 스레드 코드 꼭 재정의 해주어야 한다.
	@Override 
	public void run() { // public 지우면 error. 상속받은 Thread에서 run()이 public으로 정의되어 있기 때문에 접근 지정자를 줄이면 안된다.
		for (int i = 10; i >= 1; i--) {
			System.out.print(i);
			try {
				sleep(1000); // Thread class에서 제공하는 정적 메소드, 단위는 ms
				// 실행 중인 스레드를 잠시 멈추게 할 수 있음.
			} catch (InterruptedException e) {
				e.printStackTrace();
			} 
		}
	} // run() 메소드가 종료하면 스레드는 종료된다.

	public static void main(String[] args) {
		MyThread1 t = new MyThread1();
		t.start(); // 자동으로 run method 호출
	}

}
