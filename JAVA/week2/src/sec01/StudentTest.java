package sec01;

public class StudentTest {

	public static void main(String[] args) {
		Student s1 = new Student();
		s1.setName("������");
		s1.setAge(21);
		s1.show();
		
		Student s2 = new Student("������", 21);
		s2.show();
	}

}
