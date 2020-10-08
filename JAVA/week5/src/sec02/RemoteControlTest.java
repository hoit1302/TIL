package sec02;

public class RemoteControlTest {
	public static void main(String[] args) {
		Television tv = new Television();
		tv.setVolume(11);
		tv.setVolume(-1);
		tv.setVolume(5);
	}
}

