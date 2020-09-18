package sec03;

public class Song {	
	String singer;
	String title;
	
	public Song(String singer, String title) {
		this.singer = singer;
		this.title = title;
	}

	@Override
	public String toString() {
		return "Song [singer=" + singer + ", title=" + title + "]";
	}
	
}
