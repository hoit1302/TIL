package sec01;

public class ScoreTest {
	public static void main(String[] args) {
		Score s1 = new Score();
		int[] values = { 10, 20, 30 };
		int result1 = s1.sum1(values);
		System.out.println("result: " + result1);
	}
}
