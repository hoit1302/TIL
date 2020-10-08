package sec02;

public class Television implements RemoteControl {
	private int volume;
	
	@Override
	public void turnOn() {
		System.out.println("TV ���� ON");
	}

	@Override
	public void turnOff() {
		 System.out.println("TV ���� OFF");
	}

	@Override
	public void setVolume(int volume) {
		if (volume > MAX_VOLUME)
			this.volume = MAX_VOLUME;
		else if (volume < MIN_VOLUME)
			this.volume = MIN_VOLUME;
		else
			this.volume = volume;
		System.out.println("���� TV ����:" + this.volume);
	}

}
