package sec01;

public class StudentTest {
	public static void main(String[] args) {
		Student s1 = new Student("자바신", "111111-1111111", 1971000);
		System.out.println("name:" + s1.name);
		System.out.println("ssn:" + s1.ssn);
		System.out.println("stuNo:" + s1.stuNo);
	}
}
