package sec03;

public class ArrayExceptionTest {
	
	public static void main(String[] args) {
		
		int[] arr = new int[5];
		try {
			for (int i = 0; i <= arr.length; i++)
				arr[i] = 100;
		} catch (ArrayIndexOutOfBoundsException e) {
			System.out.println("배열의 범위를 초과함");
			e.printStackTrace();
		}
	}
}
