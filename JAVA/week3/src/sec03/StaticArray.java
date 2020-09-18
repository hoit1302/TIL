package sec03;

import java.util.Scanner;

public class StaticArray {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		Song[] songs = new Song[3];
		for (int i = 0; i < songs.length; i++)
			songs[i] = new Song(in.next(), in.next());
		
		for (Song s: songs)
			System.out.println(s);
		
		in.close();
	}
}
