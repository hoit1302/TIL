package sec03;

import java.util.*;

public class DynamicArray {
	public static void main(String[] args) {
		List<Song> songs = new ArrayList<Song>();
		songs.add(new Song("방탄", "Zero 0'clock"));
		songs.add(new Song("트와이스", "more and more"));
		songs.add(new Song("청하", "play"));
		
		for (Song s: songs)
			System.out.println(s);
	}
}
