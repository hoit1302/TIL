package sec02;
// 인터넷 뱅킹의 출금시스템
// 동기화 synchronized 블록 지정
class Account {
	int balance = 10000;

	public void withdraw(int money) {
		if (balance >= money) {
			try {
				Thread.sleep(1000);
			} catch (Exception e) {
			}
			balance -= money;
		}
	}
}

class Bank extends Thread {
	static Account obj = new Account();

	public Bank(String name) {
		super(name);
	}

	@Override
	public void run() {
		while (true) {
			// 동기화하지 않으면 은행과 atm기에서 동시에 계좌에 접근하는 사태가 발생한다.
			synchronized (obj) { // 동기화
				int money = (int) (Math.random() * 3 + 1) * 1000;
				if (obj.balance >= money) {
					System.out.println(getName() + " : 원본의 balance:" + obj.balance);
					System.out.println(getName() + " : 찾는 금액:" + money);
					obj.withdraw(money);
					System.out.println(getName() + " : 수정된 balance:" + obj.balance);
				} else {
					System.out.println("잔액 부족");
					break;
				}
			}
		}
	}
}

public class BankThread {
	public static void main(String[] args) {
		Bank t1 = new Bank("ATM");
		Bank t2 = new Bank("은행");
		t1.start();
		t2.start();
	}
}
