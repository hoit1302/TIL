package sec02;

public interface RemoteControl {
//	static final�� �����ص� ��. (�����Ϸ��� ����)
	
	// ��� �ʵ�
	int MAX_VOLUME = 10;
	int MIN_VOLUME = 0;
	
	
//	 �߻� Ŭ���������� �޼��� �տ� abstract�� �ٿ��� �ϳ�
//	interface member�� ��� public abstract�� ����Ʈ
	// �߻� �޼���
	void turnOn();
	void turnOff();
	void setVolume(int volume);
}
