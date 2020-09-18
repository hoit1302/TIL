package sec01;

public class Score {
	int sum1(int[] values) {
		int sum = 0;
		for (int i = 0; i < values.length; i++)
			sum += values[i];
		return sum;
	}
}

// 참고: 함수 return값이 void 일 때 강제종료 하는 법: return;