package sec02;

public class CallByValue{
	public static void main(String[] args) {
		int x = 10;
		System.out.println(x); // 10
		add(x);
		System.out.println(x); // 10 11아님
	}
	static void add(int x) {
		x++;
	}
}
