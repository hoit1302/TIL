package sec03;

import java.util.*;

public class DynamicArray {
	public static void main(String[] args) {
		List<Song> songs = new ArrayList<Song>();
		songs.add(new Song("��ź", "Zero 0'clock"));
		songs.add(new Song("Ʈ���̽�", "more and more"));
		songs.add(new Song("û��", "play"));
		
		for (Song s: songs)
			System.out.println(s);
	}
}
