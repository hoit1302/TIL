package sec02;

public class Array {

	int minArray(int[] score) {
		int min=score[0];
		
		for(int i=1;i<score.length;i++) {
			if(score[i]<min)
				min=score[i];
		}
		return min;
	}
	
	int maxArray(int[] score) {
		int max=score[0];
		
		for(int i=1;i<score.length;i++) {
			if(score[i]>max)
				max=score[i];
		}
		return max;
	}
	
}
