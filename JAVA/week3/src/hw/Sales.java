package sec02;

public class Sales {
	int num;
	static int cnt;
	
	Sales(){
		cnt++;
	}
	static int getSale() {
		return cnt;
	}
}
