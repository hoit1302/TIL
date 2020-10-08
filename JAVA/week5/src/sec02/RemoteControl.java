package sec02;

public interface RemoteControl {
//	static final을 생략해도 됨. (컴파일러에 의해)
	
	// 상수 필드
	int MAX_VOLUME = 10;
	int MIN_VOLUME = 0;
	
	
//	 추상 클래스에서는 메서드 앞에 abstract을 붙여야 하나
//	interface member는 모두 public abstract이 디폴트
	// 추상 메서드
	void turnOn();
	void turnOff();
	void setVolume(int volume);
}
