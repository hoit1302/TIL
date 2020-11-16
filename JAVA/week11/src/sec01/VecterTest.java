package sec01;
// 정수만을 다루는 Vector<Integer> 제네릭 벡터를 생성하고 활용하는 예제
import java.util.Vector;

public class VecterTest {
	public static void main(String[] args) {
		Vector<Integer> v = new Vector<>();
		// 요소 추가
		v.add(100); // 자동 박싱
		v.add(90);
		// 요소 중간 삽입
		v.add(1, 70);
		System.out.println(v);
		// 모든 요소 합계
		int sum = 0;
		for (int i = 0; i < v.size(); i++)
			sum += v.get(i);
		System.out.println("벡터에 있는 모든 요소의 합: " + sum);
	}
}
